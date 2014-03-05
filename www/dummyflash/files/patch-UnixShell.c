--- PluginSDK30b5/examples/UnixTemplate/Source/UnixShell.c.orig	1996-07-12 15:10:28.000000000 +0930
+++ PluginSDK30b5/examples/UnixTemplate/Source/UnixShell.c	2013-10-09 07:24:13.570473153 +1030
@@ -48,7 +48,7 @@
 char*
 NPP_GetMIMEDescription(void)
 {
-	return("mime/type:sample:Template Only");
+	return("application/x-shockwave-flash:null flash:Dummy flash plugin");
 }
 
 NPError
@@ -58,12 +58,11 @@
 
 	switch (variable) {
 		case NPPVpluginNameString:
-			*((char **)value) = "Template plugin";
+			*((char **)value) = "Dummy flash plugin";
 			break;
 		case NPPVpluginDescriptionString:
 			*((char **)value) =
-				"This plugins handles nothing. This is only"
-				" a template.";
+				"This is a dummy flash plugin";
 			break;
 		default:
 			err = NPERR_GENERIC_ERROR;
