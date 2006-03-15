--- uriloader/exthandler/unix/nsGNOMERegistry.cpp.orig	Fri Dec 24 04:30:00 2004
+++ uriloader/exthandler/unix/nsGNOMERegistry.cpp	Fri Dec 24 04:34:05 2004
@@ -143,7 +143,7 @@
     PR_END_MACRO
 
   // Attempt to open libgconf
-  gconfLib = LoadVersionedLibrary("gconf-2", ".4");
+  gconfLib = PR_LoadLibrary("libgconf-2.so");
   ENSURE_LIB(gconfLib);
 
   GET_LIB_FUNCTION(gconf, gconf_client_get_default);
@@ -151,7 +151,7 @@
   GET_LIB_FUNCTION(gconf, gconf_client_get_bool);
 
   // Attempt to open libgnome
-  gnomeLib = LoadVersionedLibrary("gnome-2", ".0");
+  gnomeLib = PR_LoadLibrary("libgnome-2.so");
   ENSURE_LIB(gnomeLib);
 
   GET_LIB_FUNCTION(gnome, gnome_url_show);
@@ -160,7 +160,7 @@
   GET_LIB_FUNCTION(gnome, gnome_program_get);
 
   // Attempt to open libgnomevfs
-  vfsLib = LoadVersionedLibrary("gnomevfs-2", ".0");
+  vfsLib = PR_LoadLibrary("libgnomevfs-2.so");
   ENSURE_LIB(vfsLib);
 
   GET_LIB_FUNCTION(vfs, gnome_vfs_mime_type_from_name);
