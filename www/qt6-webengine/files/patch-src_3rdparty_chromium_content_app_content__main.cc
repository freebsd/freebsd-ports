--- src/3rdparty/chromium/content/app/content_main.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/content/app/content_main.cc
@@ -228,7 +228,7 @@ NO_STACK_PROTECTOR int RunContentProcess(
 #endif
     logging::RegisterAbslAbortHook();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
@@ -314,7 +314,7 @@ NO_STACK_PROTECTOR int RunContentProcess(
     command_line->AppendSwitch(switches::kUseMobileUserAgent);
 #endif
 
-#if (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)) && !defined(COMPONENT_BUILD)
+#if (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)) && !defined(COMPONENT_BUILD) && defined(notyet)
     base::subtle::EnableFDOwnershipEnforcement(true);
 #endif
 
