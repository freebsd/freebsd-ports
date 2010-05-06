--- ./srclib/apr/build/buildcheck.sh.orig	2004-11-24 18:10:04.000000000 -0500
+++ ./srclib/apr/build/buildcheck.sh	2010-05-06 16:06:03.782832400 -0400
@@ -26,7 +26,7 @@
 # output is multiline from 1.5 onwards
 
 # Require libtool 1.3.3 or newer
-libtool=`build/PrintPath glibtool libtool`
+libtool=${LIBTOOL}
 lt_pversion=`$libtool --version 2>/dev/null|sed -e 's/([^)]*)//g;s/^[^0-9]*//;s/[- ].*//g;q'`
 if test -z "$lt_pversion"; then
 echo "buildconf: libtool not found."
