--- lib/parse.C.orig	Tue May 31 17:59:28 2005
+++ lib/parse.C	Wed Jun  1 20:56:12 2005
@@ -32,7 +32,6 @@
 #ifndef _WIN32
 #include <cstring>
 #include <cstdlib>
-#include <locale>
 #include <string>
 #if HAVE_IEEEFP_H
 #include <ieeefp.h>
@@ -67,10 +66,7 @@
 bool parse_int(const char* buf, const char* tag, int& x) {
     char* p = strstr(buf, tag);
     if (!p) return false;
-    std::string strLocale = setlocale(LC_NUMERIC, NULL);
-    setlocale(LC_NUMERIC, "C");
     x = strtol(p+strlen(tag), 0, 0);        // this parses 0xabcd correctly
-    setlocale(LC_NUMERIC, strLocale.c_str());
     return true;
 }
 
@@ -80,10 +76,7 @@
     double y;
     char* p = strstr(buf, tag);
     if (!p) return false;
-    std::string strLocale = setlocale(LC_NUMERIC, NULL);
-    setlocale(LC_NUMERIC, "C");
     y = atof(p+strlen(tag));
-    setlocale(LC_NUMERIC, strLocale.c_str());
     if (finite(y)) {
         x = y;
         return true;
