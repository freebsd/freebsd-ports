##################################################################
#
# This Makefile is tested with FreeBSD 5.x
#
# Contributed by: 
#   Jason W. Bacon
#   Medical College of Wisconsin
#   bacon@smithers.neuro.mcw.edu
#
# Before compiling afni, install the following packages:
#
#   open-motif
# 
# To compile SUMA you will also need the following packages:
#
#   libiconv
#   gettext
#   gmake
#
#   Note:   SUMA has display problems on FreeBSD 4.8 and below that I 
#           have not found time to resolve.  I believe they are related
#           to the version of the GL libraries that ship with 4.x.
#
#           SUMA works fine under FreeBSD 4.9 with GeForce drivers installed
#           and under FreeBSD 5.1.
#
#   Note:   The SUMA build process (as of Aug, 2003) requires GNU make,
#           which is ${LOCALBASE}/bin/gmake on BSD systems.  
#           Be sure the MAKE macro below is set to gmake.
#
#   Note:   Compilation of netcdf-3.5.0 may fail due to m4's lack of
#           support for the -B option.  Remove the -B10000 flag from
#           netcdf-3.5.0/src/configure BEFORE running make to avoid
#           this error.  ( Or force configure to use gm4 by reversing
#           the order of "m4 gm4" to "gm4 m4" everywhere in the script }
#           This problem has been reported to the netcdf development team.
#           It seems to have been resolved as of the June, 2003 afni
#           source distribution.
#

USE_ZLIB = -DHAVE_ZLIB
LZLIB    = -lz
USE_GIFTI = -DHAVE_GIFTI
LGIFTI    = -L${LOCALBASE}/lib -lexpat

CC?     = cc
LD?     = ${CC}

CCDEBS = -DAFNI_DEBUG -DIMSEQ_DEBUG -DDISPLAY_DEBUG -DTHD_DEBUG
CEXTRA = -DFreeBSD -DNO_GAMMA -DUSE_TRACING -DHAVE_XDBE -DSUMA_MOTIF_GLXAREA
ifeq (${ARCH}, amd64)
CEXTRA += -DPIC -fPIC
endif
ifeq (${ARCH}, ia64)
CEXTRA += -DPIC -fPIC
endif

CFLAGS += -Wno-return-type -Wno-switch ${CEXTRA}
CC     += ${CFLAGS}

CCVOL  = ${CC}
CCFAST = ${CC} -O3
CCMIN  = ${CC}
CCD    = ${CC} ${CCDEBS}
CCSVD  = ${CC} -O0
CCOLD  = ${CC}

IFLAGS = -I. -I${LOCALBASE}/include
LFLAGS = -s -L. -L${LOCALBASE}/lib

MAKE   = gmake
# Some build scripts pick up the wrong make, so Makefile.INCLUDE is edited
# to use MAKE_CMD
MAKE_CMD  = gmake

PLUGIN_SUFFIX = so
PLUGIN_LFLAGS = -shared
PLUGIN_CC     = ${CC}
PLFLAGS       = -s -rdynamic -L. -L${LOCALBASE}/lib

AR     = /usr/bin/ar
RANLIB = /usr/bin/ranlib
TAR    = /usr/bin/tar
MKDIR  = /bin/mkdir
TAPE   = /dev/sa0
GZIP   = /bin/gzip

RM = /bin/rm -f
MV = /bin/mv -f
CP = /bin/cp -f

LINT = /usr/bin/lint -a -b -u -v -x ${IFLAGS} ${CCDEFS}

INSTALLDIR = ./BSD
LIBDIR = ${INSTALLDIR}

# for dynamic linking

LLIBS  = -lmri -lf2c -lXm -lXp -lXpm -lXext -lXmu -lXt -lX11 -lm $(LZLIB) $(LGIFTI)

# vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
# For suma (NO STATIC LINKING OF GL libs)
SUMA_INCLUDE_PATH = -I${LOCALBASE}/include/glib-2.0 -I${LOCALBASE}/lib/glib-2.0/include -I${LOCALBASE}/include -I./ -I../ -I../niml/ -Igts/src 
SUMA_LINK_PATH = -L/usr/lib -L${LOCALBASE}/lib -L../
#use -lGLw if you have libGLw.a or libGLw.so* or 
#  -lMesaGLw if you have Mesa's version (libMesaGLw*) of libGLw
SUMA_LINK_LIB = -lXm -lGLw -lGLU -lGL -lXmu -lXp -lXt -lXext -lX11 -lm $(LZLIB) -lxml2 -lexpat
SUMA_MAKEFILE_NAME = SUMA_Makefile
SUMA_BIN_ARCHIVE = SUMA_FreeBSD.tar
SUMA_GLIB_VER = -2.0
# ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

###############################################################

include Makefile.INCLUDE
