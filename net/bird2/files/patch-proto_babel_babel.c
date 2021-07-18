--- proto/babel/babel.c.orig	2021-04-16 21:18:15 UTC
+++ proto/babel/babel.c
@@ -1658,10 +1658,6 @@ babel_if_notify(struct proto *P, unsigned flags, struc
     if (!(iface->flags & IF_UP))
       return;
 
-    /* We only speak multicast */
-    if (!(iface->flags & IF_MULTICAST))
-      return;
-
     /* Ignore ifaces without link-local address */
     if (!iface->llv6)
       return;
@@ -1734,10 +1730,6 @@ babel_reconfigure_ifaces(struct babel_proto *p, struct
   WALK_LIST(iface, iface_list)
   {
     if (!(iface->flags & IF_UP))
-      continue;
-
-    /* Ignore non-multicast ifaces */
-    if (!(iface->flags & IF_MULTICAST))
       continue;
 
     /* Ignore ifaces without link-local address */
