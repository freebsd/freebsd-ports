--- gsl_sf.cc.orig	2021-02-21 21:41:43 UTC
+++ gsl_sf.cc
@@ -26,11 +26,7 @@
 #include <gsl/gsl_errno.h>
 #include <gsl/gsl_version.h>
 
-#ifdef OCTAVE_HAS_OV_ISREAL_METHOD
 #define ISREAL(x) ((x).isreal ())
-#else
-#define ISREAL(x) ((x).is_real_type ())
-#endif
 
 void octave_gsl_errorhandler (const char * reason, const char * file,
 			      int line, int gsl_errno)
@@ -47,11 +43,7 @@ special functions of the GNU Scientific Library (GSL).
 \n\
 @end deftypefn\n")
 {
-#ifdef OCTAVE_HAS_FEVAL_IN_OCTAVE_NAMESPACE
   octave::feval ("help", octave_value ("gsl_sf"));
-#else
-  feval ("help", octave_value ("gsl_sf"));
-#endif
 
   return octave_value();
 }
