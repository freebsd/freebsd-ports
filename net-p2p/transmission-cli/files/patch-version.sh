--- version.sh.orig	2007-08-07 10:44:05.000000000 -0500
+++ version.sh	2007-08-07 10:44:41.000000000 -0500
@@ -52,9 +52,4 @@
 EOF
 replace_if_differs libtransmission/version.h.new libtransmission/version.h
 
-# Generate Info.plist from Info.plist.in
-sed -e "s/%%BUNDLE_VERSION%%/$SVN_REVISION/" -e "s/%%SHORT_VERSION_STRING%%/$USERAGENT_PREFIX/" \
-        < macosx/Info.plist.in > macosx/Info.plist.new
-replace_if_differs macosx/Info.plist.new macosx/Info.plist
-
 exit 0
