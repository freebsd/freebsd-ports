--- srclib/apr/build/buildcheck.sh.orig	Fri Jan 14 11:16:31 2005
+++ srclib/apr/build/buildcheck.sh	Wed Feb 23 11:16:25 2005
@@ -38,7 +38,7 @@
 # output is multiline from 1.5 onwards
 
 # Require libtool 1.4 or newer
-libtool=`build/PrintPath glibtool libtool libtool15 libtool14`
+libtool=${LIBTOOL}
 lt_pversion=`$libtool --version 2>/dev/null|sed -e 's/([^)]*)//g;s/^[^0-9]*//;s/[- ].*//g;q'`
 if test -z "$lt_pversion"; then
 echo "buildconf: libtool not found."
