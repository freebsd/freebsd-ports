--- make.inc.orig	Sun Jan  1 18:52:00 2006
+++ make.inc	Sat Feb  4 19:25:37 2006
@@ -29,12 +29,12 @@
 ARCHFLAGS    = cr
 RANLIB       = ranlib
 
-CC           = cc
-CFLAGS       = -xO3 -xcg92
-FORTRAN	     = f77
-FFLAGS       = -O
-LOADER       = cc
-LOADOPTS     = -xO3
+CC           = %%CC%%
+CFLAGS       = %%CFLAGS%%
+FORTRAN	     = %%FC%%
+FFLAGS       = %%FFLAGS%%
+LOADER       = %%CC%%
+LOADOPTS     = 
 
 #
 #  C preprocessor defs for compilation (-DNoChange, -DAdd_, or -DUpCase)
