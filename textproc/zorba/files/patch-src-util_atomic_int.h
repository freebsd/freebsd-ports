--- src/util/atomic_int.h.orig	2011-09-15 10:09:31.000000000 +0200
+++ src/util/atomic_int.h	2011-09-15 11:15:19.000000000 +0200
@@ -27,7 +27,10 @@
 // Test first for and prefer gcc's atomic operations over all others since
 // they're an order of magnitude faster.
 //
-#if defined( __GNUC__ )
+#if defined( __FreeBSD__ )
+# include <sys/types.h>
+# include <machine/atomic.h>
+#elif defined( __GNUC__ )
 # if __GNUC__ * 100 + __GNUC_MINOR__ >= 402
 #   include <ext/atomicity.h>
 # else
@@ -40,9 +43,6 @@
 # endif
 #elif defined( __APPLE__ )
 # include <libkern/OSAtomic.h>
-#elif defined( __FreeBSD__ )
-# include <sys/types.h>
-# include <machine/atomic.h>
 #elif defined( __NetBSD__ )
 # include <sys/atomic.h>
 #elif defined( __SOLARIS__ )
@@ -66,12 +66,12 @@
  */
 class atomic_int {
 public:
-#if defined( __GNUC__ )
+#if defined( __FreeBSD__ )
+  typedef int value_type;
+#elif defined( __GNUC__ )
   typedef _Atomic_word value_type;
 #elif defined( __APPLE__ ) || defined( __NetBSD__ ) || defined( __SOLARIS__ )
   typedef int32_t value_type;
-#elif defined( __FreeBSD__ )
-  typedef int value_type;
 #elif defined( _WIN32 )
   typedef LONG value_type;
 #endif
@@ -172,7 +172,7 @@
 
   value_type load_impl() const {
 #if defined( __FreeBSD__ )
-    return atomic_load_acq_int( &value_ );
+    return atomic_load_acq_int( (volatile u_int *)&value_ );
 #else
     value_type const temp = *(value_type volatile*)&value_;
 # if defined( __GNUC__ )
@@ -192,7 +192,7 @@
 
   void store_impl( value_type n ) {
 #if defined( __FreeBSD__ )
-    atomic_store_rel_int( &value_, n );
+    atomic_store_rel_int( (volatile u_int *)&value_, n );
 #elif defined( _WIN32 )
     InterlockedExchange( &value_, n );
 #else
@@ -210,12 +210,12 @@
   }
 
   value_type add( value_type n ) {
-#if defined( __GNUC__ )
+#if defined( __FreeBSD__ )
+    return atomic_fetchadd_int( (volatile u_int*)&value_, n ) + n;
+#elif defined( __GNUC__ )
     return GNU_EXCHANGE_AND_ADD( &value_, n ) + n;
 #elif defined( __APPLE__ )
     return OSAtomicAdd32( n, &value_ );
-#elif defined( __FreeBSD__ )
-    return atomic_fetchadd_int( &value_, n ) + n;
 #elif defined( __NetBSD__ )
     return (value_type)atomic_add_32_nv( (uint32_t*)&value_, n );
 #elif defined( __SOLARIS__ )
@@ -226,12 +226,12 @@
   }
 
   value_type pre_dec() {
-#if defined( __GNUC__ )
+#if defined( __FreeBSD__ )
+    return atomic_fetchadd_int( (volatile u_int *)&value_, -1 ) - 1;
+#elif defined( __GNUC__ )
     return GNU_EXCHANGE_AND_ADD( &value_, -1 ) - 1;
 #elif defined( __APPLE__ )
     return OSAtomicDecrement32( &value_ );
-#elif defined( __FreeBSD__ )
-    return atomic_fetchadd_int( &value_, -1 ) - 1;
 #elif defined( __NetBSD__ )
     return (value_type)atomic_add_int_nv( (uint32_t*)&value_, -1 );
 #elif defined( __SOLARIS__ )
@@ -242,12 +242,12 @@
   }
 
   value_type pre_inc() {
-#if defined( __GNUC__ )
+#if defined( __FreeBSD__ )
+    return atomic_fetchadd_int( (volatile u_int *)&value_, 1 ) + 1;
+#elif defined( __GNUC__ )
     return GNU_EXCHANGE_AND_ADD( &value_, 1 ) + 1;
 #elif defined( __APPLE__ )
     return OSAtomicIncrement32( &value_ );
-#elif defined( __FreeBSD__ )
-    return atomic_fetchadd_int( &value_, 1 ) + 1;
 #elif defined( __NetBSD__ )
     return (value_type)atomic_add_int_nv( (uint32_t*)&value_, 1 );
 #elif defined( __SOLARIS__ )
@@ -258,12 +258,12 @@
   }
 
   value_type post_dec() {
-#if defined( __GNUC__ )
+#if defined( __FreeBSD__ )
+    return atomic_fetchadd_int( (volatile u_int *)&value_, -1 );
+#elif defined( __GNUC__ )
     return GNU_EXCHANGE_AND_ADD( &value_, -1 );
 #elif defined( __APPLE__ )
     return OSAtomicDecrement32( &value_ ) + 1;
-#elif defined( __FreeBSD__ )
-    return atomic_fetchadd_int( &value_, -1 );
 #elif defined( __NetBSD__ )
     return (value_type)atomic_add_int_nv( (uint32_t*)&value_, -1 ) + 1;
 #elif defined( __SOLARIS__ )
@@ -274,12 +274,12 @@
   }
 
   value_type post_inc() {
-#if defined( __GNUC__ )
+#if defined( __FreeBSD__ )
+    return atomic_fetchadd_int( (volatile u_int *)&value_, 1 );
+#elif defined( __GNUC__ )
     return GNU_EXCHANGE_AND_ADD( &value_, 1 );
 #elif defined( __APPLE__ )
     return OSAtomicIncrement32( &value_ ) - 1;
-#elif defined( __FreeBSD__ )
-    return atomic_fetchadd_int( &value_, 1 );
 #elif defined( __NetBSD__ )
     return (value_type)atomic_add_int_nv( (uint32_t*)&value_, 1 ) - 1;
 #elif defined( __SOLARIS__ )
