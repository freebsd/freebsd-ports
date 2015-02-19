--- misc/os_spec.h.orig	2011-08-02 23:52:50.000000000 +0000
+++ misc/os_spec.h	2015-02-19 11:32:33.126607217 +0000
@@ -606,9 +606,7 @@
    support for the change was added in gcc 4.4, so any newer version with 
    ARM_EABI defined will have a scalar va_list */
 
-#if defined( __GNUC__ ) && \
-	( ( __GNUC__ == 4 && __GNUC_MINOR__ >= 4 ) || ( __GNUC__ > 4 ) ) && \
-	defined( __ARM_EABI__ )
+#if defined( __ARM_EABI__ )
 	/* In theory we could check __ap but in practice it's too risky to rely 
 	   on the type and state of hidden internal fields, and in any case it's 
 	   only a sanity check, not a hard requirement, so we just no-op the 
@@ -666,7 +664,7 @@
 
 #if defined( __WINDOWS__ ) || \
 	( defined( __UNIX__ ) && \
-	  ( ( defined( sun ) && OSVERSION > 4 ) || defined( __linux__ ) || \
+	  ( ( defined( sun ) && OSVERSION > 4 ) || defined( __linux__ ) || defined(__FreeBSD__) || \
 		defined( _AIX ) || ( defined( __APPLE__ ) && !defined( __MAC__ ) ) ) )
   #define DYNAMIC_LOAD
 
