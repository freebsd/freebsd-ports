--- version-gen.sh.orig	2020-03-19 09:52:56.313967100 +0100
+++ version-gen.sh	2020-03-27 19:15:53.407855000 +0100
@@ -2,10 +2,6 @@
 
 DEFAULT_VERSION="5.11.0.git"
 
-if [ -d .git ]; then
-	VERSION="`git describe --dirty=+ --abbrev=7 2> /dev/null | sed -e '/^collectd-/!d' -e 's///' -e 'y/-/./'`"
-fi
-
 if test -z "$VERSION"; then
 	VERSION="$DEFAULT_VERSION"
 fi
