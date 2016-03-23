--- src/procenv.c.orig	2014-08-16 19:06:54 UTC
+++ src/procenv.c
@@ -5361,8 +5361,13 @@ show_capabilities_bsd (int fd)
 	show_capsicum_cap (rights, CAP_KQUEUE);
 	show_capsicum_cap (rights, CAP_KQUEUE_CHANGE);
 	show_capsicum_cap (rights, CAP_KQUEUE_EVENT);
+#if __FreeBSD__ > 10
+	show_capsicum_cap (rights, CAP_LINKAT_TARGET);
+	show_capsicum_cap (rights, CAP_LINKAT_SOURCE);
+#else
 	show_capsicum_cap (rights, CAP_LINKAT);
 #endif
+#endif
 	show_capsicum_cap (rights, CAP_LISTEN);
 	show_capsicum_cap (rights, CAP_LOOKUP);
 	show_capsicum_cap (rights, CAP_MAC_GET);
@@ -5392,8 +5397,13 @@ show_capabilities_bsd (int fd)
 	show_capsicum_cap (rights, CAP_READ);
 #if __FreeBSD__ > 9
 	show_capsicum_cap (rights, CAP_RECV);
+#if __FreeBSD__ > 10
+	show_capsicum_cap (rights, CAP_RENAMEAT_TARGET);
+	show_capsicum_cap (rights, CAP_RENAMEAT_SOURCE);
+#else
 	show_capsicum_cap (rights, CAP_RENAMEAT);
 #endif
+#endif
 	show_capsicum_cap (rights, CAP_SEEK);
 #if __FreeBSD__ > 9
 	show_capsicum_cap (rights, CAP_SEEK_TELL);
