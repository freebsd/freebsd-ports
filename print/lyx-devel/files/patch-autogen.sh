--- autogen.sh	Thu Apr 18 22:11:28 2002
+++ autogen.sh	Fri Jun 28 21:55:35 2002
@@ -1,9 +1,9 @@
 #!/bin/sh
 
 ACLOCAL=aclocal
-AUTOHEADER=autoheader
+AUTOHEADER=autoheader213
 AUTOMAKE="automake -a -c --foreign"
-AUTOCONF=autoconf
+AUTOCONF=autoconf213
 GNUM4=
 
 ACINCLUDE_FILES="lyxinclude.m4 libtool.m4 codeset.m4 gettext.m4 glibc21.m4 iconv.m4 isc-posix.m4 lcmessage.m4 progtest.m4 sigc++.m4 qt2.m4 gtk--.m4 gnome--.m4 gnome.m4 pspell.m4"
@@ -31,7 +31,7 @@
 echo "done."
 
 # Generate the Makefiles and configure files
-if ( aclocal --version ) </dev/null > /dev/null 2>&1; then
+if ( $ACLOCAL --version ) </dev/null > /dev/null 2>&1; then
 	echo "Building macros..."
 	for dir in . lib/reLyX sigc++ ; do
 	    echo "        $dir"
@@ -43,7 +43,7 @@
 	exit
 fi
 
-if ( autoheader --version ) </dev/null > /dev/null 2>&1; then
+if ( $AUTOHEADER --version ) </dev/null > /dev/null 2>&1; then
 	echo "Building config header template..."
 	for dir in . sigc++ ; do
 	    echo "        $dir"
