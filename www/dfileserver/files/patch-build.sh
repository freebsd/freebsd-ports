--- build.sh.orig	Sun Jun 19 07:07:05 2005
+++ build.sh	Thu Sep 15 21:44:32 2005
@@ -1,6 +1,6 @@
 #!/bin/sh
 
-GCCFLAGS="-Wall -Werror -O3"
+GCCFLAGS=${CFLAGS}
 
 mkdir ./obj/
 mkdir ./obj/contrib/
@@ -8,18 +8,18 @@
 echo "Native Build:" $GCCFLAGS
 
 echo "Compiling src/DashFileServer.cxx"
-g++ $GCCFLAGS -c src/DashFileServer.cxx -o obj/DashFileServer.o
+${CXX} $GCCFLAGS -c src/DashFileServer.cxx -o obj/DashFileServer.o
 echo "Compiling src/ClientConnection.cxx"
-g++ $GCCFLAGS -c src/ClientConnection.cxx -o obj/ClientConnection.o
+${CXX} $GCCFLAGS -c src/ClientConnection.cxx -o obj/ClientConnection.o
 echo "Compiling src/CPathResolver.cxx"
-g++ $GCCFLAGS -c src/CPathResolver.cxx -o obj/CPathResolver.o
+${CXX} $GCCFLAGS -c src/CPathResolver.cxx -o obj/CPathResolver.o
 echo "Compiling src/DirectoryIndexing.cxx"
-g++ $GCCFLAGS -c src/DirectoryIndexing.cxx -o obj/DirectoryIndexing.o
+${CXX} $GCCFLAGS -c src/DirectoryIndexing.cxx -o obj/DirectoryIndexing.o
 echo "Compiling src/MimeTypes.cxx"
-g++ $GCCFLAGS -c src/MimeTypes.cxx -o obj/MimeTypes.o
+${CXX} $GCCFLAGS -c src/MimeTypes.cxx -o obj/MimeTypes.o
 
 echo "Linking..."
-g++ -o DFileServer.x86 obj/DashFileServer.o obj/ClientConnection.o obj/CPathResolver.o obj/DirectoryIndexing.o obj/MimeTypes.o
+${CXX} -o DFileServer.x86 obj/DashFileServer.o obj/ClientConnection.o obj/CPathResolver.o obj/DirectoryIndexing.o obj/MimeTypes.o
 
 echo "Striping..."
 strip --strip-all DFileServer.x86
