--- ptrace.c.orig	2012-04-22 03:04:11 UTC
+++ ptrace.c
@@ -22,11 +22,13 @@
 
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
@@ -376,7 +378,7 @@ bool checkmatches(globals_t * vars, 
     return detach(vars->target);
 }
 
-/* read region using /proc/pid/mem */
+/* read region using /compat/linux/proc/pid/mem */
 ssize_t readregion(pid_t target, void *buf, size_t count, unsigned long offset)
 {
     char mem[32];
@@ -384,7 +386,7 @@ ssize_t readregion(pid_t target, void *b
     ssize_t len;
     
     /* print the path to mem file */
-    snprintf(mem, sizeof(mem), "/proc/%d/mem", target);
+    snprintf(mem, sizeof(mem), "/compat/linux/proc/%d/mem", target);
     
     /* attempt to open the file */
     if ((fd = open(mem, O_RDONLY)) == -1) {
@@ -498,7 +500,7 @@ bool searchregions(globals_t * vars, sca
         }
 
 #else     
-        /* cannot use /proc/pid/mem */
+        /* cannot use /compat/linux/proc/pid/mem */
         nread = r->size;
 #endif
         /* print a progress meter so user knows we havent crashed */
@@ -632,7 +634,7 @@ bool setaddr(pid_t target, void *addr, c
         return false;
     }
 
-    /* TODO: may use /proc/<pid>/mem here */
+    /* TODO: may use /compat/linux/proc/<pid>/mem here */
     /* assume that sizeof(save.int64_value) (int64_t) is multiple of sizeof(long) */
     for (i = 0; i < sizeof(saved.int64_value); i += sizeof(long)) 
     {
@@ -687,7 +689,7 @@ bool read_array(pid_t target, void *addr
 #endif
 }
 
-/* TODO: may use /proc/<pid>/mem here */
+/* TODO: may use /compat/linux/proc/<pid>/mem here */
 bool write_array(pid_t target, void *addr, const void *data, int len)
 {
     int i,j;
