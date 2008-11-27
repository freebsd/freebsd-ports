--- ospfd/ospfd.h.orig	2008-02-07 18:57:03.000000000 +0300
+++ ospfd/ospfd.h	2008-02-07 18:56:54.000000000 +0300
@@ -320,6 +320,10 @@
 TAILQ_HEAD(lsa_head, lsa_entry);
 TAILQ_HEAD(auth_md_head, auth_md);
 
+#if defined(__FreeBSD__) /* FreeBSD has no LINK_STATE_IS_UP macro. */
+#define LINK_STATE_IS_UP(_s)	((_s) >= LINK_STATE_UP)
+#endif /* defined(__FreeBSD__) */
+
 struct iface {
 	LIST_ENTRY(iface)	 entry;
 	struct event		 hello_timer;
