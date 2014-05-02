--- genver.sh.orig	2014-02-11 22:06:01.000000000 +0100
+++ genver.sh	2014-04-30 17:06:00.000000000 +0200
@@ -1,4 +1,4 @@
-#! /bin/bash
+#! /bin/sh
 
 if [ ${#} -eq 1 ] && [ "x$1" = "x-r" ]; then
 	# release text only
@@ -7,28 +7,7 @@
 	QUIET=0
 fi
 
-if ! `(git status | grep -q "On branch") 2> /dev/null`; then
-        # If we don't have git, we can't work out what
-        # version this is. It must have been downloaded as a
-        # zip file. Github creates the zip file with all
-        # files dated from the last change: use the
-        # Makefile's modification time as a release number
-	release=zip-`stat -c "%y" Makefile | sed 's/ .*//'`
-fi
-
-if head=`git rev-parse --verify HEAD 2>/dev/null`; then
-	# generate the version info based on the tag
-	release=`(git describe --tags || git --describe || git describe --all --long) \
-		2>/dev/null | tr -d '\n'`
-
-	# Are there uncommitted changes?
-	git update-index --refresh --unmerged > /dev/null
-	if git diff-index --name-only HEAD | grep -v "^scripts/package" \
-	    | read dummy; then
-		release="$release-dirty"
-	fi
-fi
-
+release=
 
 if [ $QUIET -ne 1 ]; then
 	printf "#ifndef _VERSION_H_ \n"
