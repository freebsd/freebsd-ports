--- build/m4/ax_c___atomic.m4.orig	2018-12-26 13:22:11 UTC
+++ build/m4/ax_c___atomic.m4
@@ -6,7 +6,12 @@ AC_DEFUN([AC_C___ATOMIC],
 [AC_CACHE_CHECK([for __atomic], ac_cv_c___atomic,
 [AC_LINK_IFELSE(
    [AC_LANG_SOURCE(
-      [[int
+      [[typedef struct test {
+        volatile uint16_t a;
+        volatile uint64_t b;
+        volatile uint64_t c;
+        } test_t;
+        int
         main (int argc, char **argv)
         {
           volatile unsigned long ul1 = 1, ul2 = 0, ul3 = 2;
@@ -23,6 +28,8 @@ AC_DEFUN([AC_C___ATOMIC],
           __atomic_fetch_sub(&ull3, 1, __ATOMIC_SEQ_CST);
           __atomic_or_fetch(&ull1, ull2, __ATOMIC_SEQ_CST);
           __atomic_and_fetch(&ull1, ull2, __ATOMIC_SEQ_CST);
+          volatile test_t test = {.a = 0, .b = 0, .c = 1};
+          __atomic_fetch_add(&test.b, 1, __ATOMIC_SEQ_CST);
           return 0;
         }
       ]])],
