--- ./srclib/apr/build/buildcheck.sh.orig	2009-11-12 19:27:16.000000000 -0500
+++ ./srclib/apr/build/buildcheck.sh	2010-05-06 19:37:54.248730202 -0400
@@ -2,6 +2,7 @@
 
 echo "buildconf: checking installation..."
 
+if [ "x${FULLBUILD}" = "xon" ] ; then
 # any python
 python=`build/PrintPath python`
 if test -z "$python"; then
@@ -13,6 +14,7 @@
 py_version=`python -c 'import sys; print sys.version' 2>&1|sed 's/ .*//;q'`
 echo "buildconf: python version $py_version (ok)"
 fi
+fi
 
 # autoconf 2.59 or newer
 ac_version=`${AUTOCONF:-autoconf} --version 2>/dev/null|sed -e 's/^[^0-9]*//;s/[a-z]* *$//;q'`
@@ -38,7 +40,7 @@
 # output is multiline from 1.5 onwards
 
 # Require libtool 1.4 or newer
-libtool=`build/PrintPath glibtool1 glibtool libtool libtool15 libtool14`
+libtool=${LIBTOOL}
 lt_pversion=`$libtool --version 2>/dev/null|sed -e 's/([^)]*)//g;s/^[^0-9]*//;s/[- ].*//g;q'`
 if test -z "$lt_pversion"; then
 echo "buildconf: libtool not found."
