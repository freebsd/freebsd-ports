--- qscanplot/plugins/make-plugin.sh.orig	Sun Apr 14 11:42:17 2002
+++ qscanplot/plugins/make-plugin.sh	Tue Feb 17 14:12:11 2004
@@ -1,14 +1,5 @@
 #! /bin/sh
 
-TMAKEPATH=/usr/lib/tmake/linux-g++
-
-export TMAKEPATH
-
-if [ ! -d $TMAKEPATH ]; then
-  echo Directory $TMAKEPATH selected for TMAKEPATH does not exist 
-  exit 1
-fi
-
 plg=$1
 
 plgcpp=$plg.cpp
@@ -34,11 +25,11 @@
 
 echo Generating makefile . . .
 
-tmake -o $plgmak $plgpro
+qmake -o $plgmak $plgpro
 
 echo Building plugin $plg
 
-make -f $plgmak
+gmake -f $plgmak
 rm -f $plgmak $plgpro $plg.o
 
 echo done.
