--- src/rip/k3bdvdrippingprocess.cpp.orig	Wed Jun  2 11:31:41 2004
+++ src/rip/k3bdvdrippingprocess.cpp	Sun Jan  2 09:30:08 2005
@@ -285,10 +285,13 @@
 void K3bDvdRippingProcess::slotPreProcessingDvd() {
     QString video;
     QDir video_ts( m_mountPoint + "/VIDEO_TS");
+#ifndef FreeBSD
+// on FreeBSD both /VIDEO_TS and /video_ts exist on dvd devices ?!?
     if( video_ts.exists() ) {
         m_udfMount = true;
         kdDebug() << "(K3bDvdRippingProcess) <" << m_mountPoint << "> has UDF filesystem." << endl;
     }
+#endif
     video_ts.setPath( m_mountPoint + "/video_ts");
     if( !video_ts.exists() && !m_udfMount){
         m_preProcessingFailed = true;
