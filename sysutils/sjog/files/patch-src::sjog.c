--- src/sjog.c.orig	Mon Aug 13 20:52:02 2001
+++ src/sjog.c	Sat Aug 17 20:38:56 2002
@@ -10,7 +10,11 @@
 /* -------------------------------------------------------------------------- */
 
 gboolean reverseBrightness = TRUE;
+#ifdef __FreeBSD__
+gboolean useSpic = TRUE;
+#else 
 gboolean useSpic = FALSE;
+#endif
 gboolean mousewheelFakeKeys = FALSE;
 gboolean centerWindow = TRUE;
 
