--- zebra/connected.h.orig	2018-03-12 00:53:37 UTC
+++ zebra/connected.h
@@ -42,10 +42,11 @@ extern void connected_up(struct interface *ifp, struct
 extern void connected_down(struct interface *ifp, struct connected *ifc);
 
 extern void connected_add_ipv6(struct interface *ifp, int flags,
-			       struct in6_addr *address, u_char prefixlen,
-			       const char *label);
+			       struct in6_addr *address, struct in6_addr *broad,
+			       uint8_t prefixlen, const char *label);
 extern void connected_delete_ipv6(struct interface *ifp,
-				  struct in6_addr *address, u_char prefixlen);
+				  struct in6_addr *address,
+				  struct in6_addr *broad, uint8_t prefixlen);
 
 extern int connected_is_unnumbered(struct interface *);
 
