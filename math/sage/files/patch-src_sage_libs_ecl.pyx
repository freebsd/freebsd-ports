--- src/sage/libs/ecl.pyx.orig	2020-05-22 13:21:27 UTC
+++ src/sage/libs/ecl.pyx
@@ -15,7 +15,7 @@ Library interface to Embeddable Common Lisp (ECL)
 #adapted to work with pure Python types.
 
 from libc.stdlib cimport abort
-from libc.signal cimport SIGINT, SIGBUS, SIGSEGV, SIGCHLD
+from libc.signal cimport SIGINT, SIGBUS, SIGSEGV, SIGCHLD, SIGFPE
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
@@ -238,6 +243,7 @@ def init_ecl():
     global ecl_has_booted
     cdef char *argv[1]
     cdef sigaction_t sage_action[32]
+    cdef int sage_fpes
     cdef int i
 
     if ecl_has_booted:
@@ -257,6 +263,8 @@ def init_ecl():
     for i in range(1,32):
         sigaction(i, NULL, &sage_action[i])
 
+    sage_fpes = fegetexcept()
+
     #initialize ECL
     ecl_set_option(ECL_OPT_SIGNAL_HANDLING_THREAD, 0)
     cl_boot(1, argv)
@@ -264,8 +272,12 @@ def init_ecl():
     #save signal handler from ECL
     sigaction(SIGINT, NULL, &ecl_sigint_handler)
     sigaction(SIGBUS, NULL, &ecl_sigbus_handler)
+    sigaction(SIGFPE, NULL, &ecl_sigfpe_handler)
     sigaction(SIGSEGV, NULL, &ecl_sigsegv_handler)
 
+    #save ECL's floating point exception flags
+    ecl_feflags = fegetexcept()
+
     #verify that no SIGCHLD handler was installed
     cdef sigaction_t sig_test
     sigaction(SIGCHLD, NULL, &sig_test)
@@ -276,6 +288,9 @@ def init_ecl():
     for i in range(1,32):
         sigaction(i, &sage_action[i], NULL)
 
+    fedisableexcept(ecl_feflags)
+    feenableexcept(sage_fpes)
+
     #initialise list of objects and bind to global variable
     # *SAGE-LIST-OF-OBJECTS* to make it rooted in the reachable tree for the GC
     list_of_objects=cl_cons(Cnil,cl_cons(Cnil,Cnil))
@@ -319,7 +334,6 @@ def init_ecl():
                     (values nil (princ-to-string cnd)))))
         """))
     safe_funcall_clobj=cl_eval(string_to_object(b"(symbol-function 'sage-safe-funcall)"))
-
     ecl_has_booted = 1
 
 cdef cl_object ecl_safe_eval(cl_object form) except NULL:
