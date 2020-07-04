--- src/sage/libs/ecl.pyx.orig	2020-06-18 17:03:16 UTC
+++ src/sage/libs/ecl.pyx
@@ -15,7 +15,7 @@ Library interface to Embeddable Common Lisp (ECL)
 #adapted to work with pure Python types.
 
 from libc.stdlib cimport abort
-from libc.signal cimport SIGINT, SIGBUS, SIGSEGV, SIGCHLD
+from libc.signal cimport SIGINT, SIGBUS, SIGSEGV, SIGFPE
 from libc.signal cimport raise_ as signal_raise
 from posix.signal cimport sigaction, sigaction_t
 cimport cysignals.signals
@@ -47,9 +47,14 @@ cdef extern from "eclsig.h":
     void ecl_sig_off()
     cdef sigaction_t ecl_sigint_handler
     cdef sigaction_t ecl_sigbus_handler
+    cdef sigaction_t ecl_sigfpe_handler
     cdef sigaction_t ecl_sigsegv_handler
     cdef mpz_t ecl_mpz_from_bignum(cl_object obj)
     cdef cl_object ecl_bignum_from_mpz(mpz_t num)
+    cdef int fegetexcept()
+    cdef int feenableexcept(int)
+    cdef int fedisableexcept(int)
+    cdef int ecl_feflags
 
 cdef cl_object string_to_object(char * s):
     return ecl_read_from_cstring(s)
@@ -139,7 +144,6 @@ def test_ecl_options():
         ECL_OPT_TRAP_SIGINT = 1
         ECL_OPT_TRAP_SIGILL = 1
         ECL_OPT_TRAP_SIGBUS = 1
-        ECL_OPT_TRAP_SIGCHLD = 0
         ECL_OPT_TRAP_SIGPIPE = 1
         ECL_OPT_TRAP_INTERRUPT_SIGNAL = 1
         ECL_OPT_SIGNAL_HANDLING_THREAD = 0
@@ -153,7 +157,6 @@ def test_ecl_options():
         ECL_OPT_LISP_STACK_SAFETY_AREA = ...
         ECL_OPT_C_STACK_SIZE = ...
         ECL_OPT_C_STACK_SAFETY_AREA = ...
-        ECL_OPT_SIGALTSTACK_SIZE = 1
         ECL_OPT_HEAP_SIZE = ...
         ECL_OPT_HEAP_SAFETY_AREA = ...
         ECL_OPT_THREAD_INTERRUPT_SIGNAL = ...
@@ -171,8 +174,6 @@ def test_ecl_options():
         ecl_get_option(ECL_OPT_TRAP_SIGILL)))
     print('ECL_OPT_TRAP_SIGBUS = {0}'.format(
         ecl_get_option(ECL_OPT_TRAP_SIGBUS)))
-    print('ECL_OPT_TRAP_SIGCHLD = {0}'.format(
-        ecl_get_option(ECL_OPT_TRAP_SIGCHLD)))
     print('ECL_OPT_TRAP_SIGPIPE = {0}'.format(
         ecl_get_option(ECL_OPT_TRAP_SIGPIPE)))
     print('ECL_OPT_TRAP_INTERRUPT_SIGNAL = {0}'.format(
@@ -199,8 +200,6 @@ def test_ecl_options():
         ecl_get_option(ECL_OPT_C_STACK_SIZE)))
     print('ECL_OPT_C_STACK_SAFETY_AREA = {0}'.format(
         ecl_get_option(ECL_OPT_C_STACK_SAFETY_AREA)))
-    print('ECL_OPT_SIGALTSTACK_SIZE = {0}'.format(
-        ecl_get_option(ECL_OPT_SIGALTSTACK_SIZE)))
     print('ECL_OPT_HEAP_SIZE = {0}'.format(
         ecl_get_option(ECL_OPT_HEAP_SIZE)))
     print('ECL_OPT_HEAP_SAFETY_AREA = {0}'.format(
@@ -238,14 +237,12 @@ def init_ecl():
     global ecl_has_booted
     cdef char *argv[1]
     cdef sigaction_t sage_action[32]
+    cdef int sage_fpes
     cdef int i
 
     if ecl_has_booted:
         raise RuntimeError("ECL is already initialized")
 
-    # we need it to stop handling SIGCHLD
-    ecl_set_option(ECL_OPT_TRAP_SIGCHLD, 0);
-
     #we keep our own GMP memory functions. ECL should not claim them
     ecl_set_option(ECL_OPT_SET_GMP_MEMORY_FUNCTIONS,0);
 
@@ -257,6 +254,8 @@ def init_ecl():
     for i in range(1,32):
         sigaction(i, NULL, &sage_action[i])
 
+    sage_fpes = fegetexcept()
+
     #initialize ECL
     ecl_set_option(ECL_OPT_SIGNAL_HANDLING_THREAD, 0)
     cl_boot(1, argv)
@@ -264,18 +263,19 @@ def init_ecl():
     #save signal handler from ECL
     sigaction(SIGINT, NULL, &ecl_sigint_handler)
     sigaction(SIGBUS, NULL, &ecl_sigbus_handler)
+    sigaction(SIGFPE, NULL, &ecl_sigfpe_handler)
     sigaction(SIGSEGV, NULL, &ecl_sigsegv_handler)
 
-    #verify that no SIGCHLD handler was installed
-    cdef sigaction_t sig_test
-    sigaction(SIGCHLD, NULL, &sig_test)
-    assert sage_action[SIGCHLD].sa_handler == NULL  # Sage does not set SIGCHLD handler
-    assert sig_test.sa_handler == NULL              # And ECL bootup did not set one 
+    #save ECL's floating point exception flags
+    ecl_feflags = fegetexcept()
 
     #and put the Sage signal handlers back
     for i in range(1,32):
         sigaction(i, &sage_action[i], NULL)
 
+    fedisableexcept(ecl_feflags)
+    feenableexcept(sage_fpes)
+
     #initialise list of objects and bind to global variable
     # *SAGE-LIST-OF-OBJECTS* to make it rooted in the reachable tree for the GC
     list_of_objects=cl_cons(Cnil,cl_cons(Cnil,Cnil))
@@ -319,7 +319,6 @@ def init_ecl():
                     (values nil (princ-to-string cnd)))))
         """))
     safe_funcall_clobj=cl_eval(string_to_object(b"(symbol-function 'sage-safe-funcall)"))
-
     ecl_has_booted = 1
 
 cdef cl_object ecl_safe_eval(cl_object form) except NULL:
