--- include/haproxy/atomic.h.orig	2018-02-17 18:17:22.219400000 +0000
+++ include/haproxy/atomic.h	2018-02-17 18:18:44.598422000 +0000
@@ -104,7 +104,7 @@ extern THREAD_LOCAL unsigned long tid_bit; /* The bit 
 /* TODO: thread: For now, we rely on GCC builtins but it could be a good idea to
  * have a header file regrouping all functions dealing with threads. */
 
-#if defined(__GNUC__) && (__GNUC__ < 4 || __GNUC__ == 4 && __GNUC_MINOR__ < 7) && !defined(__clang__)
+#if (defined(__GNUC__) && (__GNUC__ < 4 || __GNUC__ == 4 && __GNUC_MINOR__ < 7) && !defined(__clang__)) || (defined(__clang__) && defined(__i386__))
 /* gcc < 4.7 */
 
 #define HA_ATOMIC_ADD(val, i)        __sync_add_and_fetch(val, i)
