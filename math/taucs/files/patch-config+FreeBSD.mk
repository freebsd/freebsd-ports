--- config/FreeBSD.mk.orig	Fri Aug 29 00:13:38 2003
+++ config/FreeBSD.mk	Tue Jan  9 14:18:49 2007
@@ -8,16 +8,16 @@
 PATHSEP=/
 DEFFLG=-D
 
-FC        ?= f77
-FFLAGS    += -Os -fno-second-underscore
+FC        = %%FC%%
+FFLAGS    += -fno-second-underscore %%FFLAGS%%
 FOUTFLG   =-o 
 
-#CC        = cc
-CFLAGS    += -Os -D_POSIX_C_SOURCE=199506L -fPIC
+CC        = %%CC%%
+CFLAGS    += -D_POSIX_C_SOURCE=199506L %%CFLAGS%%
 COUTFLG   = -o
 
-LD        = $(CC) 
-LDFLAGS   = $(CFLAGS) -static
+LD        = %%FC%%
+LDFLAGS   = -L%%LOCALBASE%%/lib -L./
 LOUTFLG   = $(COUTFLG)
 
 AR        = ar cr
@@ -26,12 +26,12 @@
 RANLIB    = ranlib
 RM        = rm -rf
 
-LIBBLAS   = -L/usr/local/lib -lf77blas -lcblas -latlas -lg2c
-LIBLAPACK = -L/usr/local/lib -llapack
+LIBBLAS   = %%BLAS%%
+LIBLAPACK = %%LAPACK%%
 
-LIBMETIS  = -L/usr/local/lib -lmetis 
+LIBMETIS  = -lmetis 
 
-LIBF77 = -lg2c  
+LIBF77 = 
 #compat is required for ftime()
 LIBC   = -lm -lcompat 
 
