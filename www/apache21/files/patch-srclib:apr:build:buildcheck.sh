--- srclib/apr/build/buildcheck.sh.orig	Sun Jun  6 23:19:19 2004
+++ srclib/apr/build/buildcheck.sh	Sat Dec 11 16:57:18 2004
@@ -38,7 +38,7 @@
 # output is multiline from 1.5 onwards
 
 # Require libtool 1.3.3 or newer
-libtool=`build/PrintPath glibtool libtool libtool15 libtool14`
+libtool=${LIBTOOL}
 lt_pversion=`$libtool --version 2>/dev/null|sed -e 's/([^)]*)//g;s/^[^0-9]*//;s/[- ].*//g;q'`
 if test -z "$lt_pversion"; then
 echo "buildconf: libtool not found."
