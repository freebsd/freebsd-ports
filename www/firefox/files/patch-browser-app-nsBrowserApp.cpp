--- browser/app/nsBrowserApp.cpp	2012-03-13 02:36:38.000000000 +0100
+++ ../../../firefox-esr/work/mozilla-esr10/browser/app/nsBrowserApp.cpp	2012-03-15 10:17:09.000000000 +0100
@@ -36,23 +36,14 @@
  *
  * ***** END LICENSE BLOCK ***** */
 
-#include "application.ini.h"
-#include "nsXPCOMGlue.h"
-#if defined(XP_WIN)
+#include "nsXULAppAPI.h"
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
-#include <string.h>
 
 #include "plstr.h"
 #include "prprf.h"
@@ -63,16 +54,11 @@
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
@@ -99,12 +85,12 @@
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
@@ -120,35 +106,22 @@
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
-static int do_main(const char *exePath, int argc, char* argv[])
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
@@ -168,133 +141,23 @@
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
 
-  int result;
-  if (appini) {
-    nsXREAppData *appData;
-    rv = XRE_CreateAppData(appini, &appData);
-    if (NS_FAILED(rv)) {
-      Output("Couldn't read application.ini");
-      return 255;
-    }
-    result = XRE_main(argc, argv, appData);
-    XRE_FreeAppData(appData);
-  } else {
-#ifdef XP_WIN
-    // exePath comes from mozilla::BinaryPath::Get, which returns a UTF-8
-    // encoded path, so it is safe to convert it
-    rv = NS_NewLocalFile(NS_ConvertUTF8toUTF16(exePath), PR_FALSE,
-                         getter_AddRefs(appini));
-#else
-    rv = NS_NewNativeLocalFile(nsDependentCString(exePath), PR_FALSE,
-                               getter_AddRefs(appini));
-#endif
-    if (NS_FAILED(rv)) {
-      return 255;
-    }
-    result = XRE_main(argc, argv, &sAppData);
-  }
-
-  return result;
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
-    result = do_main(exePath, argc, argv);
-  }
-
-  XPCOMGlueShutdown();
+  int result = XRE_main(argc, argv, appData);
+  XRE_FreeAppData(appData);
+  if (appEnv)
+    PR_smprintf_free(appEnv);
   return result;
 }
