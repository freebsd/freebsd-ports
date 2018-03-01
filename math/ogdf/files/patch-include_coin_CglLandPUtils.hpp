In file included from CglLandPSimplex.cpp:11:
In file included from ./CglLandPSimplex.hpp:31:
./CglLandPUtils.hpp:88:25: error: reinterpret_cast from 'nullptr_t' to 'OsiRowCut *' is not allowed
        cuts_.resize(i, reinterpret_cast<OsiRowCut *> (NULL));
                        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- include/coin/CglLandPUtils.hpp.orig	2015-05-29 15:36:11 UTC
+++ include/coin/CglLandPUtils.hpp
@@ -85,7 +85,7 @@ struct Cuts
     /** resize vector.*/
     void resize(unsigned int i)
     {
-        cuts_.resize(i, reinterpret_cast<OsiRowCut *> (NULL));
+        cuts_.resize(i, static_cast<OsiRowCut *> (NULL));
     }
 private:
     /** Stores the number of cuts.*/
