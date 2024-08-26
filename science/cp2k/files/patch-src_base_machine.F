--- src/base/machine.F.orig	2024-08-25 22:12:03 UTC
+++ src/base/machine.F
@@ -337,7 +337,7 @@ CONTAINS
       ! __NO_STATM_ACCESS can be used to disable the stuff, if getpagesize
       ! lead to linking errors or /proc/self/statm can not be opened
       !
-#if defined(__NO_STATM_ACCESS)
+#if 1 || defined(__NO_STATM_ACCESS)
       mem_local = 0
 #else
       INTEGER(KIND=int_8)                      :: m1, m2, m3
