--- src/rip/k3baudioprojectconvertingthread.cpp.orig	Sun Jul 10 00:18:23 2005
+++ src/rip/k3baudioprojectconvertingthread.cpp	Sun Jul 10 00:18:50 2005
@@ -373,7 +373,7 @@
 
   // we always use a relative filename here
   QString imageFile = m_tracks[0].second.section( '/', -1 );
-  cueWriter.setImage( imageFile, ( d->fileType.isEmpty() ? "WAVE" : d->fileType ) );
+  cueWriter.setImage( imageFile, ( d->fileType.isEmpty() ? QString("WAVE") : d->fileType ) );
 
   // use the same base name as the image file
   QString cueFile = m_tracks[0].second;
