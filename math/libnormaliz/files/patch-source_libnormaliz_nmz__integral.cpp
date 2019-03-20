--- source/libnormaliz/nmz_integral.cpp.orig	2018-09-25 05:50:07 UTC
+++ source/libnormaliz/nmz_integral.cpp
@@ -403,7 +403,7 @@ try{
   vector<Integer> test_grading=C.getSublattice().to_sublattice_dual_no_div(C.getGrading());
   Integer corr_factor=v_gcd(test_grading);  
   mpz_class corr_mpz=convertTo<mpz_class>(corr_factor);
-  I*=BigInt(corr_mpz.get_mpz_t());  
+  I*=BigIntFromMPZ(corr_mpz.get_mpz_t());  
   
   string result="Integral";
   if(do_virt_mult)
