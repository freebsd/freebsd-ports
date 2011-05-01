--- ./rkward/rbackend/rksignalsupport.cpp.orig	2011-02-23 12:43:20.000000000 +0100
+++ ./rkward/rbackend/rksignalsupport.cpp	2011-05-01 15:38:25.000000000 +0200
@@ -23,18 +23,18 @@
 
 #include "../debug.h"
 
-#ifndef __sighandler_t
-	typedef void (*__sighandler_t) (int);
-#endif
+// On some platforms sighandler_t is defined, on others it is not, but it's required to be the same everywhere, anyway.
+// To avoid re-definition errors, we just use our own "type".
+typedef void (*rk_sighandler_t) (int);
 
 namespace RKSignalSupportPrivate {
 #ifdef Q_WS_WIN
-	__sighandler_t r_sigsegv_handler = 0;
-	__sighandler_t default_sigsegv_handler = 0;
-	__sighandler_t r_sigill_handler = 0;
-	__sighandler_t default_sigill_handler = 0;
-	__sighandler_t r_sigabrt_handler = 0;
-	__sighandler_t default_sigabrt_handler = 0;
+	rk_sighandler_t r_sigsegv_handler = 0;
+	rk_sighandler_t default_sigsegv_handler = 0;
+	rk_sighandler_t r_sigill_handler = 0;
+	rk_sighandler_t default_sigill_handler = 0;
+	rk_sighandler_t r_sigabrt_handler = 0;
+	rk_sighandler_t default_sigabrt_handler = 0;
 #else
 	struct sigaction r_sigsegv_handler;
 	struct sigaction default_sigsegv_handler;
@@ -43,7 +43,7 @@
 	struct sigaction r_sigabrt_handler;
 	struct sigaction default_sigabrt_handler;
 #endif
-	__sighandler_t r_sigint_handler = 0;
+	rk_sighandler_t r_sigint_handler = 0;
 	void (*new_sigint_handler) (void) = 0;
 	void internal_sigint_handler (int num) {
 		new_sigint_handler ();
@@ -52,8 +52,8 @@
 
 #ifdef Q_WS_WIN
 	void signal_proxy (int signum) {
-		__sighandler_t r_handler = r_sigsegv_handler;
-		__sighandler_t default_handler = default_sigsegv_handler;
+		rk_sighandler_t r_handler = r_sigsegv_handler;
+		rk_sighandler_t default_handler = default_sigsegv_handler;
 #else
 	void signal_proxy (int signum, siginfo_t *info, void *context) {
 		struct sigaction r_handler = r_sigsegv_handler;
