--- src/sim/cstat.cc.orig	2006-10-21 16:44:55.000000000 +0200
+++ src/sim/cstat.cc	2008-04-06 14:42:30.000000000 +0200
@@ -370,8 +370,31 @@
 
 void cWeightedStdDev::collect2(double val, double weight)
 {
-    cStdDev::collect(weight*val);
+    // Lars Westerhoff: collect weight*val*val for sqrsum_samples for variance
+
+    if (++num_samples <= 0)
+    {
+        // FIXME: num_samples overflow: issue warning and must stop collecting!
+        ev.printf("\a\nWARNING: (%s)%s: observation count overflow!\n\n",className(),fullPath());
+    }
+    sum_samples+=weight*val;
+    sqrsum_samples+=weight*val*val;
     sum_weights += weight;
+
+    if (num_samples>1)
+    {
+        if (val<min_samples)
+            min_samples=val;
+        else if (val>max_samples)
+            max_samples=val;
+    }
+    else
+    {
+        min_samples=max_samples=val;
+    }
+
+    if (transientDetectionObject()) td->collect(val);  //NL
+    if (accuracyDetectionObject()) ra->collect(val);   //NL
 }
 
 void cWeightedStdDev::clearResult()
@@ -382,18 +405,18 @@
 
 double cWeightedStdDev::variance() const
 {
-    throw new cRuntimeError(this, "variance()/stddev() not implemented");
+    // Lars Westerhoff
-
-    // if (sum_weights==0)
-    //   return 0.0;
-    // else
-    // {
-    //   double devsqr = (sqrsum_samples - sum_samples*sum_samples/sum_weights)/(sum_weights-1);
-    //   if (devsqr<=0)
-    //       return 0.0;
-    //   else
-    //       return devsqr;
-    //}
+
+    if (sum_weights==0)
+        return 0.0;
+    else
+    {
+        double devsqr = (sqrsum_samples - sum_samples*sum_samples/sum_weights)/(sum_weights); // sum_weights-1 ???
+        if (devsqr<=0)
+            return 0.0;
+        else
+            return devsqr;
+   }
 }
 
 void cWeightedStdDev::saveToFile(FILE *f) const
