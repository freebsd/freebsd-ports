--- tools/depends/target/ffmpeg/autobuild.sh.orig	2017-11-14 16:55:01 UTC
+++ tools/depends/target/ffmpeg/autobuild.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 #
 #      Copyright (C) 2005-2013 Team XBMC
 #      http://xbmc.org
@@ -27,7 +27,8 @@ BASE_URL=$(grep "BASE_URL=" FFMPEG-VERSION | sed 's/BA
 VERSION=$(grep "VERSION=" FFMPEG-VERSION | sed 's/VERSION=//g')
 ARCHIVE=ffmpeg-$(echo "${VERSION}" | sed 's/\//-/g').tar.gz
 
-function usage {
+usage()
+{
   echo "usage $(basename $0) 
        [-p | --prefix]    ... ffmepg install prefix
        [-d | --download]  ... no build, download tarfile only
@@ -87,6 +88,46 @@ do
       FLAGS="$FLAGS --extra-cxxflags=\"${1#*=}\""
       shift
       ;;
+    --cc=*)
+      FLAGS="$FLAGS --cc=${1#*=}"
+      shift
+      ;;
+    --cxx=*)
+      FLAGS="$FLAGS --cxx=${1#*=}"
+      shift
+      ;;
+    --disable-xlib)
+      FLAGS="$FLAGS --disable-xlib"
+      shift
+      ;;
+    --disable-libxcb)
+      FLAGS="$FLAGS --disable-libxcb"
+      shift
+      ;;
+    --disable-libxcb-shm)
+      FLAGS="$FLAGS --disable-libxcb-shm"
+      shift
+      ;;
+    --disable-libxcb-xfixes)
+      FLAGS="$FLAGS --disable-libxcb-xfixes"
+      shift
+      ;;
+    --disable-libxcb-shape)
+      FLAGS="$FLAGS --disable-libxcb-shape"
+      shift
+      ;;
+    --disable-fast-unaligned)
+      FLAGS="$FLAGS --disable-fast-unaligned"
+      shift
+      ;;
+    --disable-vfp)
+      FLAGS="$FLAGS --disable-vfp"
+      shift
+      ;;
+    --enable-neon)
+      FLAGS="$FLAGS --enable-neon --cpu=armv7-a"
+      shift
+      ;;
     -j)
       BUILDTHREADS=$2
       shift 2
@@ -105,7 +146,7 @@ do
   esac
 done
 
-BUILDTHREADS=${BUILDTHREADS:-$(grep -c "^processor" /proc/cpuinfo)}
+BUILDTHREADS=${BUILDTHREADS:-$(sysctl -n hw.ncpu)}
 [ ${BUILDTHREADS} -eq 0 ] && BUILDTHREADS=1
 
 [ -z ${VERSION} ] && exit 3
@@ -115,12 +156,12 @@ then
   [ "$VERSION" == "$CURVER" ] && exit 0
 fi
 
-[ -f ${ARCHIVE} ] ||
-  curl -Ls --create-dirs -f -o ${ARCHIVE} ${BASE_URL}/${VERSION}.tar.gz ||
-  { echo "error fetching ${BASE_URL}/${VERSION}.tar.gz" ; exit 3; }
+#[ -f ${ARCHIVE} ] ||
+#  curl -Ls --create-dirs -f -o ${ARCHIVE} ${BASE_URL}/${VERSION}.tar.gz ||
+#  { echo "error fetching ${BASE_URL}/${VERSION}.tar.gz" ; exit 3; }
 [ $downloadonly ] && exit 0
 
-[ -d ffmpeg-${VERSION} ] && rm -rf ffmpeg-${VERSION} && rm .ffmpeg-installed >/dev/null 2>&1
+#[ -d ffmpeg-${VERSION} ] && rm -rf ffmpeg-${VERSION} && rm .ffmpeg-installed >/dev/null 2>&1
 if [ -d ${FFMPEG_PREFIX} ]
 then
   [ -w ${FFMPEG_PREFIX} ] || SUDO="sudo"
@@ -128,9 +169,9 @@ else
   [ -w $(dirname ${FFMPEG_PREFIX}) ] || SUDO="sudo"
 fi
 
-mkdir -p "ffmpeg-${VERSION}"
-cd "ffmpeg-${VERSION}" || exit 2
-tar --strip-components=1 -xf $MYDIR/${ARCHIVE}
+#mkdir -p "ffmpeg-${VERSION}"
+cd "FFmpeg-${VERSION}" || exit 2
+#tar --strip-components=1 -xf $MYDIR/${ARCHIVE}
 
 CFLAGS="$CFLAGS" CXXFLAGS="$CXXFLAGS" LDFLAGS="$LDFLAGS" \
 ./configure --prefix=$FFMPEG_PREFIX \
@@ -167,11 +208,11 @@ CFLAGS="$CFLAGS" CXXFLAGS="$CXXFLAGS" LDFLAGS="$LDFLAG
 	--disable-mipsdspr2 \
         ${FLAGS}
 
-make -j ${BUILDTHREADS} 
+gmake -j ${BUILDTHREADS} 
 if [ $? -eq 0 ]
 then
   [ ${SUDO} ] && echo "Root privileges are required to install to ${FFMPEG_PREFIX}"
-  ${SUDO} make install && echo "$VERSION" > $MYDIR/.ffmpeg-installed
+  ${SUDO} gmake install && echo "$VERSION" > $MYDIR/.ffmpeg-installed
 else
   echo "ERROR: Building ffmpeg failed"
   exit 1
