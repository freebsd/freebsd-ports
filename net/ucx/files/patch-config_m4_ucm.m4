--- config/m4/ucm.m4.orig	2026-02-04 09:52:46 UTC
+++ config/m4/ucm.m4
@@ -15,11 +15,18 @@ AC_ARG_WITH([allocator],
         [],
         [with_allocator=ptmalloc286])
 
+AC_CHECK_FUNCS([brk sbrk], [], [], [#include <unistd.h>])
+
+HAVE_UCM_PTMALLOC286=no
+
 case ${with_allocator} in
     ptmalloc286)
         AC_MSG_NOTICE(Memory allocator is ptmalloc-2.8.6 version)
-        AC_DEFINE([HAVE_UCM_PTMALLOC286], 1, [Use ptmalloc-2.8.6 version])
-        HAVE_UCM_PTMALLOC286=yes
+        AS_IF([test "x$ac_cv_func_brk" = "xyes" && test "x$ac_cv_func_sbrk" = "xyes"],
+              [AC_DEFINE([HAVE_UCM_PTMALLOC286], 1, [Use ptmalloc-2.8.6 version])
+               HAVE_UCM_PTMALLOC286=yes],
+              [AC_MSG_WARN([brk()/sbrk() not available; disabling ptmalloc286 allocator])
+               HAVE_UCM_PTMALLOC286=no])
         ;;
     *)
         AC_MSG_ERROR(Cannot continue. Unsupported memory allocator name
@@ -83,6 +90,9 @@ AS_IF([test "x$mmap_hooks_happy" = "xyes"],
 AS_IF([test "x$mmap_hooks_happy" = "xyes"],
       AS_IF([test "x$ipc_hooks_happy" = "xyes" -o "x$shm_hooks_happy" = "xyes"],
             [bistro_hooks_happy=yes]))
+
+AS_IF([test "x$ac_cv_func_brk" != "xyes" -o "x$ac_cv_func_sbrk" != "xyes"],
+      [bistro_hooks_happy=no])
 
 AS_IF([test "x$bistro_hooks_happy" = "xyes"],
       [AC_DEFINE([UCM_BISTRO_HOOKS], [1], [Enable BISTRO hooks])],
