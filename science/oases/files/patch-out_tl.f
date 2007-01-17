--- plot/out_tl.f~	Fri Feb 11 06:06:07 2000
+++ plot/out_tl.f	Wed Jan 17 14:00:05 2007
@@ -16,7 +16,7 @@
   240 FORMAT(6(1X,E12.5))
 
       IF(IC.EQ.1 .AND. IFLG13 .EQ. 0)   THEN
-        OPEN(13,STATUS='NEW',FORM='FORMATTED')
+        OPEN(13,STATUS='NEW',FILE='OUT13',FORM='FORMATTED')
         WRITE(13,150) HTXT
         DELX=AX(2)-AX(1)
         READ(LAB(1),140) FREQ
