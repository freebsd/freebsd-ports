--- libyara/proc.c.orig	2015-02-10 12:43:13 UTC
+++ libyara/proc.c
@@ -140,10 +140,9 @@ int yr_process_get_memory(
 
 #else
 
-#define _XOPEN_SOURCE 500
-
 #include <fcntl.h>
 #include <unistd.h>
+#include <sys/cdefs.h>
 #include <sys/types.h>
 #include <sys/ptrace.h>
 #include <sys/wait.h>
