--- remoting/host/host_attributes.cc.orig	2019-01-09 13:07:49.513766000 +0100
+++ remoting/host/host_attributes.cc	2019-01-09 13:08:03.536029000 +0100
@@ -123,7 +123,7 @@
       media::InitializeMediaFoundation()) {
     result.push_back("HWEncoder");
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   result.push_back("HWEncoder");
 #endif
 
