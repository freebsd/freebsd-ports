--- test/certs.c.orig	2023-03-20 10:42:36 UTC
+++ test/certs.c
@@ -52,7 +52,7 @@
 #if defined( __MWERKS__ ) || defined( SYMANTEC_C ) || defined( __MRC__ )
   #define CERTTIME_DATETEST	( ( ( 2021 - 1970 ) * ONE_YEAR_TIME ) + 2082844800L )
 #else
-  #define CERTTIME_DATETEST	( ( 2021 - 1970 ) * ONE_YEAR_TIME )
+  #define CERTTIME_DATETEST	( ( 2023 - 1970 ) * ONE_YEAR_TIME )
 #endif /* Macintosh-specific weird epoch */
 #if ( ULONG_MAX > 0xFFFFFFFFUL ) || defined( _M_X64 )
   #define SYSTEM_64BIT
