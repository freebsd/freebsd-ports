
$FreeBSD$

--- zaptel/zaptel.c
+++ zaptel/zaptel.c
@@ -156,12 +156,17 @@
 #endif
 
 static struct cdevsw zt_devsw = {
-#if __FreeBSD_version >= 502103
+#if __FreeBSD_version < 502103
+#ifdef MAJOR_AUTO
+		.d_maj = MAJOR_AUTO,
+#else
+		.d_maj = ZT_MAJOR,
+#endif
+#else
 		.d_version = D_VERSION,
 #endif
 		.d_open			= ztopen,
-		.d_name			= "zaptel",
-		.d_maj			= ZT_MAJOR
+		.d_name			= "zaptel"
 };
 
 
