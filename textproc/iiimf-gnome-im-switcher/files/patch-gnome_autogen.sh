--- gnome-im-switcher/autogen.sh	Fri Dec  5 12:25:06 2003
+++ gnome-im-switcher/autogen.sh	Wed Feb 16 16:50:27 2005
@@ -13,15 +13,20 @@
 
 DIE=0
 
-AUTOMAKE=automake-1.4
-ACLOCAL=aclocal-1.4
+LIBTOOL=libtool15
+INTLTOOLIZE=intltoolize
+LIBTOOLIZE=libtoolize15
+ACLOCAL=aclocal15
+AUTOHEADER=autoheader253
+AUTOMAKE=automake15
+AUTOCONF=autoconf253
 
 ($AUTOMAKE --version) < /dev/null > /dev/null 2>&1 || {
         AUTOMAKE=automake
         ACLOCAL=aclocal
 }
 
-(autoconf --version) < /dev/null > /dev/null 2>&1 || {
+($AUTOCONF --version) < /dev/null > /dev/null 2>&1 || {
 	echo
 	echo "You must have autoconf installed to compile $PROJECT."
 	echo "Download the appropriate package for your distribution,"
@@ -38,7 +43,7 @@
 }
 
 (grep "^AM_PROG_LIBTOOL" configure.in >/dev/null) && {
-  (libtool --version) < /dev/null > /dev/null 2>&1 || {
+  ($LIBTOOL --version) < /dev/null > /dev/null 2>&1 || {
     echo
     echo "**Error**: You must have \`libtool' installed to compile $PROJECT."
     echo "Get ftp://ftp.gnu.org/pub/gnu/libtool-1.2d.tar.gz"
@@ -57,7 +62,7 @@
 }
 
 (grep "^AC_PROG_INTLTOOL" $srcdir/configure.in >/dev/null) && {
-  (intltoolize --version) < /dev/null > /dev/null 2>&1 || {
+  ($INTLTOOLIZE --version) < /dev/null > /dev/null 2>&1 || {
     echo
     echo "**Error**: You must have \`intltoolize' installed to compile $PKG_NAME."
     echo "Get ftp://ftp.gnome.org/pub/GNOME/stable/sources/intltool/intltool-0.10.tar.gz"
@@ -115,22 +120,22 @@
       fi
       if grep "^AC_PROG_INTLTOOL" configure.in >/dev/null; then
         echo "Running intltoolize..."
-	intltoolize --copy --force --automake
+	$INTLTOOLIZE --copy --force --automake
       fi
       if grep "^AM_PROG_LIBTOOL" configure.in >/dev/null; then
 	echo "Running libtoolize..."
-	libtoolize --force --copy
+	$LIBTOOLIZE --force --copy
       fi
       echo "Running $ACLOCAL $aclocalinclude ..."
       $ACLOCAL $aclocalinclude
       if grep "^AM_CONFIG_HEADER" configure.in >/dev/null; then
 	echo "Running autoheader..."
-	autoheader
+	$AUTOHEADER
       fi
       echo "Running $AUTOMAKE --gnu $am_opt ..."
       $AUTOMAKE --add-missing --gnu $am_opt
       echo "Running autoconf ..."
-      autoconf
+      $AUTOCONF
     )
   fi
 done
