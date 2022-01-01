--- src/libm-tester/tester2simdsp.c.orig	2021-11-18 16:25:52 UTC
+++ src/libm-tester/tester2simdsp.c
@@ -828,7 +828,7 @@ int main(int argc,char **argv)
       double u0 = countULPsp(t = vget(xacoshf(vd), e), frx);
       
       if ((fabs(d) < sqrt(FLT_MAX) && u0 > 1.0001) ||
-	  (d >=  sqrt(FLT_MAX) && !(u0 <= 1.0001 || (isinff(t) && t > 0))) ||
+	  (d >=  sqrt(FLT_MAX) && !(u0 <= 1.0001 || (isinf(t) && t > 0))) ||
 	  (d <= -sqrt(FLT_MAX) && !isnan(t))) {
 	printf(ISANAME " acoshf arg=%.20g ulp=%.20g\n", d, u0);
 	fflush(stdout); ecnt++;
