--- sav_if/s_comput.h.orig	2009-09-18 21:22:27.000000000 +0900
+++ sav_if/s_comput.h	2009-09-18 21:22:52.000000000 +0900
@@ -642,7 +642,7 @@
  * Hardware platform.
  */
 
-# if defined(__i386__)
+# if defined(__i386__) || defined(__amd64__)
 #  define __SOPHOS_I386__
 # elif (defined(__hppa__) && defined(_PA_RISC1_1))
 #  define __SOPHOS_HP_PA__
