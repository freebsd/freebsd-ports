--- libclamav/bignum_fast.h
+++ libclamav/bignum_fast.h
@@ -7,6 +7,14 @@
  * 
  * Tom St Denis, tomstdenis@gmail.com
  */
+
+/* Oct 1, 2013
+ * Adding clamav-config.h include here for size-checking on fall-through case
+ */
+#if HAVE_CONFIG_H
+#include "clamav-config.h"
+#endif
+
 #ifndef TFM_H_
 #define TFM_H_
 
@@ -249,7 +257,13 @@
       typedef signed long long   long64;
    #endif
 #endif
-   typedef unsigned long      fp_digit;
+   /* The code requires that fp_word be twice the size of fp_digit.
+    * Add size-checking for special case (both long and long long are 64) */
+   #if (SIZEOF_LONG == 8) && (SIZEOF_LONG_LONG == 8)
+      typedef unsigned int       fp_digit;
+   #else
+      typedef unsigned long      fp_digit;
+   #endif
    typedef ulong64            fp_word;
 #endif
 
