--- indep.h.orig	Mon Oct 29 09:49:01 2001
+++ indep.h	Mon Oct 29 09:49:52 2001
@@ -23,7 +23,7 @@
 extern char *cleanupName2(char *name, int flag);
 #define cleanupName(name) cleanupName2((name), TRUE)
 extern char *expandPath(char *name);
-extern char *strcasestr(char *s1, char *s2);
+extern char *strcasestr(const char *s1, const char *s2);
 extern int strcasemstr(char *str, char *srch[], char **ret_ptr);
 extern char *remove_space(char *str);
 extern int non_null(char *s);
