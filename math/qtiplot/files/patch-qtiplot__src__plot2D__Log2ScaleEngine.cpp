--- ./qtiplot/src/plot2D/Log2ScaleEngine.cpp.orig	2009-10-18 10:44:49.000000000 +0400
+++ ./qtiplot/src/plot2D/Log2ScaleEngine.cpp	2009-10-18 18:54:12.000000000 +0400
@@ -160,8 +160,8 @@
     if ( numTicks > 10000 )
         numTicks = 10000;
 
-    const double lxmin = ::log2(interval.minValue());
-    const double lxmax = ::log2(interval.maxValue());
+    const double lxmin = ::log(interval.minValue())*M_LOG2E;
+    const double lxmax = ::log(interval.maxValue())*M_LOG2E;
     const double lstep = (lxmax - lxmin) / double(numTicks - 1);
 
     QwtValueList ticks;
@@ -224,6 +224,6 @@
 QwtDoubleInterval Log2ScaleEngine::log2(
     const QwtDoubleInterval &interval) const
 {
-    return QwtDoubleInterval(::log2(interval.minValue()),
-            ::log2(interval.maxValue()));
+    return QwtDoubleInterval(::log(interval.minValue())*M_LOG2E,
+            ::log(interval.maxValue())*M_LOG2E);
 }
