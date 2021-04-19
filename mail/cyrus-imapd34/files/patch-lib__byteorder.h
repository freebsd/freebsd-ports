--- lib/byteorder.h.orig	2021-01-07 01:26:49 UTC
+++ lib/byteorder.h
@@ -61,7 +61,12 @@
 #  define ntohll(x) (x)
 
 #else /* small-endian machines */
-#  if defined(__GNUC__) && __GNUC_PREREQ(4, 3)
+#  if defined(__GNUC__) && !defined(__clang__)
+#    if __GNUC_PREREQ(4, 3)
+#      define GNUC_PREREQ_4_3 1
+#    endif
+#  endif
+#  if defined(GNUC_PREREQ_4_3)
      /* Remove existing macros if present */
 #    undef ntohl
 #    undef htonl
