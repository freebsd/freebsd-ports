--- cef/libcef/common/resource_util.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/common/resource_util.cc
@@ -4,7 +4,7 @@
 
 #include "cef/libcef/common/resource_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <dlfcn.h>
 #endif
 
@@ -16,7 +16,7 @@
 #include "chrome/common/chrome_paths.h"
 #include "chrome/common/chrome_switches.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #endif
@@ -29,7 +29,7 @@ namespace resource_util {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // Based on chrome/common/chrome_paths_linux.cc.
 // See http://standards.freedesktop.org/basedir-spec/basedir-spec-latest.html
@@ -140,7 +140,7 @@ void OverrideUserDataDir(CefSettings* se
       true);  // Create if necessary.
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void OverrideAssetPath() {
   Dl_info dl_info;
   if (dladdr(reinterpret_cast<const void*>(&OverrideAssetPath), &dl_info)) {
