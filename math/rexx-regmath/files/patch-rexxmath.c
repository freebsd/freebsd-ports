--- rexxmath.c.orig	2001-11-04 21:51:10 UTC
+++ rexxmath.c
@@ -19,7 +19,7 @@
 static double cotan(const double arg);
 static double csc(const double arg);
 static double sec(const double arg);
-static double round(const double arg);
+static double xround(const double arg);
 
 #if defined(__EMX__) || defined(_WIN32)
 static double acosh(double arg);
@@ -48,7 +48,7 @@ static struct funclist {
     "ln", log,		/* Log base e ln(x) log x > 0.0 */
     "log", log,		/* Log base e ln(x) log x > 0.0 */
     "log10", log10,	/* Log base 10 log10(x) x > 0.0  */
-    "nint", round,      /* nearest integer */
+    "nint", xround,      /* nearest integer */
     "sec", sec,         /* secant */
     "sin", sin,         /* sine */
     "sinh", sinh,       /* hyperbolic sine */
@@ -70,7 +70,7 @@ rxfunc(mathfunc1)
 
     checkparam(1,1);
     
-    afunc.name = fname;
+    afunc.name = (char *) fname;
     theFunc = (struct funclist *)bsearch(&afunc, mathfuncs,DIM(mathfuncs)
                , sizeof(*theFunc), findmathfunc);
 
@@ -158,7 +158,7 @@ rxfunc(mathfact)
 }
 
 /* Nearest integer to x      nint(x) */
-static double round(const double arg)
+static double xround(const double arg)
 {
    return floor(arg+.5);
 }
