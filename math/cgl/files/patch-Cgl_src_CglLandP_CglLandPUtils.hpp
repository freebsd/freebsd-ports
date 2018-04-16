--- Cgl/src/CglLandP/CglLandPUtils.hpp.orig	2018-04-16 07:09:23 UTC
+++ Cgl/src/CglLandP/CglLandPUtils.hpp
@@ -85,7 +85,7 @@ struct Cuts
     /** resize vector.*/
     void resize(unsigned int i)
     {
-        cuts_.resize(i, reinterpret_cast<OsiRowCut *> (NULL));
+        cuts_.resize(i, nullptr); // workaround for clang-6
     }
 private:
     /** Stores the number of cuts.*/
