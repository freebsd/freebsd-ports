--- bench/benchmarks.c.orig	Tue Oct  4 19:22:20 2005
+++ bench/benchmarks.c	Tue Oct  4 19:22:40 2005
@@ -1,6 +1,5 @@
 #include <time.h>
 #include <sys/time.h>
-#include <asm/unistd.h>
 #include <sys/stat.h>
 #include <stdio.h>
 #include "../x86info.h"
@@ -13,7 +12,6 @@
 	if (show_bench != 1)
 		return;
 
-	TIME(asm volatile("int $0x80" :"=a" (ret) :"0" (__NR_getppid)), "int 0x80");
 	TIME(asm volatile("cpuid": : :"ax", "dx", "cx", "bx"), "cpuid");
 
 	TIME(asm volatile("addl $1,0(%esp)"), "addl");
