--- turb/turb.mk.orig	Fri Jun  8 04:24:24 2001
+++ turb/turb.mk	Sun Dec 26 21:25:24 2004
@@ -1,4 +1,4 @@
-MAKE=make
+MAKE?=gmake
 
 SRC=  $(HOME)/ISAAC/src
 TURB= $(SRC)/turb
