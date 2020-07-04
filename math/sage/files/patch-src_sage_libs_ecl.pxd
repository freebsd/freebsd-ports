--- src/sage/libs/ecl.pxd.orig	2020-06-18 17:03:16 UTC
+++ src/sage/libs/ecl.pxd
@@ -39,7 +39,6 @@ cdef extern from "ecl/ecl.h":
         ECL_OPT_TRAP_SIGINT,
         ECL_OPT_TRAP_SIGILL,
         ECL_OPT_TRAP_SIGBUS,
-        ECL_OPT_TRAP_SIGCHLD,
         ECL_OPT_TRAP_SIGPIPE,
         ECL_OPT_TRAP_INTERRUPT_SIGNAL,
         ECL_OPT_SIGNAL_HANDLING_THREAD,
@@ -53,7 +52,6 @@ cdef extern from "ecl/ecl.h":
         ECL_OPT_LISP_STACK_SAFETY_AREA,
         ECL_OPT_C_STACK_SIZE,
         ECL_OPT_C_STACK_SAFETY_AREA,
-        ECL_OPT_SIGALTSTACK_SIZE,
         ECL_OPT_HEAP_SIZE,
         ECL_OPT_HEAP_SAFETY_AREA,
         ECL_OPT_THREAD_INTERRUPT_SIGNAL,
