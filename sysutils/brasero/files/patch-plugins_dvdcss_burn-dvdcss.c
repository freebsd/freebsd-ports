https://bugzilla.gnome.org/show_bug.cgi?id=744916

--- plugins/dvdcss/burn-dvdcss.c.orig	2015-08-08 18:33:01.297835000 +0200
+++ plugins/dvdcss/burn-dvdcss.c	2015-08-08 18:33:13.493460000 +0200
@@ -95,9 +95,6 @@ brasero_dvdcss_library_init (BraseroPlug
 	if (!module)
 		goto error_doesnt_exist;
 
-	if (!g_module_symbol (module, "dvdcss_interface_2", &address))
-		goto error_version;
-
 	if (!g_module_symbol (module, "dvdcss_open", &address))
 		goto error_version;
 	dvdcss_open = address;
