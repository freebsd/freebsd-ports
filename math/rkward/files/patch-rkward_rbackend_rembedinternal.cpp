--- rkward/rbackend/rembedinternal.cpp.orig	2008-04-10 09:19:08.000000000 -0400
+++ rkward/rbackend/rembedinternal.cpp	2013-05-28 07:06:41.000000000 -0400
@@ -87,7 +87,9 @@
 #include "R.h"
 #include "Rinternals.h"
 #include "Rinterface.h"
-#include "Rdevices.h"
+#if (R_VERSION < R_Version(2, 8, 1))
+# include "Rdevices.h"
+#endif
 #include "R_ext/Parse.h"
 
 #ifdef R_2_4
@@ -118,7 +120,9 @@
 
 // some functions we need that are not declared
 extern int Rf_initEmbeddedR(int argc, char **argv);
+#if (R_VERSION < R_Version(3,0,0))
 extern void Rf_PrintWarnings (void);
+#endif
 extern int R_interrupts_pending;
 #ifdef R_2_3
 extern int Rf_initialize_R(int ac, char **av);
@@ -839,6 +843,7 @@
 
 	UNPROTECT(1); /* pr */
 
+#if (R_VERSION < R_Version(3,0,0))
 	// for safety, let's protect exp for the two print calls below.
 	// TODO: this is not good. It causes an additional PROTECT and UPROTECT. Need to (re-)move printing
 	PROTECT (exp);
@@ -849,6 +854,7 @@
 	Rf_PrintWarnings ();
 
 	UNPROTECT (1);		// exp; We unprotect this, as most of the time the caller is not really interested in the result
+#endif
 	return exp;
 }
 
