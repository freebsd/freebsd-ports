--- autogen.sh.orig	2009-06-02 10:26:46.731977294 -0400
+++ autogen.sh	2009-06-02 10:27:02.866983000 -0400
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
