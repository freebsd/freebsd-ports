--- include/Ldokchitser.h.orig	2012-08-08 21:21:55 UTC
+++ include/Ldokchitser.h
@@ -1,3 +1,5 @@
+// Patches borrowed from SageMath.
+
 #ifndef Ldokchitser_H
 #define Ldokchitser_H
 
@@ -69,7 +71,7 @@ phi_series(int precision)
     
     // compute the values m[j] for the respective lambda_k[j]
     
-    Complex m[N+1];
+    std::vector<Complex> m(N+1);
     for (j=1;j<=N;j++)
     	m[j] = -2*lambda_k[j] + 2;
 	
@@ -78,7 +80,8 @@ phi_series(int precision)
 	
 	int n,fact_n;
 	Complex log_Gamma[N+1][a+1][MYDIGITS+1];
-	Complex sum_log_Gamma[N+1][MYDIGITS+1];
+        std::vector<std::vector<Complex> > sum_log_Gamma(N+1);
+        for (j=1;j<=N;j++) sum_log_Gamma[j].resize(MYDIGITS+1);
 	
 	for (j=1;j<=N;j++)
 	for (n=0;n<=MYDIGITS;n++)
@@ -103,8 +106,13 @@ phi_series(int precision)
 	
 	// compute the exponential taylor series for gamma = exp(sum_log_Gamma)
 	
-	Complex exp_sum_log_Gamma[N+1][MYDIGITS+1][MYDIGITS+1]; // symmetric functions
-	Complex gamma[N+1][MYDIGITS+1]; // gamma(s+m[j]) for j = 1 to N
+        std::vector<std::vector<std::vector<Complex> > > exp_sum_log_Gamma(N+1); // symmetric functions
+        std::vector<std::vector<Complex> > gamma(N+1); // gamma(s+m[j]) for j = 1 to N
+        for (j=1;j<=N;j++){
+            exp_sum_log_Gamma[j].resize(MYDIGITS+1);
+            gamma[j].resize(MYDIGITS+1);
+        }
+        for (j=1;j<=N;j++) for (n=0;n<=MYDIGITS;n++) exp_sum_log_Gamma[j][n].resize(MYDIGITS+1);
 	Complex temp_gamma[MYDIGITS+1];
 	Complex temp_mult_gamma[MYDIGITS+1];
 	Complex temp_exp_sum_log_Gamma[MYDIGITS+1];
