--- include/vlc_atomic.h.orig	2014-08-14 07:20:03 UTC
+++ include/vlc_atomic.h
@@ -32,6 +32,14 @@
 /*** Native C11 atomics ***/
 #  include <stdatomic.h>
 
+# elif defined (__cplusplus) && defined(_LIBCPP_VERSION) && _LIBCPP_VERSION >= 3800
+
+#  include <atomic>
+
+using std::atomic_uint_least32_t;
+using std::atomic_uintptr_t;
+using std::atomic_int;
+
 # else
 
 #  define ATOMIC_FLAG_INIT false
