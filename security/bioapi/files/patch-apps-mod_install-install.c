--- apps/mod_install/install.c	Wed Jun  8 02:51:04 2005
+++ apps/mod_install/install.c	Tue Mar 28 08:59:05 2006
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
@@ -496,10 +501,6 @@
 							}
 							else if ( Action == INSTALL_ACTION_UNINSTALL )
 							{
-/* Linux-Port: Added the Linux branch */
-#if defined (LINUX) || defined (SOLARIS)
-								DeleteFile(szDstPath);
-#endif
 								printf( "Module uninstalled successfully.\n" );
 							}
 							else if ( Action == INSTALL_ACTION_REFRESH )
