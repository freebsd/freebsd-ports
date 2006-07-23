--- akode_artsplugin/akodePlayObject_impl.cpp.orig	Fri Jul 21 22:10:02 2006
+++ akode_artsplugin/akodePlayObject_impl.cpp	Fri Jul 21 22:13:13 2006
@@ -82,6 +82,8 @@
 
 akodePlayObject_impl::~akodePlayObject_impl()
 {
+    delete m_packetQueue;
+
     unload();
 }
 
@@ -219,10 +221,9 @@
         delete bufferedDecoder;
         bufferedDecoder = 0;
     }
-#else
-    delete frameDecoder
-    frameDecoder = 0;
 #endif
+    delete frameDecoder;
+    frameDecoder = 0;
     decoder = 0;
     if (buffer != inBuffer)
         delete inBuffer;
@@ -301,7 +302,7 @@
 {
     arts_debug("akode: readFrame");
 
-    if (!buffer || !decoder) return false;
+    if (!inBuffer || !decoder) return false;
     if (m_bytebuffer) processQueue();
     if(!decoder->readFrame(inBuffer)) {
         if (decoder->eof()) {