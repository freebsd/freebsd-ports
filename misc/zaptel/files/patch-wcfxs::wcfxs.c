
$FreeBSD$

--- wcfxs/wcfxs.c
+++ wcfxs/wcfxs.c
@@ -308,7 +308,13 @@
 
 /* Character device entry points */
 static struct cdevsw wcfxs_cdevsw = {
-#if __FreeBSD_version >= 502103
+#if __FreeBSD_version < 502103
+#ifdef MAJOR_AUTO
+	.d_maj = MAJOR_AUTO,
+#else
+	.d_maj = 198,
+#endif
+#else
 	.d_version = D_VERSION,
 #endif
 	.d_name  =   "wcfxs",
