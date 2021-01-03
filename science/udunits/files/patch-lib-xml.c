--- lib/xml.c.orig	2020-12-07 18:37:03 UTC
+++ lib/xml.c
@@ -38,7 +38,7 @@
 #endif
 #include <sys/stat.h>
 #include <sys/types.h>
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #elif defined(__APPLE__)
 #define _DARWIN_C_SOURCE
@@ -2137,7 +2137,7 @@ default_udunits2_xml_path()
     if (absXmlPathname[0] == 0) {
         const char* prefix = NULL; // Installation directory
 
-#       if defined(__APPLE__) || defined(__linux__)
+#       if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
             Dl_info     info;
             const char  sep = '/'; // Pathname component separator
             char        buf[PATH_MAX];
