--- iiimxcf/xiiimp.so/autogen.sh	Wed Mar 24 10:15:03 2004
+++ iiimxcf/xiiimp.so/autogen.sh	Wed Feb 16 16:29:24 2005
@@ -12,7 +12,15 @@
 
 DIE=0
 
-(libtool --version) < /dev/null > /dev/null 2>&1 || {
+LIBTOOL=libtool15
+INTLTOOLIZE=intltoolize15
+LIBTOOLIZE=libtoolize15
+ACLOCAL=aclocal15
+AUTOHEADER=autoheader253
+AUTOMAKE=automake15
+AUTOCONF=autoconf253
+
+(${LIBTOOL} --version) < /dev/null > /dev/null 2>&1 || {
 	echo
 	echo "You must have libtool installed to compile $PROJECT."
 	echo "Install the appropriate package for your distribution,"
@@ -20,7 +28,7 @@
 	DIE=1
 }
 
-(autoconf --version) < /dev/null > /dev/null 2>&1 || {
+(${AUTOCONF} --version) < /dev/null > /dev/null 2>&1 || {
 	echo
 	echo "You must have autoconf installed to compile $PROJECT."
 	echo "libtool the appropriate package for your distribution,"
@@ -29,8 +37,8 @@
 }
 
 have_automake=false
-if automake --version < /dev/null > /dev/null 2>&1 ; then
-	automake_version=`automake --version | grep 'automake (GNU automake)' | sed 's/^[^0-9]*\(.*\)/\1/'`
+if ${AUTOMAKE} --version < /dev/null > /dev/null 2>&1 ; then
+	automake_version=`${AUTOMAKE} --version | grep 'automake (GNU automake)' | sed 's/^[^0-9]*\(.*\)/\1/'`
 	case $automake_version in
 	   1.2*|1.3*|1.4) 
 		;;
@@ -66,13 +74,13 @@
 # intentionally we don't call "libtoolize --force"
 # to avoid overriding ../acfiles/ltmain.h, which we don't want to happen!
 
-aclocal -I ../../acfiles $ACLOCAL_FLAGS
+${ACLOCAL} -I ../../acfiles $ACLOCAL_FLAGS
 
 # optionally feature autoheader
-(autoheader --version)  < /dev/null > /dev/null 2>&1 && autoheader
+(${AUTOHEADER} --version)  < /dev/null > /dev/null 2>&1 && ${AUTOHEADER}
 
-automake -a $am_opt
-autoconf
+${AUTOMAKE} -a $am_opt
+${AUTOCONF}
 cd $ORIGDIR
 
 if test -z "$AUTOGEN_SUBDIR_MODE"; then
