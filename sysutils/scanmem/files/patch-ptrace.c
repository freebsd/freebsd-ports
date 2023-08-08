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
@@ -94,7 +96,7 @@ bool sm_attach(pid_t target)
     int status;
 
     /* attach to the target application, which should cause a SIGSTOP */
-    if (ptrace(PTRACE_ATTACH, target, NULL, NULL) == -1L) {
+    if (ptrace(PTRACE_ATTACH, target, NULL, 0) == -1L) {
         show_error("failed to attach to %d, %s\n", target, strerror(errno));
         return false;
     }
@@ -117,7 +119,7 @@ bool sm_attach(pid_t target)
 bool sm_detach(pid_t target)
 {
     // addr is ignored on Linux, but should be 1 on FreeBSD in order to let the child process continue execution where it had been interrupted
-    return ptrace(PTRACE_DETACH, target, 1, 0) == 0;
+    return ptrace(PTRACE_DETACH, target, (caddr_t)1, 0) == 0;
 }
 
 
@@ -184,7 +186,7 @@ extern inline bool sm_peekdata(pid_t pid, const void *
     for (i = 0; i < missing_bytes; i += sizeof(long))
     {
         const char *ptrace_address = peekbuf.base + peekbuf.size;
-        long ptraced_long = ptrace(PTRACE_PEEKDATA, pid, ptrace_address, NULL);
+        long ptraced_long = ptrace(PTRACE_PEEKDATA, pid, ptrace_address, 0);
 
         /* check if ptrace() succeeded */
         if (EXPECT(ptraced_long == -1L && errno != 0, false)) {
@@ -195,7 +197,7 @@ extern inline bool sm_peekdata(pid_t pid, const void *
                 for (j = 1, errno = 0; j < sizeof(long); j++, errno = 0) {
                 
                     /* try for a shifted ptrace - 'continue' (i.e. try an increased shift) if it fails */
-                    if ((ptraced_long = ptrace(PTRACE_PEEKDATA, pid, ptrace_address - j, NULL)) == -1L && 
+                    if ((ptraced_long = ptrace(PTRACE_PEEKDATA, pid, ptrace_address - j, 0)) == -1L && 
                         (errno == EIO || errno == EFAULT))
                             continue;
                     
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
@@ -735,7 +737,7 @@ bool sm_write_array(pid_t target, void *addr, const vo
             for(j = 0; j <= sizeof(long) - (len - i); ++j)
             {
                 errno = 0;
-                if(((peek_value = ptrace(PTRACE_PEEKDATA, target, addr - j, NULL)) == -1L) && (errno != 0))
+                if(((peek_value = ptrace(PTRACE_PEEKDATA, target, addr - j, 0)) == -1L) && (errno != 0))
                 {
                     if (errno == EIO || errno == EFAULT) /* may try next shift */
                         continue;
