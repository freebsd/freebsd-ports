--- sav_if/s_comput.h.orig	2004-11-16 20:59:20 UTC
+++ sav_if/s_comput.h
@@ -642,7 +642,7 @@
  * Hardware platform.
  */
 
-# if defined(__i386__)
+# if defined(__i386__) || defined(__amd64__)
 #  define __SOPHOS_I386__
 # elif (defined(__hppa__) && defined(_PA_RISC1_1))
 #  define __SOPHOS_HP_PA__
