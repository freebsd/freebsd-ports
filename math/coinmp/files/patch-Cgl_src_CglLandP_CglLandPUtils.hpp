In file included from CglLandPSimplex.cpp:11:
In file included from ./CglLandPSimplex.hpp:31:
./CglLandPUtils.hpp:88:25: error: reinterpret_cast from 'nullptr_t' to 'OsiRowCut *' is not allowed
        cuts_.resize(i, reinterpret_cast<OsiRowCut *> (NULL));
                        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- Cgl/src/CglLandP/CglLandPUtils.hpp.orig	2013-04-06 20:39:53 UTC
+++ Cgl/src/CglLandP/CglLandPUtils.hpp
@@ -85,7 +85,7 @@ struct Cuts
     /** resize vector.*/
     void resize(unsigned int i)
     {
-        cuts_.resize(i, reinterpret_cast<OsiRowCut *> (NULL));
+        cuts_.resize(i, static_cast<OsiRowCut *> (NULL));
     }
 private:
     /** Stores the number of cuts.*/
