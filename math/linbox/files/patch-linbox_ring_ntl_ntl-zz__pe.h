--- linbox/ring/ntl/ntl-zz_pe.h.orig	2022-07-28 02:52:14 UTC
+++ linbox/ring/ntl/ntl-zz_pe.h
@@ -385,7 +385,7 @@ namespace LinBox
                 _size(size), _seed(seed), _ring(F)
 		{
 			if(_seed == 0)
-				NTL::SetSeed(NTL::to_ZZ(time(0)));
+				NTL::SetSeed(NTL::to_ZZ(static_cast<long>(time(0))));
 			else {
 				NTL::ZZ x;
 				std::stringstream s;
@@ -414,7 +414,7 @@ namespace LinBox
 
 		{
 			if(_seed == 0)
-				NTL::SetSeed(NTL::to_ZZ(time(0)));
+				NTL::SetSeed(NTL::to_ZZ( static_cast<long>(time(0))));
 			else
 				NTL::SetSeed(NTL::to_ZZ( static_cast<long>(_seed)) );
 		}
