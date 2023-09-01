--- process.h.orig	2023-09-01 07:49:45 UTC
+++ process.h
@@ -4,8 +4,8 @@
 #include <stdbool.h>
 #include <sys/types.h>
 
-int ARGC;
-char **ARGV;
+extern int ARGC;
+extern char **ARGV;
 
 void process_set_name(const char *name);
 void process_disable_ptrace(void);
