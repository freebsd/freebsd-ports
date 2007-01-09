--- src/inihf.f~	Tue May 17 02:22:50 2005
+++ src/inihf.f	Tue Jan  9 17:12:22 2007
@@ -20,6 +20,7 @@
       implicit integer*4 (i-n)
       implicit real*8 (a-h,o-z)
       character*8 atom1,term1,atom2,term2
+      integer ouf2dhf1, ouf2dhf2
       include 'commons8.inc'
       dimension psi(*),pot(*),excp(*),f2(*),f4(*),wgt2(*),wk0(*)
       dimension rhf1(9999),phf1(20,9999),ehf1(20),qc1(20),
