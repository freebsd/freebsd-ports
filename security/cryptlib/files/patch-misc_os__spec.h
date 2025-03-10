--- misc/os_spec.h.orig	2023-02-10 20:29:06 UTC
+++ misc/os_spec.h
@@ -607,9 +607,8 @@ typedef int					BOOLEAN_INT;
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
