--- remoting/host/base/switches.cc.orig	2022-02-28 16:54:41 UTC
+++ remoting/host/base/switches.cc
@@ -23,7 +23,7 @@ const char kProcessTypeEvaluateCapability[] = "evaluat
 const char kProcessTypeFileChooser[] = "file_chooser";
 const char kProcessTypeUrlForwarderConfigurator[] =
     "url_forwarder_configurator";
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kProcessTypeXSessionChooser[] = "xsession_chooser";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
