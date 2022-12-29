--- interfaces/blas/C/testing/c_sblat1.f.orig	2016-07-28 19:43:02 UTC
+++ interfaces/blas/C/testing/c_sblat1.f
@@ -247,11 +247,11 @@
             IF (ICASE.EQ.7) THEN
 *              .. SNRM2TEST ..
                STEMP(1) = DTRUE1(NP1)
-               CALL STEST1(SNRM2TEST(N,SX,INCX),STEMP,STEMP,SFAC)
+               CALL STEST1(SNRM2TEST(N,SX,INCX),STEMP(1),STEMP,SFAC)
             ELSE IF (ICASE.EQ.8) THEN
 *              .. SASUMTEST ..
                STEMP(1) = DTRUE3(NP1)
-               CALL STEST1(SASUMTEST(N,SX,INCX),STEMP,STEMP,SFAC)
+               CALL STEST1(SASUMTEST(N,SX,INCX),STEMP(1),STEMP,SFAC)
             ELSE IF (ICASE.EQ.9) THEN
 *              .. SSCALTEST ..
                CALL SSCALTEST(N,SA((INCX-1)*5+NP1),SX,INCX)
