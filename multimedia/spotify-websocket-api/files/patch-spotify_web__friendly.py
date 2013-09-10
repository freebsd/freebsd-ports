--- ./spotify_web/friendly.py.orig	2013-08-08 08:45:21.000000000 +0200
+++ ./spotify_web/friendly.py	2013-09-10 22:11:07.000000000 +0200
@@ -244,6 +244,8 @@
         uri_parts = self.uri.split(":")
         if len(uri_parts) == 4:
             return uri_parts[3]
+        elif len(uri_parts) == 3:
+            return None
         else:
             return uri_parts[4]
 
@@ -251,7 +253,7 @@
         return self.uri
 
     def getName(self):
-        return "Starred" if self.getID() == "starred" else self.obj.attributes.name
+        return "Starred" if self.getID() == "starred" else (None if self.obj == False else self.obj.attributes.name)
 
     def rename(self, name):
         ret = self.spotify.api.rename_playlist(self.getURI(), name)
