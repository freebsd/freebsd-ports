diff --git a/proto/ospf/hello.c b/proto/ospf/hello.c
index d5aa1b9..58e87bb 100644
--- proto/ospf/hello.c
+++ proto/ospf/hello.c
@@ -101,6 +101,17 @@ ospf_hello_receive(struct ospf_packet *ps_i, struct ospf_iface *ifa,
     return;
   }
 
+#ifdef OSPFv2
+  if (n && (n->rid != ntohl(ps_i->routerid)))
+  {
+    OSPF_TRACE(D_EVENTS,
+	"Neighbor %I has changed router id from %R to %R.",
+	     n->ip, n->rid, ntohl(ps_i->routerid));
+    ospf_neigh_remove(n);
+    n = NULL;
+  }
+#endif
+
   if (!n)
   {
     if ((ifa->type == OSPF_IT_NBMA) || (ifa->type == OSPF_IT_PTMP))
@@ -132,7 +143,7 @@ ospf_hello_receive(struct ospf_packet *ps_i, struct ospf_iface *ifa,
 
     n = ospf_neighbor_new(ifa);
 
-    n->rid = ntohl(((struct ospf_packet *) ps)->routerid);
+    n->rid = ntohl(ps_i->routerid);
     n->ip = faddr;
     n->dr = ntohl(ps->dr);
     n->bdr = ntohl(ps->bdr);
