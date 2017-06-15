Move vlc_atomic.h closer to the git version (post-2.2.4), especially revision
ab550d60dd8d8 ("include: stick to a single version (2011) C/C++ atomics") by
assuming C++ builds are being done in C++11 mode or later and include <atomic>.
For C usages, use <stdatomic.h> in C11 mode and define some shims otherwise.

The original 2.2.4 version does not have C++11 support and breaks with Qt5, as
Qt 5.7+ requires C++11 support.
--- include/vlc_atomic.h.orig	2014-08-14 07:20:03 UTC
+++ include/vlc_atomic.h
@@ -26,13 +26,13 @@
  * Atomic operations do not require locking, but they are not very powerful.
  */
 
-# if !defined (__cplusplus) && (__STDC_VERSION__ >= 201112L) \
-  && !defined (__STDC_NO_ATOMICS__)
+# ifndef __cplusplus
+#  if (__STDC_VERSION__ >= 201112L) && !defined (__STDC_NO_ATOMICS__)
 
 /*** Native C11 atomics ***/
 #  include <stdatomic.h>
 
-# else
+#  else
 
 #  define ATOMIC_FLAG_INIT false
 
@@ -57,7 +57,7 @@
  * unsigned equivalents, i.e. 4-bytes and 8-bytes types, although GCC also
  * supports 1 and 2-bytes types. Some non-x86 architectures do not support
  * 8-byte atomic types (or not efficiently). */
-#  if defined (_MSC_VER)
+#   if defined (_MSC_VER)
 /* Some atomic operations of the Interlocked API are only
    available for desktop apps. Thus we define the atomic types to
    be at least 32 bits wide. */
@@ -68,7 +68,7 @@
 typedef     uint_least32_t atomic_uchar;
 typedef      int_least32_t atomic_short;
 typedef     uint_least32_t atomic_ushort;
-#  else
+#   else
 typedef          bool      atomic_flag;
 typedef          bool      atomic_bool;
 typedef          char      atomic_char;
@@ -76,7 +76,7 @@
 typedef unsigned char      atomic_uchar;
 typedef          short     atomic_short;
 typedef unsigned short     atomic_ushort;
-#  endif
+#   endif
 typedef          int       atomic_int;
 typedef unsigned int       atomic_uint;
 typedef          long      atomic_long;
@@ -109,7 +109,7 @@
 typedef          intmax_t atomic_intmax_t;
 typedef         uintmax_t atomic_uintmax_t;
 
-# if defined (__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4) || (defined (__clang__) && (defined (__x86_64__) || defined (__i386__)))
+#   if defined (__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4) || (defined (__clang__) && (defined (__x86_64__) || defined (__i386__)))
 
 /*** Intel/GCC atomics ***/
 
@@ -203,7 +203,7 @@
 #  define atomic_flag_clear_explicit(object,order) \
     atomic_flag_clear(object)
 
-# elif defined (__GNUC__)
+#   elif defined (__GNUC__)
 
 /*** No atomics ***/
 
@@ -315,7 +315,7 @@
 #  define atomic_flag_clear_explicit(object,order) \
     atomic_flag_clear(object)
 
-# elif defined (_MSC_VER)
+#   elif defined (_MSC_VER)
 
 # include <windows.h>
 
@@ -397,10 +397,8 @@
 #  define atomic_flag_clear_explicit(object,order) \
     atomic_flag_clear(object)
 
-# else
-#  error FIXME: implement atomic operations for this compiler.
-# endif
-# endif
+#   endif
+#  endif
 
 typedef atomic_uint_least32_t vlc_atomic_float;
 
@@ -427,4 +425,9 @@
     atomic_store(atom, u.i);
 }
 
+# else /* C++ */
+/*** Native C++11 atomics ***/
+#  include <atomic>
+# endif
+
 #endif
