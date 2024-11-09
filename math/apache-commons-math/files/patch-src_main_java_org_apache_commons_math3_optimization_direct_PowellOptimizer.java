BROKEN_armv7=	fails to compile: PowellOptimizer.java:301: error: Illegal static declaration in inner class PowellOptimizer.LineSearch

--- src/main/java/org/apache/commons/math3/optimization/direct/PowellOptimizer.java.orig	2024-10-24 09:29:04 UTC
+++ src/main/java/org/apache/commons/math3/optimization/direct/PowellOptimizer.java
@@ -297,7 +297,7 @@ public class PowellOptimizer
          * but will not pass the convergence check, so that the custom checker
          * will always decide when to stop the line search.
          */
-        private static final double ABS_TOL_UNUSED = Double.MIN_VALUE;
+//      private static final double ABS_TOL_UNUSED = Double.MIN_VALUE;
         /**
          * Automatic bracketing.
          */
@@ -314,7 +314,7 @@ public class PowellOptimizer
         LineSearch(double rel,
                    double abs) {
             super(REL_TOL_UNUSED,
-                  ABS_TOL_UNUSED,
+                  /* ABS_TOL_UNUSED */ Double.MIN_VALUE,
                   new SimpleUnivariateValueChecker(rel, abs));
         }
 
