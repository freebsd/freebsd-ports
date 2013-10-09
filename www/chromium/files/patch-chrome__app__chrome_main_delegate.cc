--- chrome/app/chrome_main_delegate.cc.orig	2013-09-20 05:35:27.000000000 +0300
+++ chrome/app/chrome_main_delegate.cc	2013-09-25 21:42:44.000000000 +0300
@@ -92,7 +92,7 @@
 #include "ui/base/x/x11_util.h"
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "chrome/app/breakpad_linux.h"
 #endif
 
@@ -110,7 +110,7 @@
     g_chrome_content_plugin_client = LAZY_INSTANCE_INITIALIZER;
 #endif
 
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
 base::LazyInstance<chrome::ChromeBreakpadClient>::Leaky
     g_chrome_breakpad_client = LAZY_INSTANCE_INITIALIZER;
 #endif
@@ -230,7 +230,7 @@
       // Mac needs them for the plugin process name.
       process_type == switches::kPluginProcess ||
 #endif
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
       // The zygote process opens the resources for the renderers.
       process_type == switches::kZygoteProcess ||
 #endif
@@ -573,7 +573,7 @@
   std::string process_type =
       command_line.GetSwitchValueASCII(switches::kProcessType);
 
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
   breakpad::SetBreakpadClient(g_chrome_breakpad_client.Pointer());
 #endif
 
@@ -699,7 +699,7 @@
 #endif
   }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   // Needs to be called after we have chrome::DIR_USER_DATA.  BrowserMain
   // sets this up for the browser process in a different manner. Zygotes
   // need to call InitCrashReporter() in RunZygote().
@@ -811,7 +811,7 @@
     SetUpProfilingShutdownHandler();
   }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   // Needs to be called after we have chrome::DIR_USER_DATA.  BrowserMain sets
   // this up for the browser process in a different manner.
   InitCrashReporter();
