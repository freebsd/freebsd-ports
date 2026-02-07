--- interfaces/blas/C/testing/c_dblat1.f.orig	2016-07-28 19:43:02 UTC
+++ interfaces/blas/C/testing/c_dblat1.f
@@ -247,11 +247,11 @@
             IF (ICASE.EQ.7) THEN
 *              .. DNRM2TEST ..
                STEMP(1) = DTRUE1(NP1)
-               CALL STEST1(DNRM2TEST(N,SX,INCX),STEMP,STEMP,SFAC)
+               CALL STEST1(DNRM2TEST(N,SX,INCX),STEMP(1),STEMP,SFAC)
             ELSE IF (ICASE.EQ.8) THEN
 *              .. DASUMTEST ..
                STEMP(1) = DTRUE3(NP1)
-               CALL STEST1(DASUMTEST(N,SX,INCX),STEMP,STEMP,SFAC)
+               CALL STEST1(DASUMTEST(N,SX,INCX),STEMP(1),STEMP,SFAC)
             ELSE IF (ICASE.EQ.9) THEN
 *              .. DSCALTEST ..
                CALL DSCALTEST(N,SA((INCX-1)*5+NP1),SX,INCX)
