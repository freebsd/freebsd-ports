--- bench/benchmarks.c.orig	Sun Aug 24 11:04:51 2003
+++ bench/benchmarks.c	Sun Aug 24 11:08:26 2003
@@ -1,7 +1,8 @@
 #include <time.h>
 #include <sys/time.h>
-#include <asm/unistd.h>
+#include <sys/unistd.h>
 #include <sys/stat.h>
+#include <sys/syscall.h>
 #include <stdio.h>
 #include "../x86info.h"
 #include "bench.h"
@@ -13,7 +14,7 @@
 	if (show_bench != 1)
 		return;
 
-	TIME(asm volatile("int $0x80" :"=a" (ret) :"0" (__NR_getppid)), "int 0x80");
+	TIME(asm volatile("int $0x80" :"=a" (ret) :"0" (SYS_getppid)), "int 0x80");
 	TIME(asm volatile("cpuid": : :"ax", "dx", "cx", "bx"), "cpuid");
 
 	TIME(asm volatile("addl $1,0(%esp)"), "addl");
