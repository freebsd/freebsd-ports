--- remoting/base/crash/crashpad_database_manager.cc.orig	2026-06-05 13:45:06 UTC
+++ remoting/base/crash/crashpad_database_manager.cc
@@ -24,7 +24,7 @@
 #if BUILDFLAG(IS_WIN)
 #include "base/base_paths.h"
 #include "base/strings/utf_string_conversions.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -39,7 +39,7 @@
 namespace remoting {
 namespace {
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 const base::FilePath::CharType kChromotingCrashpadDatabasePath[] =
     FILE_PATH_LITERAL("crashpad");
 #endif
@@ -56,7 +56,7 @@ const size_t kMaxReportsToRetain = 20;
 // Maximum number of days to keep reports around in the local database.
 const size_t kMaxReportAgeDays = 7;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 inline base::FilePath GetDaemonProcessCrashpadDatabasePath() {
   return GetVarLibDir().Append("crashpad.daemon");
@@ -131,7 +131,7 @@ base::FilePath GetCrashpadDatabasePath() {
     base::FilePath path;
     base::PathService::Get(base::BasePathKey::DIR_ASSETS, &path);
     return path.Append(kChromotingCrashpadDatabasePath);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (getuid() == 0) {
       return GetDaemonProcessCrashpadDatabasePath();
     }
@@ -186,7 +186,7 @@ CrashpadDatabaseManager::CrashpadDatabaseManager(Logge
 CrashpadDatabaseManager::~CrashpadDatabaseManager() = default;
 
 bool CrashpadDatabaseManager::InitializeCrashpadDatabase() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   SetupCrashpadDirectories();
 #endif
 
