--- src/rip/k3baudioripthread.cpp.orig	Sun Jul 10 00:14:21 2005
+++ src/rip/k3baudioripthread.cpp	Sun Jul 10 00:15:00 2005
@@ -536,7 +536,7 @@
 
   // we always use a relative filename here
   QString imageFile = m_tracks[0].second.section( '/', -1 );
-  cueWriter.setImage( imageFile, ( d->fileType.isEmpty() ? "WAVE" : d->fileType ) );
+  cueWriter.setImage( imageFile, ( d->fileType.isEmpty() ? QString("WAVE") : d->fileType ) );
 
   // use the same base name as the image file
   QString cueFile = m_tracks[0].second;
