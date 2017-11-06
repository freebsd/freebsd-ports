--- install.sh.orig	2015-07-13 03:31:19 UTC
+++ install.sh
@@ -2,6 +2,7 @@
 
 INSTALLDIR=${INSTALLDIR:-/usr/local/lib/Ngraph}
 BINDIR=${BINDIR:-/usr/local/bin}
+LIBDIR=${PREFIX}/lib/Ngraph
 
 TEXTFILES="Ngraph.ini .Ngraph .Ngraph.ngp .fit.ngp INSTALL.jis gpl.txt gpl.ja.txt"
 ADDINFILES="append.nsc math.nsc text-in.nsc \
@@ -26,8 +27,8 @@ if [ ! -f ./org/Ngraph.ini ]
 then
   cp Ngraph.ini ./org
 fi
-sed -e "s?INSTALLDIR?${INSTALLDIR}?" ./org/ngraph.sh > ngraph.sh
-sed -e "s?INSTALLDIR?${INSTALLDIR}?" ./org/Ngraph.ini > Ngraph.ini
+sed -e "s?INSTALLDIR?${LIBDIR}?" ./org/ngraph.sh > ngraph.sh
+sed -e "s?INSTALLDIR?${LIBDIR}?" ./org/Ngraph.ini > Ngraph.ini
 
 echo "Making directories in ${INSTALLDIR}"
 if [ ! -d ${INSTALLDIR} ]
@@ -112,7 +113,7 @@ echo "Copying documents to ${INSTALLDIR}
 if [ ! -h ${BINDIR}/ngraph ]
 then
   echo "Making a symbolic link ${BINDIR}/ngraph"
-  ln -s ${INSTALLDIR}/ngraph.sh ${BINDIR}/ngraph
+  ln -s ${LIBDIR}/ngraph.sh ${BINDIR}/ngraph
 fi
 
 if [ -f ./org/ngraph.sh ]
