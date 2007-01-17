IDATE and ITIME are intrinsic
--- mindis/mindis6.f~	Wed May 10 05:48:07 2000
+++ mindis/mindis6.f	Wed Jan 17 14:02:18 2007
@@ -57,7 +57,6 @@
 C     ***Routine to return date and time in Ascii
       CHARACTER*(*) PDATE, PTIME
       INTEGER II(3)
-      EXTERNAL IDATE,ITIME
       CALL IDATE(II)
       WRITE(PDATE,100) II(2),II(1),MOD(II(3),100)
       CALL ITIME(II)
