--- ./libyara/proc.c.orig	2011-03-18 09:56:15.000000000 -0400
+++ ./libyara/proc.c	2011-05-23 08:47:07.456485028 -0400
@@ -122,17 +122,18 @@
 #include "mem.h"
 #include "proc.h"
 
-#ifdef __MACH__
+#if defined(__FreeBSD__) || defined(__MACH__)
+#define PTRACE_ATTACH PT_ATTACH
+#define PTRACE_DETACH PT_DETACH
+#endif
+
+#if defined(__MACH__)
 
 #include <mach/mach.h>
 #include <mach/mach_vm.h>
 #include <mach/vm_region.h>
 #include <mach/vm_statistics.h>
 
-#define PTRACE_ATTACH PT_ATTACH
-#define PTRACE_DETACH PT_DETACH
-
-
 int get_process_memory(pid_t pid, MEMORY_BLOCK** first_block)
 {
     task_t task;
