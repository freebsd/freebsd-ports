--- src/condor_power/power_state.cpp.orig	2015-04-07 15:10:11 UTC
+++ src/condor_power/power_state.cpp
@@ -57,7 +57,8 @@ enum
 	E_ARGCNT  = -6,  /* too few/many arguments */
 	E_NOREST  = -7,  /* failed to switch the machine's power state */
 	E_CLASSAD = -8,  /* error in class-ad (errno = %d) */
-	E_UNKNOWN = -9   /* unknown error */
+	E_UNSUPPORTED = -9, /* OS not supported */
+	E_UNKNOWN = -10   /* unknown error */
 };
 
 /**	Error messages */
@@ -72,7 +73,8 @@ static const char *errmsgs[] = {
   /* E_ARGCNT   -6 */  "wrong number of arguments.\n",
   /* E_NOREST   -7 */  "failed to switch the machine's power state.\n",
   /* E_CLASSAD  -8 */  "error in class-ad (errno = %d).\n",
-  /* E_UNKNOWN  -9 */  "unknown error.\n"
+  /* E_UNSUPPORTED = -9 */ "condor_power() not implemented for this OS.\n",
+  /* E_UNKNOWN  -10 */  "unknown error.\n"
 };
 
 /**	Typedefs */
@@ -257,6 +259,8 @@ main( int argc, const char *argv[] )
 	/**	Create the hibernation mechanism. */
 # if ( HIBERNATOR_TYPE_DEFINED )
 	hibernator = new RealHibernator;
+# else
+	error( E_UNSUPPORTED );
 # endif
 	if ( !hibernator ) {
 		error( E_NOMEM, "hibernator object." );
