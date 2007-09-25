Index: ospfd/ospf_spf.c
===================================================================
RCS file: /cvsroot/zebra/ospfd/ospf_spf.c,v
retrieving revision 1.124
diff -u -r1.124 ospf_spf.c
--- ospfd/ospf_spf.c	28 Mar 2003 19:55:28 -0000	1.124
+++ ospfd/ospf_spf.c	22 Feb 2006 03:03:26 -0000
@@ -29,6 +29,7 @@
 #include "table.h"
 #include "log.h"
 #include "sockunion.h"          /* for inet_ntop () */
+#include "pqueue.h"
 
 #include "ospfd/ospfd.h"
 #include "ospfd/ospf_interface.h"
@@ -114,7 +115,7 @@
 }
 
 void
-ospf_vertex_add_parent (struct vertex *v)
+ospf_vertex_connect_to_parent (struct vertex *v)
 {
   struct vertex_nexthop *nh;
   listnode node;
@@ -458,48 +459,36 @@
     }
 }
 
-void
-ospf_install_candidate (list candidate, struct vertex *w)
+int
+ospf_vertex_cmp (void *a, void *b)
 {
-  listnode node;
-  struct vertex *cw;
-
-  if (list_isempty (candidate))
-    {
-      listnode_add (candidate, w);
-      return;
-    }
+  struct vertex *va = (struct vertex *) a;
+  struct vertex *vb = (struct vertex *) b;
+  /* ascending order */
+  return (va->distance - vb->distance);
+}
 
-  /* Install vertex with sorting by distance. */
-  for (node = listhead (candidate); node; nextnode (node))
-    {
-      cw = (struct vertex *) getdata (node);
-      if (cw->distance > w->distance)
-        {
-          list_add_node_prev (candidate, node, w);
-          break;
-        }
-      else if (node->next == NULL)
-        {
-          list_add_node_next (candidate, node, w);
-          break;
-        }
-    }
+void
+ospf_install_candidate (struct pqueue *candidate_list, struct vertex *w)
+{
+  if (IS_DEBUG_OSPF_EVENT)
+    zlog_info ("candidate: type: %d id: %s p: %p distance: %lu",
+               w->type, inet_ntoa (w->id), w, (u_long)w->distance);
+  pqueue_enqueue (w, candidate_list);
 }
 
 /* RFC2328 Section 16.1 (2). */
 void
 ospf_spf_next (struct vertex *v, struct ospf_area *area,
-               list candidate, struct route_table *rv,
+               struct pqueue *candidate_list, struct route_table *rv,
                struct route_table *nv)
 {
   struct ospf_lsa *w_lsa = NULL;
-  struct vertex *w, *cw;
+  struct vertex *w;
   u_char *p;
   u_char *lim;
   struct router_lsa_link *l = NULL;
   struct in_addr *r;
-  listnode node;
   int type = 0;
 
   /* If this is a router-LSA, and bit V of the router-LSA (see Section
@@ -618,58 +607,22 @@
       else
         w->distance = v->distance;
 
-      /* Is there already vertex W in candidate list? */
-      node = ospf_vertex_lookup (candidate, w->id, w->type);
-      if (node == NULL)
-        {
-          /* Calculate nexthop to W. */
-          ospf_nexthop_calculation (area, v, w);
-
-          ospf_install_candidate (candidate, w);
-        }
-      else
-        {
-          cw = (struct vertex *) getdata (node);
-
-          /* if D is greater than. */
-          if (cw->distance < w->distance)
-            {
-              ospf_vertex_free (w);
-              continue;
-            }
-          /* equal to. */
-          else if (cw->distance == w->distance)
-            {
-              /* Calculate nexthop to W. */
-              ospf_nexthop_calculation (area, v, w);
-              ospf_nexthop_merge (cw->nexthop, w->nexthop);
-              list_delete_all_node (w->nexthop);
-              ospf_vertex_free (w);
-            }
-          /* less than. */
-          else
-            {
-              /* Calculate nexthop. */
-              ospf_nexthop_calculation (area, v, w);
-
-              /* Remove old vertex from candidate list. */
-              ospf_vertex_free (cw);
-              listnode_delete (candidate, cw);
+      /* calculate nexthop */
+      ospf_nexthop_calculation (area, v, w);
 
-              /* Install new to candidate. */
-              ospf_install_candidate (candidate, w);
-            }
-        }
+      /* install candidate */
+      ospf_install_candidate (candidate_list, w);
     }
 }
 
 /* Add vertex V to SPF tree. */
-void
+struct vertex *
 ospf_spf_register (struct vertex *v, struct route_table *rv,
 		   struct route_table *nv)
 {
   struct prefix p;
   struct route_node *rn;
+  struct vertex *cv;
 
   p.family = AF_INET;
   p.prefixlen = IPV4_MAX_BITLEN;
@@ -680,7 +633,39 @@
   else
     rn = route_node_get (nv, &p);
 
-  rn->info = v;
+  cv = rn->info;
+
+  /* if the route does not exist yet, just install and return */
+  if (! cv)
+    {
+      rn->info = v;
+      return v;
+    }
+
+  /* if D is greater than. */
+  if (cv->distance < v->distance)
+    ospf_vertex_free (v);
+
+  /* equal to. */
+  else if (cv->distance == v->distance)
+    {
+      /* Merge nexthop to D. */
+      ospf_nexthop_merge (cv->nexthop, v->nexthop);
+      list_delete_all_node (v->nexthop);
+      ospf_vertex_free (v);
+    }
+
+  /* less than. */
+  else
+    {
+      /* As long as sorting in the candidate_list works,
+      cv->distance never become more than v->distance
+      (i.e. (cv->distance > v->distance) should not happen). */
+      assert (0);
+    }
+
+  /* the vertex is dropped anyway */
+  return NULL;
 }
 
 void
@@ -709,6 +694,7 @@
   listnode cnode;
   listnode nnode;
   struct vertex_nexthop *nexthop;
+  struct vertex *w;
 
   if (v->type == OSPF_VERTEX_ROUTER)
     {
@@ -734,8 +720,8 @@
 
   for (cnode = listhead (v->child); cnode; nextnode (cnode))
     {
-      v = getdata (cnode);
-      ospf_spf_dump (v, i);
+      w = getdata (cnode);
+      ospf_spf_dump (w, i);
     }
 }
 
@@ -895,8 +881,7 @@
 ospf_spf_calculate (struct ospf_area *area, struct route_table *new_table, 
                     struct route_table *new_rtrs)
 {
-  list candidate;
-  listnode node;
+  struct pqueue *candidate_list;
   struct vertex *v;
   struct route_table *rv;
   struct route_table *nv;
@@ -925,7 +910,8 @@
   nv = route_table_init ();
 
   /* Clear the list of candidate vertices. */ 
-  candidate = list_new ();
+  candidate_list = pqueue_create ();
+  candidate_list->cmp = ospf_vertex_cmp;
 
   /* Initialize the shortest-path tree to only the root (which is the
      router doing the calculation). */
@@ -939,29 +925,37 @@
 
   for (;;)
     {
-      /* RFC2328 16.1. (2). */
-      ospf_spf_next (v, area, candidate, rv, nv);
+      if (v != NULL)
+        {
+          if (IS_DEBUG_OSPF_EVENT)
+            zlog_info ("determined: type: %d id: %s p: %p distance: %lu",
+                       v->type, inet_ntoa (v->id), v, (u_long)v->distance);
+
+          /* RFC2328 16.1. (2). */
+          ospf_spf_next (v, area, candidate_list, rv, nv);
+        }
 
       /* RFC2328 16.1. (3). */
       /* If at this step the candidate list is empty, the shortest-
          path tree (of transit vertices) has been completely built and
          this stage of the procedure terminates. */
-      if (listcount (candidate) == 0)
+      if (candidate_list->size == 0)
         break;
 
       /* Otherwise, choose the vertex belonging to the candidate list
          that is closest to the root, and add it to the shortest-path
          tree (removing it from the candidate list in the
          process). */ 
-      node = listhead (candidate);
-      v = getdata (node);
-      ospf_vertex_add_parent (v);
-
-      /* Reveve from the candidate list. */
-      listnode_delete (candidate, v);
+      v = pqueue_dequeue (candidate_list);
 
       /* Add to SPF tree. */
-      ospf_spf_register (v, rv, nv);
+      v = ospf_spf_register (v, rv, nv);
+
+      /* Skip rest if the vertex is rejected to be installed in SPF tree */
+      if (v == NULL)
+        continue;
+
+      ospf_vertex_connect_to_parent (v);
 
       /* Note that when there is a choice of vertices closest to the
          root, network vertices must be chosen before router vertices
@@ -993,7 +987,7 @@
   ospf_spf_route_free (nv);
 
   /* Free candidate list */
-  list_free (candidate);
+  pqueue_delete (candidate_list);
 
   /* Increment SPF Calculation Counter. */
   area->spf_calculation++;
