--- autogen.sh.orig	2013-07-20 21:14:17.454775429 +0000
+++ autogen.sh	2013-07-20 21:14:26.096159846 +0000
@@ -4,6 +4,7 @@
 test -z "$srcdir" && srcdir=.
 
 PKG_NAME="nemo"
+REQUIRED_AUTOMAKE_VERSION=1.14
 
 which gnome-autogen.sh || {
     echo "You need to install gnome-common from GNOME Git (or from"
