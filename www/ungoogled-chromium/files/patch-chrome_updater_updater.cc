--- chrome/updater/updater.cc.orig	2023-01-13 08:56:02 UTC
+++ chrome/updater/updater.cc
@@ -44,7 +44,7 @@
 #include "chrome/updater/win/win_util.h"
 #elif BUILDFLAG(IS_MAC)
 #include "chrome/updater/app/server/mac/server.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/updater/app/server/linux/server.h"
 #include "chrome/updater/linux/ipc_support.h"
 #endif
@@ -137,7 +137,7 @@ int HandleUpdaterCommands(UpdaterScope updater_scope,
     CHECK(false) << "--crash-me was used.";
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // As long as this object is alive, all Mojo API surface relevant to IPC
   // connections is usable, and message pipes which span a process boundary will
   // continue to function.
