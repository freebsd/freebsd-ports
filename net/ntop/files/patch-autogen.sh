--- autogen.sh.orig	2009-09-15 11:33:11.000000000 -0300
+++ autogen.sh	2009-09-15 11:34:06.000000000 -0300
@@ -244,16 +244,6 @@
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
