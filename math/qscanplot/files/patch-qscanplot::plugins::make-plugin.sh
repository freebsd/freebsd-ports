
$FreeBSD$

--- qscanplot/plugins/make-plugin.sh	2002/04/23 09:48:56	1.1
+++ qscanplot/plugins/make-plugin.sh	2002/04/23 09:53:40
@@ -1,6 +1,6 @@
 #! /bin/sh
 
-TMAKEPATH=/usr/lib/tmake/linux-g++
+TMAKEPATH=${LOCALBASE}/share/tmake/freebsd-g++
 
 export TMAKEPATH
 
@@ -38,7 +38,7 @@
 
 echo Building plugin $plg
 
-make -f $plgmak
+gmake -f $plgmak
 rm -f $plgmak $plgpro $plg.o
 
 echo done.
