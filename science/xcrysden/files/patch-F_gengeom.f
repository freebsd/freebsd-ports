Temporary fix for gcc8 breakage: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=232960
Source: http://www.democritos.it/pipermail/xcrysden/2018-October/001929.html

--- F/gengeom.f 2012-02-03 11:53:05.000000000 +0100
+++ F/gengeom.f 2018-10-30 08:58:33.624408287 +0100
@@ -905,9 +905,9 @@

       SUBROUTINE GETCCOOR(A33,B33,BROW,X,Y,Z,XC,YC,ZC,NA,NATR)
       include 'param.inc'
-      REAL*8 B33(3,4),A33(3,3),RA(3,3),COOR(3),X(NATR),Y(NATR),Z(NATR),
-     *     XC(NAC,4),YC(NAC,4),ZC(NAC,4),RX(3)
       INTEGER BROW
+      REAL*8 B33(3,BROW),A33(3,3),RA(3,3),COOR(3),X(NATR),Y(NATR),
+     *     Z(NATR),XC(NAC,4),YC(NAC,4),ZC(NAC,4),RX(3)

 C     ********
 C     ATTENTION: HERE WE HAVE MULT. OFF "SAME-LAYING" ELEMENTS,
