--- linbox/ring/ntl/ntl-gf2e.h.orig	2022-07-28 02:52:14 UTC
+++ linbox/ring/ntl/ntl-gf2e.h
@@ -211,7 +211,7 @@ public :
                 _size(size), _seed(seed)
             {
                 if(_seed == 0)
-                    NTL::SetSeed(NTL::to_ZZ(time(0)));
+                    NTL::SetSeed(NTL::to_ZZ(static_cast<long unsigned int>(time(0))));
                 else
                     NTL::SetSeed(NTL::to_ZZ(static_cast<long unsigned int>(_seed)));
             }
@@ -221,7 +221,7 @@ public :
 
             {
                 if(_seed == 0)
-                    NTL::SetSeed(NTL::to_ZZ(time(0)));
+                    NTL::SetSeed(NTL::to_ZZ(static_cast<long unsigned int>(time(0))));
                 else
                     NTL::SetSeed(NTL::to_ZZ(static_cast<long unsigned int>(_seed)));
             }
