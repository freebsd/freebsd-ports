--- version.sh.orig	Wed Apr 18 11:24:12 2007
+++ version.sh	Wed Apr 18 11:24:21 2007
@@ -48,9 +48,4 @@
 EOF
 replace_if_differs libtransmission/version.h.new libtransmission/version.h
 
-# Generate Info.plist from Info.plist.in
-sed -e "s/%%BUNDLE_VERSION%%/$REV/" -e "s/%%SHORT_VERSION_STRING%%/$STRING/" \
-        < macosx/Info.plist.in > macosx/Info.plist.new
-replace_if_differs macosx/Info.plist.new macosx/Info.plist
-
 exit 0
