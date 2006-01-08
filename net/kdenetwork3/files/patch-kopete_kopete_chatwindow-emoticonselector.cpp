--- kopete/kopete/chatwindow/emoticonselector.cpp.orig	Mon Dec 19 14:52:02 2005
+++ kopete/kopete/chatwindow/emoticonselector.cpp	Mon Dec 19 15:06:05 2005
@@ -47,7 +47,7 @@
     // Some of the custom icons are rather large
     // so lets limit them to a maximum size for this display panel
     //
-    if (p.width() > 32 or p.height() > 32)
+    if (p.width() > 32 || p.height() > 32)
         p.resize(32, 32);
 	setMinimumSize(p.size());
 }
