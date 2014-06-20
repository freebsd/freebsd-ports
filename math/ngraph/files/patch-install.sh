--- install.sh.orig	2009-10-15 20:17:47.000000000 +0900
+++ install.sh	2014-06-20 21:40:11.532930042 +0900
@@ -2,6 +2,7 @@
 
 INSTALLDIR=${INSTALLDIR:-/usr/local/lib/Ngraph}
 BINDIR=${BINDIR:-/usr/local/bin}
+LIBDIR=${PREFIX}/lib/Ngraph
 
 TEXTFILES="Ngraph.ini .Ngraph .Ngraph.ngp .fit.ngp INSTALL.jis gpl.txt gpl.ja.txt"
 ADDINFILES="append.nsc math.nsc text-in.nsc \
@@ -26,8 +27,8 @@
 then
   cp Ngraph.ini ./org
 fi
-sed -e "s?INSTALLDIR?${INSTALLDIR}?" ./org/ngraph.sh > ngraph.sh
-sed -e "s?INSTALLDIR?${INSTALLDIR}?" ./org/Ngraph.ini > Ngraph.ini
+sed -e "s?INSTALLDIR?${LIBDIR}?" ./org/ngraph.sh > ngraph.sh
+sed -e "s?INSTALLDIR?${LIBDIR}?" ./org/Ngraph.ini > Ngraph.ini
 
 echo "Making directories in ${INSTALLDIR}"
 if [ ! -d ${INSTALLDIR} ]
@@ -90,7 +91,7 @@
 if [ ! -h ${BINDIR}/ngraph ]
 then
   echo "Making a symbolic link ${BINDIR}/ngraph"
-  ln -s ${INSTALLDIR}/ngraph.sh ${BINDIR}/ngraph
+  ln -s ${LIBDIR}/ngraph.sh ${BINDIR}/ngraph
 fi
 
 if [ -f ./org/ngraph.sh ]
