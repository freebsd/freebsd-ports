--- lib/parse.C.orig	Tue Mar 15 15:23:24 2005
+++ lib/parse.C	Sun Mar 20 21:45:20 2005
@@ -31,7 +31,6 @@
 #ifndef _WIN32
 #include <cstring>
 #include <cstdlib>
-#include <locale>
 #include <string>
 #endif
 
@@ -63,10 +62,7 @@
 bool parse_int(const char* buf, const char* tag, int& x) {
     char* p = strstr(buf, tag);
     if (!p) return false;
-    std::string strLocale = setlocale(LC_NUMERIC, NULL);
-    setlocale(LC_NUMERIC, "C");
     x = strtol(p+strlen(tag), 0, 0);        // this parses 0xabcd correctly
-    setlocale(LC_NUMERIC, strLocale.c_str());
     return true;
 }
 
@@ -75,10 +71,7 @@
 bool parse_double(const char* buf, const char* tag, double& x) {
     char* p = strstr(buf, tag);
     if (!p) return false;
-    std::string strLocale = setlocale(LC_NUMERIC, NULL);
-    setlocale(LC_NUMERIC, "C");
     x = atof(p+strlen(tag));
-    setlocale(LC_NUMERIC, strLocale.c_str());
     return true;
 }
 
