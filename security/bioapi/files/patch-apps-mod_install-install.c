--- apps/mod_install/install.c	Wed Jun  8 02:51:04 2005
+++ apps/mod_install/install.c	Fri Nov 25 18:08:54 2005
@@ -370,8 +370,13 @@
 #if defined (LINUX) || defined (SOLARIS)
   if ( ( Action == INSTALL_ACTION_INSTALL ) || ( Action == INSTALL_ACTION_REFRESH ) )
   {
-    strcat(szSrcPath, ModuleName);
-    Src = szSrcPath;
+	if (strchr(ModuleName, '/') == NULL) {
+    	strcat(szSrcPath, ModuleName);
+    	Src = szSrcPath;
+	}
+	else {
+		Src = ModuleName;
+	}
   }
   if ( Action == INSTALL_ACTION_UNINSTALL )
   {
