--- OMCompiler/Compiler/runtime/settingsimpl.c.orig	2022-12-10 10:59:38 UTC
+++ OMCompiler/Compiler/runtime/settingsimpl.c
@@ -90,7 +90,7 @@ const char* SettingsImpl__getInstallationDirectoryPath
   return path &&*path ? path : "OPENMODELICA_BOOTSTRAPPING_STAGE_NO_OPENMODELICAHOME";
 }
 #else
-#if (defined(__linux__) || defined(__APPLE_CC__))
+#if (defined(__linux__) || defined(__APPLE_CC__) || defined(__FreeBSD__))
 /* Helper function to strip /bin/... or /lib/... from the executable path of omc */
 static void stripbinpath(char *omhome)
 {
@@ -112,7 +112,7 @@ static void stripbinpath(char *omhome)
 #endif
 
 /* Do not free or modify the returned variable of getInstallationDirectoryPath. It's part of the environment! */
-#if defined(__linux__) || defined(__APPLE_CC__)
+#if defined(__linux__) || defined(__APPLE_CC__) || defined(__FreeBSD__)
 #include <dlfcn.h>
 
 const char* SettingsImpl__getInstallationDirectoryPath(void) {
