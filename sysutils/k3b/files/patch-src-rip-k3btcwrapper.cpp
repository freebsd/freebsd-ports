--- src/rip/k3btcwrapper.cpp.orig	Thu Jun 12 16:07:42 2003
+++ src/rip/k3btcwrapper.cpp	Fri Nov  7 12:35:44 2003
@@ -27,7 +27,7 @@
 //#include <kprocess.h>
 #include <klocale.h>
 #include <kdebug.h>
-
+#include <stdlib.h>
 
 K3bTcWrapper::K3bTcWrapper( QObject* parent )
   : QObject( parent )
@@ -65,7 +65,14 @@
   //K3bProcess *p = new K3bProcess();
   emit tcprobeTitleParsed( m_currentTitle );
 
+#ifndef __FreeBSD__
   *p << bin->path << "-i" <<  m_device->ioctlDevice() << "-T" << QString::number(m_currentTitle);
+#else
+    QString s = "mount " + m_device->mountPoint();
+    system(s.latin1());
+    kdDebug() << "(K3bDirView) executing: " << bin->path << " -i " <<  m_device->mountPoint() << " -T " << QString::number(m_currentTitle) << endl;
+  *p << bin->path << "-i" <<  m_device->mountPoint() << "-T" << QString::number(m_currentTitle);
+#endif
   //p->setSplitStdout( true );
   connect( p, SIGNAL(receivedStderr(KProcess*, char*, int)), this, SLOT(slotParseTcprobeError(KProcess*, char*, int)) );
   connect( p, SIGNAL(receivedStdout(KProcess*, char*, int)), this, SLOT(slotParseTcprobeOutput(KProcess*, char*, int)) );
@@ -115,7 +122,7 @@
         // check dvd
         for( QStringList::Iterator str = errorLines.begin(); str != errorLines.end(); str++ ) {
             kdDebug() << (*str) << endl;
-            if( !(*str).contains("tcprobe") && !(*str).contains("DVD image/device") ) {
+            if( !(*str).contains("tcprobe") || !(*str).contains("DVD image/device") ) {
                 continue;
             } else{
                 isDvd = true;
