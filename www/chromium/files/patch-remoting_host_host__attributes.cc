--- remoting/host/host_attributes.cc.orig	2022-02-28 16:54:41 UTC
+++ remoting/host/host_attributes.cc
@@ -122,7 +122,7 @@ std::string GetHostAttributes() {
       media::InitializeMediaFoundation()) {
     result.push_back("HWEncoder");
   }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   result.push_back("HWEncoder");
 #endif
 
