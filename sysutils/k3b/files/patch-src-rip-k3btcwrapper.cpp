--- src/rip/k3btcwrapper.cpp.orig	Wed Jan 21 11:20:20 2004
+++ src/rip/k3btcwrapper.cpp	Fri Feb 13 21:03:38 2004
@@ -65,7 +65,12 @@
   //K3bProcess *p = new K3bProcess();
   emit tcprobeTitleParsed( m_currentTitle );
 
+#ifndef __FreeBSD__
   *p << bin->path << "-i" <<  m_device->blockDeviceName() << "-T" << QString::number(m_currentTitle);
+#else
+    kdDebug() << "(K3bTcWrapper) executing: " << bin->path << " -i " <<  m_device->mountPoint() << " -T " << QString::number(m_currentTitle) << endl;
+  *p << bin->path << "-i" <<  m_device->mountPoint() << "-T" << QString::number(m_currentTitle);
+#endif
   //p->setSplitStdout( true );
   connect( p, SIGNAL(receivedStderr(KProcess*, char*, int)), this, SLOT(slotParseTcprobeError(KProcess*, char*, int)) );
   connect( p, SIGNAL(receivedStdout(KProcess*, char*, int)), this, SLOT(slotParseTcprobeOutput(KProcess*, char*, int)) );
