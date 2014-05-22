--- flower/include/std-string.hh.orig	2014-04-07 10:27:23.000000000 +0200
+++ flower/include/std-string.hh	2014-04-07 10:27:33.000000000 +0200
@@ -39,6 +39,7 @@
 typedef size_t ssize;
 #define NPOS string::npos
 
+#if _cplusplus <= 19971L
 string to_string (const string&);
 string to_string (char c, int n = 1);
 string to_string (int i, char const *format = 0);
@@ -50,6 +51,7 @@
 string to_string (bool b);
 string to_string (char const *format, ...)
 __attribute__ ((format (printf, 1, 2)));
+#endif
 
 string &replace_all (string *str, string const &find, string const &replace);
 string &replace_all (string *str, char find, char replace);
