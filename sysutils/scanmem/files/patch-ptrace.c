--- ptrace.c.orig	2017-10-13 21:53:16 UTC
+++ ptrace.c
@@ -25,11 +25,13 @@
 
 #include "config.h"
 
+#if 0
 /* for pread */
 # ifdef _XOPEN_SOURCE
 #  undef _XOPEN_SOURCE
 # endif
 # define _XOPEN_SOURCE 500
+#endif
 
 #include <time.h>
 #include <sys/types.h>
@@ -406,7 +408,7 @@ bool sm_checkmatches(globals_t *vars,
     return sm_detach(vars->target);
 }
 
-/* read region using /proc/pid/mem */
+/* read region using /compat/linux/proc/pid/mem */
 static inline ssize_t readregion(pid_t target, void *buf, size_t count, unsigned long offset)
 {
     char mem[32];
@@ -414,7 +416,7 @@ static inline ssize_t readregion(pid_t target, void *b
     ssize_t len;
     
     /* print the path to mem file */
-    snprintf(mem, sizeof(mem), "/proc/%d/mem", target);
+    snprintf(mem, sizeof(mem), "/compat/linux/proc/%d/mem", target);
     
     /* attempt to open the file */
     if ((fd = open(mem, O_RDONLY)) == -1) {
@@ -650,7 +652,7 @@ bool sm_setaddr(pid_t target, void *addr, const value_
         return false;
     }
 
-    /* TODO: may use /proc/<pid>/mem here */
+    /* TODO: may use /compat/linux/proc/<pid>/mem here */
     for (i = 0; i < sizeof(uint64_t)/sizeof(long); i++)
     {
         if (ptrace(PTRACE_POKEDATA, target, addr + i*sizeof(long), memarray[i]) == -1L) {
@@ -704,7 +706,7 @@ bool sm_read_array(pid_t target, const void *addr, cha
 #endif
 }
 
-/* TODO: may use /proc/<pid>/mem here */
+/* TODO: may use /compat/linux/proc/<pid>/mem here */
 bool sm_write_array(pid_t target, void *addr, const void *data, int len)
 {
     int i,j;
