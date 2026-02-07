--- src/dana_aux.F.orig	2020-10-23 09:16:48 UTC
+++ src/dana_aux.F
@@ -3008,7 +3008,7 @@ C
      &  write(MPG,'(A,1I5)') 
      &  ' Average density of rows/columns =', AvgDens
         IF (MP.GT.0 .AND. MPG.NE.MP.AND.(ICNTL(4).GE.2))
-     &  write(MPG,'(A,1I5)') 
+     &  write(MP,'(A,1I5)') 
      &  ' Average density of rows/columns =', AvgDens
       RETURN
 99999 FORMAT (/'*** Warning message from analysis routine ***')
