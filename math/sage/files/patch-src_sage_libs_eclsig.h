--- src/sage/libs/eclsig.h.orig	2020-05-22 13:21:27 UTC
+++ src/sage/libs/eclsig.h
@@ -9,24 +9,66 @@
 
 
 #include <signal.h>
+
+/* Rummage around to determine how ECL was configured */
+#define ECL_AVOID_FPE_H  /* Prevent some local includes */
+#include <ecl/config-internal.h>
+
+#ifdef HAVE_FENV_H
+#include <fenv.h>
+#ifndef FE_ALL_EXCEPT
+#define FE_ALL_EXCEPT FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW | FE_INVALID
+#endif
+#else
+#ifndef FE_ALL_EXCEPT
+#define FE_ALL_EXCEPT 0
+#endif
+#define feclearexcept(flags) do {} while (0)
+#endif
+
+#ifndef HAVE_FEENABLEEXCEPT
+/* These are GNU extensions */
+#define fegetexcept() 0
+#define feenablexcept(flags) do {} while (0)
+#define fdisableexcept(flags) do {} while (0)
+#endif
+
 static struct sigaction ecl_sigint_handler;
 static struct sigaction ecl_sigbus_handler;
+static struct sigaction ecl_sigfpe_handler;
 static struct sigaction ecl_sigsegv_handler;
 static struct sigaction sage_sigint_handler;
 static struct sigaction sage_sigbus_handler;
+static struct sigaction sage_sigfpe_handler;
 static struct sigaction sage_sigsegv_handler;
+static int ecl_feflags;
+static int sage_feflags;
 
 static inline void set_ecl_signal_handler(void)
 {
     sigaction(SIGINT, &ecl_sigint_handler, &sage_sigint_handler);
     sigaction(SIGBUS, &ecl_sigbus_handler, &sage_sigbus_handler);
+    sigaction(SIGFPE, &ecl_sigfpe_handler, &sage_sigfpe_handler);
     sigaction(SIGSEGV, &ecl_sigsegv_handler, &sage_sigsegv_handler);
+
+    /* first clear pending floating point exceptions, if any */
+    feclearexcept(FE_ALL_EXCEPT);
+
+    /* sage_feflags should be 0; we don't set them otherwise */
+    sage_feflags = fedisableexcept(FE_ALL_EXCEPT);
+    feenableexcept(ecl_feflags);
 }
 
 static inline void unset_ecl_signal_handler(void)
 {
+    /* clear pending exceptions and restore previous exception mask */
+    feclearexcept(FE_ALL_EXCEPT);
+    ecl_feflags = fedisableexcept(FE_ALL_EXCEPT);
+    feenableexcept(sage_feflags);
+
     sigaction(SIGINT, &sage_sigint_handler, NULL);
     sigaction(SIGBUS, &sage_sigbus_handler, NULL);
+    sigaction(SIGFPE, &sage_sigfpe_handler, NULL);
     sigaction(SIGSEGV, &sage_sigsegv_handler, NULL);
 }
 
