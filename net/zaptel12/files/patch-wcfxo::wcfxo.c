
$FreeBSD$

--- wcfxo/wcfxo.c
+++ wcfxo/wcfxo.c
@@ -267,8 +267,14 @@
 
 /* Character device entry points */
 static struct cdevsw wcfxo_cdevsw = {
-#if __FreeBSD_version >= 502103
-	.d_version = D_VERSION,
+#if __FreeBSD_version < 502103
+#ifdef MAJOR_AUTO
+	.d_maj = MAJOR_AUTO,
+#else
+	.d_maj = 197,
+#endif
+#else
+	.d_version = D_VERSION, 
 #endif
 	.d_name =   "wcfxo",
 	.d_open  =   wcfxo_sys_open,
