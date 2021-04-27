--- remoting/host/host_attributes.cc.orig	2021-04-14 18:41:08 UTC
+++ remoting/host/host_attributes.cc
@@ -120,7 +120,7 @@ std::string GetHostAttributes() {
       media::InitializeMediaFoundation()) {
     result.push_back("HWEncoder");
   }
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   result.push_back("HWEncoder");
 #endif
 
