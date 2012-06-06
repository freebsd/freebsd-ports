--- browser/app/nsBrowserApp.cpp.orig	2012-05-23 20:56:32.000000000 +0200
+++ browser/app/nsBrowserApp.cpp	2012-05-27 18:11:50.000000000 +0200
@@ -37,38 +37,28 @@
  * ***** END LICENSE BLOCK ***** */
 
 #include "nsXULAppAPI.h"
-#include "application.ini.h"
-#include "nsXPCOMGlue.h"
-#if defined(XP_WIN)
+#ifdef XP_WIN
 #include <windows.h>
 #include <stdlib.h>
-#elif defined(XP_UNIX)
-#include <sys/time.h>
-#include <sys/resource.h>
-#endif
-
-#ifdef XP_MACOSX
-#include "MacQuirks.h"
 #endif
 
 #include <stdio.h>
 #include <stdarg.h>
 
+#include "plstr.h"
+#include "prprf.h"
+#include "prenv.h"
+
 #include "nsCOMPtr.h"
 #include "nsILocalFile.h"
 #include "nsStringGlue.h"
 
 #ifdef XP_WIN
+// we want to use the DLL blocklist if possible
+#define XRE_WANT_DLL_BLOCKLIST
 // we want a wmain entry point
 #include "nsWindowsWMain.cpp"
-#define snprintf _snprintf
-#define strcasecmp _stricmp
 #endif
-#include "BinaryPath.h"
-
-#include "nsXPCOMPrivate.h" // for MAXPATHLEN and XPCOM_DLL
-
-#include "mozilla/Telemetry.h"
 
 static void Output(const char *fmt, ... )
 {
@@ -95,12 +85,12 @@
   {
     if (*++arg == '-')
       ++arg;
-    return !strcasecmp(arg, s);
+    return !PL_strcasecmp(arg, s);
   }
 
 #if defined(XP_WIN) || defined(XP_OS2)
   if (*arg == '/')
-    return !strcasecmp(++arg, s);
+    return !PL_strcasecmp(++arg, s);
 #endif
 
   return false;
@@ -116,35 +106,22 @@
   ~ScopedLogging() { NS_LogTerm(); }
 };
 
-XRE_GetFileFromPathType XRE_GetFileFromPath;
-XRE_CreateAppDataType XRE_CreateAppData;
-XRE_FreeAppDataType XRE_FreeAppData;
-#ifdef XRE_HAS_DLL_BLOCKLIST
-XRE_SetupDllBlocklistType XRE_SetupDllBlocklist;
-#endif
-XRE_TelemetryAccumulateType XRE_TelemetryAccumulate;
-XRE_mainType XRE_main;
-
-static const nsDynamicFunctionLoad kXULFuncs[] = {
-    { "XRE_GetFileFromPath", (NSFuncPtr*) &XRE_GetFileFromPath },
-    { "XRE_CreateAppData", (NSFuncPtr*) &XRE_CreateAppData },
-    { "XRE_FreeAppData", (NSFuncPtr*) &XRE_FreeAppData },
-#ifdef XRE_HAS_DLL_BLOCKLIST
-    { "XRE_SetupDllBlocklist", (NSFuncPtr*) &XRE_SetupDllBlocklist },
-#endif
-    { "XRE_TelemetryAccumulate", (NSFuncPtr*) &XRE_TelemetryAccumulate },
-    { "XRE_main", (NSFuncPtr*) &XRE_main },
-    { nsnull, nsnull }
-};
-
-static int do_main(int argc, char* argv[])
+int main(int argc, char* argv[])
 {
+  ScopedLogging log;
+
   nsCOMPtr<nsILocalFile> appini;
-  nsresult rv;
+  nsresult rv = XRE_GetBinaryPath(argv[0], getter_AddRefs(appini));
+  if (NS_FAILED(rv)) {
+    Output("Couldn't calculate the application directory.");
+    return 255;
+  }
+  appini->SetNativeLeafName(NS_LITERAL_CSTRING("application.ini"));
 
   // Allow firefox.exe to launch XULRunner apps via -app <application.ini>
   // Note that -app must be the *first* argument.
-  const char *appDataFile = getenv("XUL_APP_FILE");
+  char *appEnv = nsnull;
+  const char *appDataFile = PR_GetEnv("XUL_APP_FILE");
   if (appDataFile && *appDataFile) {
     rv = XRE_GetFileFromPath(appDataFile, getter_AddRefs(appini));
     if (NS_FAILED(rv)) {
@@ -164,119 +141,23 @@
       return 255;
     }
 
-    char appEnv[MAXPATHLEN];
-    snprintf(appEnv, MAXPATHLEN, "XUL_APP_FILE=%s", argv[2]);
-    if (putenv(appEnv)) {
-      Output("Couldn't set %s.\n", appEnv);
-      return 255;
-    }
+    appEnv = PR_smprintf("XUL_APP_FILE=%s", argv[2]);
+    PR_SetEnv(appEnv);
     argv[2] = argv[0];
     argv += 2;
     argc -= 2;
   }
 
-  if (appini) {
-    nsXREAppData *appData;
-    rv = XRE_CreateAppData(appini, &appData);
-    if (NS_FAILED(rv)) {
-      Output("Couldn't read application.ini");
-      return 255;
-    }
-    int result = XRE_main(argc, argv, appData);
-    XRE_FreeAppData(appData);
-    return result;
-  }
-
-  return XRE_main(argc, argv, &sAppData);
-}
-
-int main(int argc, char* argv[])
-{
-  char exePath[MAXPATHLEN];
-
-#ifdef XP_MACOSX
-  TriggerQuirks();
-#endif
-
-  nsresult rv = mozilla::BinaryPath::Get(argv[0], exePath);
-  if (NS_FAILED(rv)) {
-    Output("Couldn't calculate the application directory.\n");
-    return 255;
-  }
-
-  char *lastSlash = strrchr(exePath, XPCOM_FILE_PATH_SEPARATOR[0]);
-  if (!lastSlash || (lastSlash - exePath > MAXPATHLEN - sizeof(XPCOM_DLL) - 1))
-    return 255;
-
-  strcpy(++lastSlash, XPCOM_DLL);
-
-  int gotCounters;
-#if defined(XP_UNIX)
-  struct rusage initialRUsage;
-  gotCounters = !getrusage(RUSAGE_SELF, &initialRUsage);
-#elif defined(XP_WIN)
-  // GetProcessIoCounters().ReadOperationCount seems to have little to
-  // do with actual read operations. It reports 0 or 1 at this stage
-  // in the program. Luckily 1 coincides with when prefetch is
-  // enabled. If Windows prefetch didn't happen we can do our own
-  // faster dll preloading.
-  IO_COUNTERS ioCounters;
-  gotCounters = GetProcessIoCounters(GetCurrentProcess(), &ioCounters);
-  if (gotCounters && !ioCounters.ReadOperationCount)
-#endif
-  {
-      XPCOMGlueEnablePreload();
-  }
-
-
-  rv = XPCOMGlueStartup(exePath);
-  if (NS_FAILED(rv)) {
-    Output("Couldn't load XPCOM.\n");
-    return 255;
-  }
-  // Reset exePath so that it is the directory name and not the xpcom dll name
-  *lastSlash = 0;
-
-  rv = XPCOMGlueLoadXULFunctions(kXULFuncs);
+  nsXREAppData *appData;
+  rv = XRE_CreateAppData(appini, &appData);
   if (NS_FAILED(rv)) {
-    Output("Couldn't load XRE functions.\n");
+    Output("Couldn't read application.ini");
     return 255;
   }
 
-#ifdef XRE_HAS_DLL_BLOCKLIST
-  XRE_SetupDllBlocklist();
-#endif
-
-  if (gotCounters) {
-#if defined(XP_WIN)
-    XRE_TelemetryAccumulate(mozilla::Telemetry::EARLY_GLUESTARTUP_READ_OPS,
-                            int(ioCounters.ReadOperationCount));
-    XRE_TelemetryAccumulate(mozilla::Telemetry::EARLY_GLUESTARTUP_READ_TRANSFER,
-                            int(ioCounters.ReadTransferCount / 1024));
-    IO_COUNTERS newIoCounters;
-    if (GetProcessIoCounters(GetCurrentProcess(), &newIoCounters)) {
-      XRE_TelemetryAccumulate(mozilla::Telemetry::GLUESTARTUP_READ_OPS,
-                              int(newIoCounters.ReadOperationCount - ioCounters.ReadOperationCount));
-      XRE_TelemetryAccumulate(mozilla::Telemetry::GLUESTARTUP_READ_TRANSFER,
-                              int((newIoCounters.ReadTransferCount - ioCounters.ReadTransferCount) / 1024));
-    }
-#elif defined(XP_UNIX)
-    XRE_TelemetryAccumulate(mozilla::Telemetry::EARLY_GLUESTARTUP_HARD_FAULTS,
-                            int(initialRUsage.ru_majflt));
-    struct rusage newRUsage;
-    if (!getrusage(RUSAGE_SELF, &newRUsage)) {
-      XRE_TelemetryAccumulate(mozilla::Telemetry::GLUESTARTUP_HARD_FAULTS,
-                              int(newRUsage.ru_majflt - initialRUsage.ru_majflt));
-    }
-#endif
-  }
-
-  int result;
-  {
-    ScopedLogging log;
-    result = do_main(argc, argv);
-  }
-
-  XPCOMGlueShutdown();
+  int result = XRE_main(argc, argv, appData);
+  XRE_FreeAppData(appData);
+  if (appEnv)
+    PR_smprintf_free(appEnv);
   return result;
 }
