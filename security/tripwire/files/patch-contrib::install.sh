--- contrib/install.sh.orig	Thu Sep 15 20:12:39 2005
+++ contrib/install.sh	Mon Feb 13 16:18:22 2006
@@ -162,12 +162,6 @@
 # Default installation script configuration file.
 INSTALL_CONFIG_FILE="./install/install.cfg"
 
-# Name of the Readme file.
-README="README"
-
-# Name of the release notes.
-REL_NOTES="Release_Notes"
-
 # Relative path to dir that contains the pkg files.
 PKG_DIR="pkg"
 
@@ -573,8 +567,6 @@
 
 README_LOC=${TWDOCS}/$REL_NOTES
 
-f1=' ff=$README ; d="" ; dd=$TWDOCS ; rr=0444 '
-f2=' ff=$REL_NOTES ; d="" ; dd=$TWDOCS ; rr=0444 '
 f3=' ff=$TWLICENSEFILE ; d="" ; dd=$TWDOCS ; rr=0444 '
 #f4=' ff=tripwire ; d="/bin" ; dd=$TWBIN ; rr=0550 '
 #f5=' ff=twadmin ; d="/bin" ; dd=$TWBIN ; rr=0550 '
@@ -593,7 +585,7 @@
 #f18=' ff=twprint.8 ; d="/man/man8" ; dd=$TWMAN/man8 ; rr=0444 '
 
 # Binaries and manpages are already installed by the install target
-loosefiles="f1 f2 f3 f8 f9 f10"
+loosefiles="f3 f8 f9 f10"
 
 for i in $loosefiles; do
 	eval "eval \"\$$i\""
