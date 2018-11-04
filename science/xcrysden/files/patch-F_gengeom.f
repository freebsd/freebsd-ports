Temporary fix for gcc8 breakage: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=232960

--- F/gengeom.f.orig	2018-11-04 17:34:02 UTC
+++ F/gengeom.f
@@ -674,7 +674,7 @@ c      print *,'READFTN34_END'
       include 'param.inc'
       CHARACTER*80 FILE2
       INTEGER NAT(NAC)
-      REAL*8 AC(3,2),BC(3,2),CC(3,2),FC(3,4),IC(3,2),RC(3,3),HC(3,3),
+      REAL*8 AC(3,4),BC(3,4),CC(3,4),FC(3,4),IC(3,4),RC(3,4),HC(3,4),
      $     CSTMC(3,4),
      *     DVC(3,3),SOP(3,3,48),TRX(48),TRY(48),TRZ(48),
      *     XC(NAC,4),YC(NAC,4),ZC(NAC,4),
