--- pf/pf_ioctl.c.orig	Wed Jan 28 20:45:50 2004
+++ pf/pf_ioctl.c	Tue Feb 24 15:53:56 2004
@@ -222,6 +222,9 @@
 	.d_ioctl =	pfioctl,
 	.d_name =	PF_NAME,
 	.d_flags =	0,
+#if __FreeBSD_version >= 502103
+	.d_version =	D_VERSION,
+#endif
 #endif
 };
 #endif /* __FreeBSD__ */
