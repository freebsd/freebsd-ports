--- js/src/jslock.cpp.orig	2009-10-07 20:15:38.000000000 +0200
+++ js/src/jslock.cpp	2009-10-07 21:36:14.000000000 +0200
@@ -160,8 +160,13 @@
     unsigned int res;
 
     __asm__ __volatile__ (
-                  "stbar\n"
-                  "cas [%1],%2,%3\n"
+                  "membar #StoreLoad | #LoadLoad\n"
+#                 if defined (__sparc64__)
+                    "casx [%1],%2,%3\n"
+#                 else
+                    "cas [%1],%2,%3\n" /* 32-bit version */
+#                 endif
+                  "membar #StoreLoad | #LoadLoad\n"
                   "cmp %2,%3\n"
                   "be,a 1f\n"
                   "mov 1,%0\n"
