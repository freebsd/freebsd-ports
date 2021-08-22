--- chrome/common/chrome_paths.h.orig	2021-07-19 18:45:10 UTC
+++ chrome/common/chrome_paths.h
@@ -57,7 +57,7 @@ enum {
 #if BUILDFLAG(IS_CHROMEOS_ASH) ||                            \
     ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
      BUILDFLAG(CHROMIUM_BRANDING)) ||                        \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
   DIR_USER_EXTERNAL_EXTENSIONS,  // Directory for per-user external extensions
                                  // on Chrome Mac and Chromium Linux.
                                  // On Chrome OS, this path is used for OEM
@@ -65,7 +65,7 @@ enum {
                                  // create it.
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   DIR_STANDALONE_EXTERNAL_EXTENSIONS,  // Directory for 'per-extension'
                                        // definition manifest files that
                                        // describe extensions which are to be
@@ -109,7 +109,7 @@ enum {
   DIR_CHROMEOS_CUSTOM_WALLPAPERS,     // Directory where custom wallpapers
                                       // reside.
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   DIR_NATIVE_MESSAGING,       // System directory where native messaging host
                               // manifest files are stored.
   DIR_USER_NATIVE_MESSAGING,  // Directory with Native Messaging Hosts
