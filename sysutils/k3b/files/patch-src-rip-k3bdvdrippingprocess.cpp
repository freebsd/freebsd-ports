--- src/rip/k3bdvdrippingprocess.cpp.orig	Wed Jan 21 11:20:20 2004
+++ src/rip/k3bdvdrippingprocess.cpp	Tue May 11 22:57:03 2004
@@ -278,10 +278,13 @@
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
