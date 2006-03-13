--- config/FreeBSD.mk.orig	Fri Aug 29 00:13:38 2003
+++ config/FreeBSD.mk	Mon Mar 13 11:38:31 2006
@@ -9,15 +9,15 @@
 DEFFLG=-D
 
 FC        ?= f77
-FFLAGS    += -Os -fno-second-underscore
+FFLAGS    += -fno-second-underscore
 FOUTFLG   =-o 
 
 #CC        = cc
-CFLAGS    += -Os -D_POSIX_C_SOURCE=199506L -fPIC
+CFLAGS    += -D_POSIX_C_SOURCE=199506L -fPIC
 COUTFLG   = -o
 
 LD        = $(CC) 
-LDFLAGS   = $(CFLAGS) -static
+LDFLAGS   = $(CFLAGS)
 LOUTFLG   = $(COUTFLG)
 
 AR        = ar cr
@@ -26,10 +26,10 @@
 RANLIB    = ranlib
 RM        = rm -rf
 
-LIBBLAS   = -L/usr/local/lib -lf77blas -lcblas -latlas -lg2c
-LIBLAPACK = -L/usr/local/lib -llapack
+LIBBLAS   = -L${LOCALBASE}/lib -lf77blas -lcblas -latlas -lg2c
+LIBLAPACK = -L${LOCALBASE}/lib -llapack
 
-LIBMETIS  = -L/usr/local/lib -lmetis 
+LIBMETIS  = -L${LOCALBASE}/lib -lmetis 
 
 LIBF77 = -lg2c  
 #compat is required for ftime()
