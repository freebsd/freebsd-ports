--- Metric.cpp.orig	Thu Dec 23 17:25:53 1999
+++ Metric.cpp	Fri Dec 19 09:38:12 2003
@@ -836,7 +836,7 @@
  
 }
 
-void Triangles::WriteMetric(ostream & f,int iso)
+void Triangles::WriteMetric(std::ostream & f,int iso)
 {
   if (iso)
     {
