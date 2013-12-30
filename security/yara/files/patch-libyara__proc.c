--- ./libyara/proc.c.orig	2013-12-26 09:01:02.000000000 -0500
+++ ./libyara/proc.c	2013-12-28 15:26:52.000000000 -0500
@@ -141,10 +141,9 @@
 
 #else
 
-#define _XOPEN_SOURCE 500
-
 #include <fcntl.h>
 #include <unistd.h>
+#include <sys/cdefs.h>
 #include <sys/types.h>
 #include <sys/ptrace.h>
 #include <sys/wait.h>
