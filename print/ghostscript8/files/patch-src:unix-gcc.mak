--- src/unix-gcc.mak.orig	Tue Jul 31 05:13:56 2007
+++ src/unix-gcc.mak	Fri Aug 10 22:01:41 2007
@@ -21,15 +21,17 @@
 # source, generated intermediate file, and object directories
 # for the graphics library (GL) and the PostScript/PDF interpreter (PS).
 
-BINDIR=./bin
-GLSRCDIR=./src
-GLGENDIR=./obj
-GLOBJDIR=./obj
-PSSRCDIR=./src
-PSLIBDIR=./lib
-PSRESDIR=./Resource
-PSGENDIR=./obj
-PSOBJDIR=./obj
+.CURDIR?=.
+BINDIR=${.CURDIR}/bin
+GLSRCDIR=${.CURDIR}/src
+GLGENDIR=${.CURDIR}/obj
+GLOBJDIR=${.CURDIR}/obj
+PSSRCDIR=${.CURDIR}/src
+PSLIBDIR=${.CURDIR}/lib
+PSRESDIR=${.CURDIR}/Resource
+PSGENDIR=${.CURDIR}/obj
+PSOBJDIR=${.CURDIR}/obj
+CONTRIBDIR=${.CURDIR}/contrib
 
 # Do not edit the next group of lines.
 
@@ -48,11 +50,10 @@
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
@@ -62,6 +63,7 @@
 datadir = $(prefix)/share
 gsdir = $(datadir)/ghostscript
 gsdatadir = $(gsdir)/$(GS_DOT_VERSION)
+gssharedir = $(libdir)/ghostscript/$(GS_DOT_VERSION)
 
 docdir=$(gsdatadir)/doc
 exdir=$(gsdatadir)/examples
@@ -108,7 +110,7 @@
 # -DHAVE_HYPOT
 #       use the system hypot() call
 
-CAPOPT= -DHAVE_MKSTEMP
+CAPOPT= -DHAVE_MKSTEMP -DHAVE_HYPOT
 
 # Define the name of the executable file.
 
@@ -143,7 +145,7 @@
 # some older JPEG streams that violate the standard. If the JPEG
 # library built from local sources, the patch will be applied.
 
-SHARE_JPEG=0
+SHARE_JPEG=1
 JPEG_NAME=jpeg
 
 # Define the directory where the PNG library sources are stored,
@@ -158,7 +160,7 @@
 # what its name is.
 # See gs.mak and Make.htm for more information.
 
-SHARE_LIBPNG=0
+SHARE_LIBPNG=1
 LIBPNG_NAME=png
 
 # Define the directory where the zlib sources are stored.
@@ -170,7 +172,7 @@
 # what its name is (usually libz, but sometimes libgz).
 # See gs.mak and Make.htm for more information.
 
-SHARE_ZLIB=0
+SHARE_ZLIB=1
 #ZLIB_NAME=gz
 ZLIB_NAME=z
 
@@ -179,6 +181,14 @@
 JBIG2_LIB=jbig2dec
 JBIG2SRCDIR=jbig2dec
 
+# Choose the library to use for (JPXDecode support)
+# whether to link to an external build or compile in from source
+# and source location and configuration flags for compiling in
+JPX_LIB=jasper
+SHARE_JPX=0
+JPXSRCDIR=jasper
+JPX_CFLAGS=-DJAS_CONFIGURE
+
 # Define the directory where the icclib source are stored.
 # See icclib.mak for more information
 
@@ -207,7 +217,7 @@
 
 # Define the name of the C compiler.
 
-CC=gcc
+CC?=cc
 
 # Define the name of the linker for the final link step.
 # Normally this is the same as the C compiler.
@@ -224,10 +234,10 @@
 # Define the added flags for standard, debugging, profiling 
 # and shared object builds.
 
-CFLAGS_STANDARD=-O2
+CFLAGS_STANDARD?=-O2
 CFLAGS_DEBUG=-g -O0
 CFLAGS_PROFILE=-pg -O2
-CFLAGS_SO=-fPIC -shared
+CFLAGS_SO=-fPIC
 
 # Define the other compilation flags.  Add at most one of the following:
 #	-DBSD4_2 for 4.2bsd systems.
@@ -240,7 +250,8 @@
 # We don't include -ansi, because this gets in the way of the platform-
 #   specific stuff that <math.h> typically needs; nevertheless, we expect
 #   gcc to accept ANSI-style function prototypes and function definitions.
-XCFLAGS=-DGS_DEVS_SHARED -DGS_DEVS_SHARED_DIR=\"$(gssharedir)\"
+XCFLAGS+=-DGS_DEVS_SHARED -DGS_DEVS_SHARED_DIR=\"$(gssharedir)\"
+XCFLAGS+=-DUPD_SIGNAL=0 -I${JPXSRCDIR}/src/libjasper/include -I${LOCALBASE}/include/libpng -I${LOCALBASE}/include
 
 CFLAGS=$(CFLAGS_STANDARD) $(GCFLAGS) $(XCFLAGS)
 
@@ -251,7 +262,7 @@
 #	-R /usr/local/xxx/lib:/usr/local/lib
 # giving the full path names of the shared library directories.
 # XLDFLAGS can be set from the command line.
-XLDFLAGS=
+XLDFLAGS+=-L${LOCALBASE}/lib
 
 LDFLAGS=$(XLDFLAGS)
 
@@ -262,7 +273,7 @@
 # Solaris may need -lnsl -lsocket -lposix4.
 # (Libraries required by individual drivers are handled automatically.)
 
-EXTRALIBS=-rdynamic -ldl
+EXTRALIBS+=-Wl,-export-dynamic
 
 # Define the standard libraries to search at the end of linking.
 # Most platforms require -lpthread for the POSIX threads library;
@@ -284,7 +295,7 @@
 # Note that x_.h expects to find the header files in $(XINCLUDE)/X11,
 # not in $(XINCLUDE).
 
-XINCLUDE=-I/usr/X11R6/include
+XINCLUDE=-I${X11BASE}/include
 
 # Define the directory/ies and library names for the X11 library files.
 # XLIBDIRS is for ld and should include -L; XLIBDIR is for LD_RUN_PATH
@@ -296,12 +307,12 @@
 # Solaris and other SVR4 systems with dynamic linking probably want
 #XLIBDIRS=-L/usr/openwin/lib -R/usr/openwin/lib
 # X11R6 (on any platform) may need
-#XLIBS=Xt SM ICE Xext X11
+XLIBS=Xt SM ICE Xext X11
 
 #XLIBDIRS=-L/usr/local/X/lib
-XLIBDIRS=-L/usr/X11R6/lib
+XLIBDIRS=-L${X11BASE}/lib
 XLIBDIR=
-XLIBS=Xt Xext X11
+#XLIBS=Xt Xext X11
 
 # Define whether this platform has floating point hardware:
 #	FPU_TYPE=2 means floating point is faster than fixed point.
@@ -319,16 +330,16 @@
 
 # If POSIX sync primitives are used, also change the STDLIBS to include
 # the pthread library.
-#SYNC=posync
+SYNC=posync
 
 # Default is No sync primitives since some platforms don't have it (HP-UX)
-SYNC=nosync
+#SYNC=nosync
 
 # ------ Devices and features ------ #
 
 # Choose the language feature(s) to include.  See gs.mak for details.
 
-FEATURE_DEVS=$(PSD)psl3.dev $(PSD)pdf.dev $(PSD)dpsnext.dev $(PSD)ttfont.dev $(PSD)epsf.dev $(GLD)pipe.dev $(PSD)fapi.dev
+FEATURE_DEVS=$(PSD)psl3.dev $(PSD)pdf.dev $(PSD)dpsnext.dev $(PSD)ttfont.dev $(PSD)epsf.dev $(GLD)pipe.dev $(PSD)fapi.dev $(PSD)jbig2.dev $(PSD)jpx.dev
 #FEATURE_DEVS=$(PSD)psl3.dev $(PSD)pdf.dev
 # The following is strictly for testing.
 FEATURE_DEVS_ALL=$(PSD)psl3.dev $(PSD)pdf.dev $(PSD)dpsnext.dev $(PSD)ttfont.dev $(PSD)rasterop.dev $(PSD)double.dev $(PSD)trapping.dev $(PSD)stocht.dev $(GLD)pipe.dev
@@ -418,7 +429,7 @@
 DEVICE_DEVS21=$(DD)spotcmyk.dev $(DD)devicen.dev $(DD)xcf.dev $(DD)bmpsep1.dev $(DD)bmpsep8.dev $(DD)bmp16m.dev $(DD)bmp32b.dev $(DD)psdcmyk.dev $(DD)psdrgb.dev
 
 # Shared library target to build.
-GS_SHARED_OBJS=$(GLOBJDIR)/X11.so $(GLOBJDIR)/lvga256.so $(GLOBJDIR)/vgalib.so
+#GS_SHARED_OBJS=$(GLOBJDIR)/X11.so $(GLOBJDIR)/lvga256.so $(GLOBJDIR)/vgalib.so
 #GS_SHARED_OBJS=$(GLOBJDIR)/X11.so
 
 # ---------------------------- End of options --------------------------- #
@@ -457,6 +468,9 @@
 include $(GLSRCDIR)/zlib.mak
 include $(GLSRCDIR)/libpng.mak
 include $(GLSRCDIR)/jbig2.mak
+include $(GLSRCDIR)/jasper.mak
+include $(GLSRCDIR)/ldf_jb2.mak
+include $(GLSRCDIR)/lwf_jp2.mak
 include $(GLSRCDIR)/icclib.mak
 include $(GLSRCDIR)/ijs.mak
 include $(GLSRCDIR)/devs.mak
@@ -466,6 +480,7 @@
 include $(GLSRCDIR)/unix-dll.mak
 include $(GLSRCDIR)/unix-end.mak
 include $(GLSRCDIR)/unixinst.mak
+include $(CONTRIBDIR)/contrib.mak
 
 # This has to come last so it won't be taken as the default target.
 $(AK):
