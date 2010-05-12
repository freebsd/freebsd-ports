--- spamass-milter.h.orig	2010-05-12 11:58:14.000000000 +0200
+++ spamass-milter.h	2010-05-12 12:05:27.000000000 +0200
@@ -186,5 +186,6 @@
 void parse_debuglevel(char* string);
 char *strlwr(char *str);
 void warnmacro(char *macro, char *scope);
+FILE *popenv(char *const argv[], const char *type, pid_t *pid);
 
 #endif
