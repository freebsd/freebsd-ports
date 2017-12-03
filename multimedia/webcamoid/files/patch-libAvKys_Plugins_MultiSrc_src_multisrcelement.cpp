--- libAvKys/Plugins/MultiSrc/src/multisrcelement.cpp.orig	2017-10-09 06:45:30 UTC
+++ libAvKys/Plugins/MultiSrc/src/multisrcelement.cpp
@@ -201,9 +201,15 @@ void MultiSrcElement::codecLibUpdated(co
     auto state = this->state();
     this->setState(AkElement::ElementStateNull);
 
-    auto media = this->m_mediaSource->media();
-    auto loop = this->m_mediaSource->loop();
-    auto showLog = this->m_mediaSource->showLog();
+    // crashes with these lines: https://github.com/webcamoid/webcamoid/issues/100
+    // auto media = this->m_mediaSource->media();
+    // auto loop = this->m_mediaSource->loop();
+    // auto showLog = this->m_mediaSource->showLog();
+
+    // workaround for the crash
+    QString media;
+    bool loop = true;
+    bool showLog = true;
 
     this->m_mutexLib.lock();
 
