--- base/unix-gcc.mak.orig	2015-03-30 08:21:24 UTC
+++ base/unix-gcc.mak
@@ -22,19 +22,19 @@
 # source, generated intermediate file, and object directories
 # for the graphics library (GL) and the PostScript/PDF interpreter (PS).
 
-BINDIR=./$(BUILDDIRPREFIX)bin
-GLSRCDIR=./base
-DEVSRCDIR=./devices
-GLGENDIR=./$(BUILDDIRPREFIX)obj
-GLOBJDIR=./$(BUILDDIRPREFIX)obj
-DEVGENDIR=./$(BUILDDIRPREFIX)obj
-DEVOBJDIR=./$(BUILDDIRPREFIX)obj
+BINDIR=${.CURDIR}/$(BUILDDIRPREFIX)bin
+GLSRCDIR=${.CURDIR}/base
+DEVSRCDIR=${.CURDIR}/devices
+GLGENDIR=${.CURDIR}/$(BUILDDIRPREFIX)obj
+GLOBJDIR=${.CURDIR}/$(BUILDDIRPREFIX)obj
+DEVGENDIR=${.CURDIR}/$(BUILDDIRPREFIX)obj
+DEVOBJDIR=${.CURDIR}/$(BUILDDIRPREFIX)obj
 AUXDIR=$(GLGENDIR)/aux
-PSSRCDIR=./psi
-PSLIBDIR=./lib
-PSRESDIR=./Resource
-PSGENDIR=./$(BUILDDIRPREFIX)obj
-PSOBJDIR=./$(BUILDDIRPREFIX)obj
+PSSRCDIR=${.CURDIR}/psi
+PSLIBDIR=${.CURDIR}/lib
+PSRESDIR=${.CURDIR}/Resource
+PSGENDIR=${.CURDIR}/$(BUILDDIRPREFIX)obj
+PSOBJDIR=${.CURDIR}/$(BUILDDIRPREFIX)obj
 
 # Do not edit the next group of lines.
 
@@ -53,11 +53,10 @@ PSD=$(PSGENDIR)/
 # the directories also define the default search path for the
 # initialization files (gs_*.ps) and the fonts.
 
-INSTALL = $(GLSRCDIR)/instcopy -c
-INSTALL_PROGRAM = $(INSTALL) -m 755
-INSTALL_DATA = $(INSTALL) -m 644
+INSTALL_PROGRAM = ${BSD_INSTALL_SCRIPT}
+INSTALL_DATA = ${BSD_INSTALL_DATA}
 
-prefix = /usr/local
+prefix = ${PREFIX}
 exec_prefix = $(prefix)
 bindir = $(exec_prefix)/bin
 scriptdir = $(bindir)
@@ -107,7 +106,7 @@ GENOPT=
 #               This uses the more secure temporary file creation call
 #               Enable this if it is available on your platform.
 
-CAPOPT= -DHAVE_MKSTEMP
+CAPOPT= -DHAVE_MKSTEMP -DHAVE_HYPOT
 
 # Define the name of the executable file.
 
@@ -142,7 +141,7 @@ JSRCDIR=jpeg
 # some older JPEG streams that violate the standard. If the JPEG
 # library built from local sources, the patch will be applied.
 
-SHARE_JPEG=0
+SHARE_JPEG=1
 JPEG_NAME=jpeg
 
 # Define the directory where the PNG library sources are stored,
@@ -156,13 +155,13 @@ PNGSRCDIR=libpng
 # what its name is.
 # See gs.mak and Make.htm for more information.
 
-SHARE_LIBPNG=0
+SHARE_LIBPNG=1
 LIBPNG_NAME=png
 
 # Define whether to use a shared version of libtiff and where
 # it is stored and what its name is.
 
-SHARE_LIBTIFF=0
+SHARE_LIBTIFF=1
 TIFFSRCDIR=tiff
 TIFFCONFDIR=tiff
 TIFFPLATFORM=unix
@@ -180,12 +179,12 @@ ZSRCDIR=zlib
 # what its name is (usually libz, but sometimes libgz).
 # See gs.mak and Make.htm for more information.
 
-SHARE_ZLIB=0
+SHARE_ZLIB=1
 #ZLIB_NAME=gz
 ZLIB_NAME=z
 
 # Choose shared or compiled in libjbig2dec and source location
-SHARE_JBIG2=0
+SHARE_JBIG2=1
 JBIG2_LIB=jbig2dec
 JBIG2SRCDIR=jbig2dec
 
@@ -225,7 +224,7 @@ RANLIB=ranlib
 
 # Define the name of the C compiler.
 
-CC=gcc
+CC?=cc
 
 # Define the name of the linker for the final link step.
 # Normally this is the same as the C compiler.
@@ -242,7 +241,7 @@ GCFLAGS=-Wall -Wstrict-prototypes -Wmiss
 # Define the added flags for standard, debugging, profiling 
 # and shared object builds.
 
-CFLAGS_STANDARD=-O2
+CFLAGS_STANDARD?=-O2
 CFLAGS_DEBUG=-g -O0
 CFLAGS_PROFILE=-pg -O2
 CFLAGS_SO=-fPIC
@@ -258,7 +257,8 @@ CFLAGS_SO=-fPIC
 # We don't include -ansi, because this gets in the way of the platform-
 #   specific stuff that <math.h> typically needs; nevertheless, we expect
 #   gcc to accept ANSI-style function prototypes and function definitions.
-XCFLAGS=-DGS_DEVS_SHARED -DGS_DEVS_SHARED_DIR=\"$(gssharedir)\"
+#XCFLAGS+=-DGS_DEVS_SHARED -DGS_DEVS_SHARED_DIR=\"$(gssharedir)\"
+XCFLAGS+=-DUPD_SIGNAL=0 -I${JPXSRCDIR}/src/libjasper/include -I${LOCALBASE}/include/libpng -I${LOCALBASE}/include
 
 CFLAGS=$(CFLAGS_STANDARD) $(GCFLAGS) $(XCFLAGS)
 
@@ -269,7 +269,7 @@ CFLAGS=$(CFLAGS_STANDARD) $(GCFLAGS) $(X
 #	-R /usr/local/xxx/lib:/usr/local/lib
 # giving the full path names of the shared library directories.
 # XLDFLAGS can be set from the command line.
-XLDFLAGS=
+XLDFLAGS+=-L${LOCALBASE}/lib
 
 LDFLAGS=$(XLDFLAGS)
 
@@ -280,7 +280,7 @@ LDFLAGS=$(XLDFLAGS)
 # Solaris may need -lnsl -lsocket -lposix4.
 # (Libraries required by individual drivers are handled automatically.)
 
-EXTRALIBS=-rdynamic -ldl
+EXTRALIBS+=-Wl,-export-dynamic
 
 # Define the standard libraries to search at the end of linking.
 # Most platforms require -lpthread for the POSIX threads library;
@@ -302,7 +302,7 @@ STDLIBS=-lm
 # Note that x_.h expects to find the header files in $(XINCLUDE)/X11,
 # not in $(XINCLUDE).
 
-XINCLUDE=-I/usr/X11R6/include
+XINCLUDE=-I${LOCALBASE}/include
 
 # Define the directory/ies and library names for the X11 library files.
 # XLIBDIRS is for ld and should include -L; XLIBDIR is for LD_RUN_PATH
@@ -317,29 +317,29 @@ XINCLUDE=-I/usr/X11R6/include
 #XLIBS=Xt SM ICE Xext X11
 
 #XLIBDIRS=-L/usr/local/X/lib
-XLIBDIRS=-L/usr/X11R6/lib
+XLIBDIRS=-L${LOCALBASE}/lib
 XLIBDIR=
-XLIBS=Xt Xext X11
+XLIBS=Xt SM ICE Xext X11
 
 # Define the .dev module that implements thread and synchronization
 # primitives for this platform.
 
 # If POSIX sync primitives are used, also change the STDLIBS to include
 # the pthread library.
-#SYNC=posync
+SYNC=posync
 
 # define the file name extension for a shared lib
 DYNANIC_LIB_EXT=so
 
 # Default is No sync primitives since some platforms don't have it (HP-UX)
-SYNC=nosync
+#SYNC=nosync
 
 SOC_LOADER=dxmainc.c
 # ------ Devices and features ------ #
 
 # Choose the language feature(s) to include.  See gs.mak for details.
 
-FEATURE_DEVS=$(PSD)psl3.dev $(PSD)pdf.dev $(PSD)dpsnext.dev $(PSD)ttfont.dev $(PSD)epsf.dev $(GLD)pipe.dev $(PSD)fapi.dev
+FEATURE_DEVS=$(PSD)psl3.dev $(PSD)pdf.dev $(PSD)dpsnext.dev $(PSD)ttfont.dev $(PSD)epsf.dev $(GLD)pipe.dev $(PSD)fapi.dev $(PSD)jbig2.dev $(PSD)jpx.dev
 #FEATURE_DEVS=$(PSD)psl3.dev $(PSD)pdf.dev
 # The following is strictly for testing.
 FEATURE_DEVS_ALL=$(PSD)psl3.dev $(PSD)pdf.dev $(PSD)dpsnext.dev $(PSD)ttfont.dev $(PSD)rasterop.dev $(PSD)double.dev $(PSD)trapping.dev $(PSD)stocht.dev $(GLD)pipe.dev
@@ -488,6 +488,7 @@ include $(GLSRCDIR)/unixlink.mak
 include $(GLSRCDIR)/unix-dll.mak
 include $(GLSRCDIR)/unix-end.mak
 include $(GLSRCDIR)/unixinst.mak
+include $(CONTRIBDIR)/contrib.mak
 
 # This has to come last so it won't be taken as the default target.
 $(AK):
