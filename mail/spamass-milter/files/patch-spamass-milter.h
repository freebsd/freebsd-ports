--- spamass-milter.h.orig	2006-03-23 23:07:55.000000000 +0100
+++ spamass-milter.h	2010-05-06 11:25:01.000000000 +0200
@@ -186,5 +186,6 @@
 void parse_debuglevel(char* string);
 char *strlwr(char *str);
 void warnmacro(char *macro, char *scope);
+FILE *popenv(char *const argv[], const char *type);
 
 #endif
