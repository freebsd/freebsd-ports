--- flower/include/std-string.hh.orig	2016-08-30 10:23:53 UTC
+++ flower/include/std-string.hh
@@ -38,6 +38,7 @@ using namespace std;
 typedef size_t ssize;
 #define NPOS string::npos
 
+#if _cplusplus <= 19971L
 string to_string (const string&);
 string to_string (char c, int n = 1);
 string to_string (int i, char const *format = 0);
@@ -49,6 +50,7 @@ string to_string (unsigned);
 string to_string (bool b);
 string to_string (char const *format, ...)
 __attribute__ ((format (printf, 1, 2)));
+#endif
 
 string &replace_all (string *str, string const &find, string const &replace);
 string &replace_all (string *str, char find, char replace);
