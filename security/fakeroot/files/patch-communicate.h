--- communicate.h.orig	2026-08-31 14:03:04 UTC
+++ communicate.h
@@ -69,7 +69,7 @@
 	|| (defined __UCLIBC__ && defined __UCLIBC_HAS_LFS__)
 # define STAT64_SUPPORT
 #else
-# ifndef __APPLE__
+# if !defined(__APPLE__) && !defined(__FreeBSD__)
 #  warning Not using stat64 support
 # endif
 /* if glibc is 2.0 or older, undefine these again */
