--- tools/depends/target/ffmpeg/autobuild.sh.orig	2015-03-31 16:37:07 UTC
+++ tools/depends/target/ffmpeg/autobuild.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 #
 #      Copyright (C) 2005-2013 Team XBMC
 #      http://xbmc.org
@@ -27,7 +27,8 @@
 VERSION=$(grep "VERSION=" FFMPEG-VERSION | sed 's/VERSION=//g')
 ARCHIVE=ffmpeg-${VERSION}.tar.gz
 
-function usage {
+usage()
+{
   echo "usage $(basename $0) 
        [-p | --prefix]    ... ffmepg install prefix
        [-d | --download]  ... no build, download tarfile only
@@ -82,6 +83,14 @@
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
     -j)
       BUILDTHREADS=$2
       shift 2
@@ -100,7 +109,7 @@
   esac
 done
 
-BUILDTHREADS=${BUILDTHREADS:-$(grep -c "^processor" /proc/cpuinfo)}
+BUILDTHREADS=${BUILDTHREADS:-$(sysctl -n hw.ncpu)}
 [ ${BUILDTHREADS} -eq 0 ] && BUILDTHREADS=1
 
 [ -z ${VERSION} ] && exit 3
@@ -110,10 +119,10 @@
   [ "$VERSION" == "$CURVER" ] && exit 0
 fi
 
-[ -f ${ARCHIVE} ] || curl -Ls --create-dirs -f -o ${ARCHIVE} ${BASE_URL}/${VERSION}.tar.gz
+#[ -f ${ARCHIVE} ] || curl -Ls --create-dirs -f -o ${ARCHIVE} ${BASE_URL}/${VERSION}.tar.gz
 [ $downloadonly ] && exit 0
 
-[ -d ffmpeg-${VERSION} ] && rm -rf ffmpeg-${VERSION} && rm .ffmpeg-installed >/dev/null 2>&1
+#[ -d ffmpeg-${VERSION} ] && rm -rf ffmpeg-${VERSION} && rm .ffmpeg-installed >/dev/null 2>&1
 if [ -d ${FFMPEG_PREFIX} ]
 then
   [ -w ${FFMPEG_PREFIX} ] || SUDO="sudo"
@@ -121,9 +130,9 @@
   [ -w $(dirname ${FFMPEG_PREFIX}) ] || SUDO="sudo"
 fi
 
-mkdir ffmpeg-${VERSION}
+#mkdir ffmpeg-${VERSION}
 cd ffmpeg-${VERSION} || exit 2
-tar --strip-components=1 -xf ../${ARCHIVE}
+#tar --strip-components=1 -xf ../${ARCHIVE}
 
 CFLAGS="$CFLAGS" CXXFLAGS="$CXXFLAGS" LDFLAGS="$LDFLAGS" \
 ./configure --prefix=$FFMPEG_PREFIX \
@@ -161,11 +170,11 @@
 	--disable-mipsdspr2 \
         ${FLAGS}
 
-make -j ${BUILDTHREADS} 
+gmake -j ${BUILDTHREADS} 
 if [ $? -eq 0 ]
 then
   [ ${SUDO} ] && echo "Root privileges are required to install to ${FFMPEG_PREFIX}"
-  ${SUDO} make install && echo "$VERSION" > ../.ffmpeg-installed
+  ${SUDO} gmake install && echo "$VERSION" > ../.ffmpeg-installed
 else
   echo "ERROR: Building ffmpeg failed"
   exit 1
