$FreeBSD$

--- gms-files.csh	2013-03-05 18:04:02.000000000 +0900
+++ gms-files.csh	2013-03-05 18:05:38.000000000 +0900
@@ -28,7 +28,7 @@
 #     to see all the file definitions (one is just below).
 #
 #---quiet---set echo
-setenv AUXDATA $GMSPATH/auxdata
+setenv AUXDATA %%PREFIX%%/share/gamess/auxdata
 setenv  EXTBAS /dev/null
 setenv  NUCBAS /dev/null
 setenv  POSBAS /dev/null
