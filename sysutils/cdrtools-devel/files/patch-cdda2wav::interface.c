--- cdda2wav/interface.c	Mon Dec 29 11:28:09 2003
+++ cdda2wav/interface.c	Sun Jan 18 01:35:50 2004
@@ -452,6 +452,10 @@
     default:			/* for example ATAPI cds */
 #else
 #if defined (__FreeBSD__) || defined(__DragonFly__)
+#if __FreeBSD_version >= 600021
+    case 0:	/* majors abandoned */
+	/* FALLTHROUGH */
+#endif
 #if __FreeBSD_version >= 501113
     case 4:	/* GEOM */
 	/* FALLTHROUGH */
