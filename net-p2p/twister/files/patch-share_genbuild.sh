--- share/genbuild.sh.orig	2014-11-29 16:20:43.000000000 +0100
+++ share/genbuild.sh	2014-11-30 12:27:01.000000000 +0100
@@ -11,16 +11,12 @@
     exit 1
 fi
 
-if [ -e "$(which git)" ]; then
-    # clean 'dirty' status of touched files that haven't been modified
-    git diff >/dev/null 2>/dev/null 
 
-    # get a string like "v0.6.0-66-g59887e8-dirty"
-    DESC="$(git describe --dirty 2>/dev/null)"
+# get a string like "v0.6.0-66-g59887e8-dirty"
+DESC="v%%PORTVERSION%%"
 
-    # get a string like "2012-04-10 16:27:19 +0200"
-    TIME="$(git log -n 1 --format="%ci")"
-fi
+# get a string like "2012-04-10 16:27:19 +0200"
+TIME="$(date "+%F %T %z")"
 
 if [ -n "$DESC" ]; then
     NEWINFO="#define BUILD_DESC \"$DESC\""
