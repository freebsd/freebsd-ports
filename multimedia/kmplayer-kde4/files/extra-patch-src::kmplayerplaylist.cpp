--- src/kmplayerplaylist.cpp.orig	Sat Nov 13 16:01:42 2004
+++ src/kmplayerplaylist.cpp	Sat Nov 13 16:02:02 2004
@@ -293,7 +293,7 @@
         else
             kdError () << "Warning: unhandled MediaType attr: " << attr << "=" << atts.value (i) << endl;
     }
-    kdDebug () << "MediaType attr found bitrate: " << bitrate << " src: " << (src.isEmpty() ? "-" : src) << " type: " << (mimetype.isEmpty() ? "-" : mimetype) << endl;
+    kdDebug () << "MediaType attr found bitrate: " << bitrate << " src: " << (src.isEmpty() ? "-" : (const char *) src) << " type: " << (mimetype.isEmpty() ? "-" : (const char *) mimetype) << endl;
 }
 
 //-----------------------------------------------------------------------------
