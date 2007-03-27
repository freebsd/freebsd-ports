--- src/unix-gcc.mak.orig	Fri Jul  7 06:32:50 2006
+++ src/unix-gcc.mak	Fri Mar 23 14:44:08 2007
@@ -21,15 +21,16 @@
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
 
 # Do not edit the next group of lines.
 
@@ -48,11 +49,10 @@
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
@@ -143,7 +143,7 @@
 # some older JPEG streams that violate the standard. If the JPEG
 # library built from local sources, the patch will be applied.
 
-SHARE_JPEG=0
+SHARE_JPEG=1
 JPEG_NAME=jpeg
 
 # Define the directory where the PNG library sources are stored,
@@ -158,7 +158,7 @@
 # what its name is.
 # See gs.mak and Make.htm for more information.
 
-SHARE_LIBPNG=0
+SHARE_LIBPNG=1
 LIBPNG_NAME=png
 
 # Define the directory where the zlib sources are stored.
@@ -170,7 +170,7 @@
 # what its name is (usually libz, but sometimes libgz).
 # See gs.mak and Make.htm for more information.
 
-SHARE_ZLIB=0
+SHARE_ZLIB=1
 #ZLIB_NAME=gz
 ZLIB_NAME=z
 
@@ -179,6 +179,14 @@
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
 
@@ -202,7 +210,7 @@
 
 # Define the name of the C compiler.
 
-CC=gcc
+CC?=cc
 
 # Define the name of the linker for the final link step.
 # Normally this is the same as the C compiler.
@@ -219,9 +227,9 @@
 # Define the added flags for standard, debugging, profiling 
 # and shared object builds.
 
-CFLAGS_STANDARD=-O2
-CFLAGS_DEBUG=-g -O0
-CFLAGS_PROFILE=-pg -O2
+CFLAGS_STANDARD?=-O2
+CFLAGS_DEBUG=-g
+CFLAGS_PROFILE=-pg
 CFLAGS_SO=-fPIC
 
 # Define the other compilation flags.  Add at most one of the following:
@@ -235,7 +243,7 @@
 # We don't include -ansi, because this gets in the way of the platform-
 #   specific stuff that <math.h> typically needs; nevertheless, we expect
 #   gcc to accept ANSI-style function prototypes and function definitions.
-XCFLAGS=
+XCFLAGS+=-I${.CURDIR}/jasper/src/libjasper/include -I${LOCALBASE}/include/libpng -I${LOCALBASE}/include
 
 CFLAGS=$(CFLAGS_STANDARD) $(GCFLAGS) $(XCFLAGS)
 
@@ -246,7 +254,7 @@
 #	-R /usr/local/xxx/lib:/usr/local/lib
 # giving the full path names of the shared library directories.
 # XLDFLAGS can be set from the command line.
-XLDFLAGS=
+XLDFLAGS=-L${LOCALBASE}/lib
 
 LDFLAGS=$(XLDFLAGS)
 
@@ -279,7 +287,7 @@
 # Note that x_.h expects to find the header files in $(XINCLUDE)/X11,
 # not in $(XINCLUDE).
 
-XINCLUDE=-I/usr/X11R6/include
+XINCLUDE=-I${X11BASE}/include
 
 # Define the directory/ies and library names for the X11 library files.
 # XLIBDIRS is for ld and should include -L; XLIBDIR is for LD_RUN_PATH
@@ -291,12 +299,12 @@
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
@@ -447,6 +455,9 @@
 include $(GLSRCDIR)/zlib.mak
 include $(GLSRCDIR)/libpng.mak
 include $(GLSRCDIR)/jbig2.mak
+include $(GLSRCDIR)/jasper.mak
+include $(GLSRCDIR)/ldf_jb2.mak
+include $(GLSRCDIR)/lwf_jp2.mak
 include $(GLSRCDIR)/icclib.mak
 include $(GLSRCDIR)/ijs.mak
 include $(GLSRCDIR)/devs.mak
