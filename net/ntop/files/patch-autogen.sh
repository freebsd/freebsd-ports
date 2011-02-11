--- ./autogen.sh.orig	2011-02-02 10:40:23.000000000 +0100
+++ ./autogen.sh	2011-02-02 10:40:40.000000000 +0100
@@ -202,16 +202,6 @@
   GNU_OR_DIE=0
 }
 
-WGET=`find_command 'wget*'`
-($WGET --version) < /dev/null > /dev/null 2>&1 ||
-{
-  echo
-  echo "You must have wget installed to compile $progname."
-  echo "Download the appropriate package for your distribution, or get the"
-  echo "source tarball from ftp://ftp.gnu.org/pub/gnu/wget"
-  GNU_OR_DIE=0
-}
-
 if test "$GNU_OR_DIE" -eq 0; then
   exit 1
 fi
