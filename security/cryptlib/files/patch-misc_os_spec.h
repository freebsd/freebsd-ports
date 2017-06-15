--- misc/os_spec.h.orig	2016-03-25 02:49:10.000000000 +0100
+++ misc/os_spec.h	2017-01-12 10:03:32.170180000 +0100
@@ -761,9 +761,8 @@
    variants, this presumably extends to SH5 as well so we treat va_lists on 
    Super-H as scalars */
 
-#if defined( __GNUC__ )
-  #if( defined( __ARM_EABI__ ) && \
-	   ( __GNUC__ == 4 && __GNUC_MINOR__ >= 4 ) || ( __GNUC__ > 4 ) )
+#if 1
+  #if defined( __ARM_EABI__ )
 	/* In theory we could check __ap but in practice it's too risky to rely 
 	   on the type and state of hidden internal fields, and in any case it's 
 	   only a sanity check, not a hard requirement, so we just no-op the 
@@ -839,7 +838,7 @@
 
 #if defined( __WINDOWS__ ) || \
 	( defined( __UNIX__ ) && \
-	  ( ( defined( sun ) && OSVERSION > 4 ) || defined( __linux__ ) || \
+	  ( ( defined( sun ) && OSVERSION > 4 ) || defined( __linux__ ) || defined(__FreeBSD__) || \
 		defined( _AIX ) || ( defined( __APPLE__ ) && !defined( __MAC__ ) ) ) ) || \
 	defined( __ANDROID__ )
   #define DYNAMIC_LOAD
