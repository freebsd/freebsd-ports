--- async/init.h.orig	Mon Oct 11 16:43:34 2004
+++ async/init.h	Mon Oct 11 16:39:35 2004
@@ -25,6 +25,12 @@
 #ifndef _ASYNC_INIT_H_
 #define _ASYNC_INIT_H_ 1
 
+#if __GNUC__ >= 3
+# define __init_attribute__(x)
+#else /* gcc < 3 */
+# define __init_attribute__(x) __attribute__ (x)
+#endif /* gcc < 3 */
+
 #define INIT(name)				\
 static class name {				\
   static int count;				\
@@ -34,7 +40,7 @@
 public:						\
   name () {if (!cnt ()++) start ();}		\
   ~name () {if (!--cnt ()) stop ();}		\
-} init_ ## name __attribute__ ((unused))
+} init_ ## name __init_attribute__ ((unused))
 
 class initfn {
   initfn ();
@@ -43,7 +49,7 @@
 };
 #define INITFN(fn)				\
 static void fn ();				\
-static initfn init_ ## fn (fn) __attribute__ ((unused))
+static initfn init_ ## fn (fn) __init_attribute__ ((unused))
 
 class exitfn {
   void (*const fn) ();
@@ -53,6 +59,6 @@
 };
 #define EXITFN(fn)					\
 static void fn ();					\
-static exitfn exit_ ## fn (fn) __attribute__ ((unused))
+static exitfn exit_ ## fn (fn) __init_attribute__ ((unused))
 
 #endif /* !_ASYNC_INIT_H_ */
