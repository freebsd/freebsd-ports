--- linbox/ring/ntl/ntl-lzz_pex.h.orig	2022-07-28 02:52:14 UTC
+++ linbox/ring/ntl/ntl-lzz_pex.h
@@ -533,7 +533,7 @@ namespace LinBox
                 _size(size), _seed(seed), _ring(F)
             {
                 if(_seed == 0)
-                    NTL::SetSeed(NTL::to_ZZ(time(0)));
+                    NTL::SetSeed(NTL::to_ZZ(static_cast<long unsigned int>(time(0))));
                 else
                     NTL::SetSeed(NTL::to_ZZ(static_cast<long unsigned int>(_seed)));
             }
@@ -545,7 +545,7 @@ namespace LinBox
 
             {
                 if(_seed == 0)
-                    NTL::SetSeed(NTL::to_ZZ(time(0)));
+                    NTL::SetSeed(NTL::to_ZZ(static_cast<long unsigned int>(time(0))));
                 else
                     NTL::SetSeed(NTL::to_ZZ(static_cast<long unsigned int>(_seed)));
             }
