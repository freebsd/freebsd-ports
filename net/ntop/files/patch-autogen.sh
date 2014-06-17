--- autogen.sh.orig	2012-02-20 14:35:43.000000000 +0400
+++ autogen.sh	2014-06-10 16:29:45.873177238 +0400
@@ -202,30 +202,6 @@
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
-if test "$GNU_OR_DIE" -eq 0; then
-  exit 1
-fi
-
-SVN=`find_command 'svn'`
-($SVN --version) < /dev/null > /dev/null 2>&1 ||
-{
-  echo
-  echo "You must have svn/subversion installed to compile $progname."
-  echo "Download the appropriate package for your distribution, or get the"
-  echo "source from http://subversion.tigris.org"
-  GNU_OR_DIE=0
-}
-
 if test "$GNU_OR_DIE" -eq 0; then
   exit 1
 fi
@@ -442,7 +418,8 @@
 if test -d nDPI; then
     echo "nDPI already available"
 else
-    svn co $NDPI_URL
+    echo "nDPI not bundled"
+    exit 1
 fi
 
 dnl> nDPI compilation
