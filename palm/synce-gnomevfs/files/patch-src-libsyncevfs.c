--- src/libsyncevfs.c.orig	Sun Aug 22 21:06:29 2004
+++ src/libsyncevfs.c	Sat Jan  8 18:40:37 2005
@@ -126,8 +126,9 @@
 {
   if (!initialized_rapi)
   {
+    HRESULT hr;
     MUTEX_LOCK (mutex); 
-    HRESULT hr = CeRapiInit();
+    hr = CeRapiInit();
     MUTEX_UNLOCK (mutex); 
 
     if (FAILED(hr))
@@ -145,9 +146,10 @@
 
 static int get_location(GnomeVFSURI *uri, gchar **location)/*{{{*/
 {
-  int result = INDEX_INVALID;
-  *location = NULL;
+  int result;
   gchar **path = NULL;
+  *location = NULL;
+  result = INDEX_INVALID;
 
   path = g_strsplit(gnome_vfs_unescape_string(gnome_vfs_uri_get_path(uri),"\\"), "/", 0);
 
