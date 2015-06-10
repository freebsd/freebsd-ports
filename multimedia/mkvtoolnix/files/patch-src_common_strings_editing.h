--- src/common/strings/editing.h.orig	2015-06-08 16:25:26.833411779 +0200
+++ src/common/strings/editing.h	2015-06-08 16:25:45.153412704 +0200
@@ -43,7 +43,6 @@
 extern const std::string empty_string;
 
 int get_arg_len(const char *fmt, ...);
-int get_varg_len(const char *fmt, va_list ap);
 
 size_t utf8_strlen(const std::string &s);
 
