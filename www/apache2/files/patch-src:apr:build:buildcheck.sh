--- srclib/apr/build/buildcheck.sh	Sun Jan 25 16:41:56 2004
+++ srclib/apr/build/buildcheck.sh	Tue Mar  9 07:49:42 2004
@@ -26,7 +26,7 @@
 # output is multiline from 1.5 onwards
 
 # Require libtool 1.3.3 or newer
-libtool=`build/PrintPath glibtool libtool`
+libtool=${LIBTOOL}
 lt_pversion=`$libtool --version 2>/dev/null|sed -e 's/([^)]*)//g;s/^[^0-9]*//;s/[- ].*//g;q'`
 if test -z "$lt_pversion"; then
 echo "buildconf: libtool not found."
