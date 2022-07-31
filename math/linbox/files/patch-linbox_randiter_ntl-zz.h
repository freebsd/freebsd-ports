--- linbox/randiter/ntl-zz.h.orig	2022-07-28 02:25:12 UTC
+++ linbox/randiter/ntl-zz.h
@@ -44,7 +44,7 @@ namespace LinBox
 
 			_size = NTL::to_ZZ(std::string(size).data());
 
-			if (seed == integer(0)) NTL::SetSeed (NTL::to_ZZ(time(NULL)));
+			if (seed == integer(0)) NTL::SetSeed (NTL::to_ZZ(static_cast<long>(time(NULL))));
 
 			else NTL::SetSeed(NTL::to_ZZ(std::string(seed).data()));
 		}
