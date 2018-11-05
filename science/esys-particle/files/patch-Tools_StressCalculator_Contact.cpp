--- Tools/StressCalculator/Contact.cpp.orig	2018-11-05 04:44:17 UTC
+++ Tools/StressCalculator/Contact.cpp
@@ -18,7 +18,7 @@ namespace esys
   namespace lsm
   {
     bool ParticleData::s_is3d = true;
-    const double ParticleData::FOUR_THIRDS_PI = ((4.0/3.0)*M_PIl);
+    const double ParticleData::FOUR_THIRDS_PI = ((4.0/3.0)*M_PI);
   }
 }
 
