--- rkward/rbackend/rksignalsupport.cpp.orig	2008-01-21 19:58:24.000000000 +0100
+++ rkward/rbackend/rksignalsupport.cpp	2009-05-07 19:35:28.000000000 +0200
@@ -23,10 +23,6 @@
 
 #include "../debug.h"
 
-#ifndef __sighandler_t
-typedef void (*__sighandler_t) (int);
-#endif
-
 namespace RKSignalSupportPrivate {
 	struct sigaction r_sigsegv_action;
 	struct sigaction default_sigsegv_action;
