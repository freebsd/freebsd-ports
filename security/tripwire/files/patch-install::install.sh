--- install/install.sh.orig	Fri Oct 27 17:26:26 2000
+++ install/install.sh	Fri Feb 22 07:34:55 2002
@@ -3,7 +3,7 @@
 #########################################################
 #########################################################
 ##
-## Tripwire(R) 2.3 Open Source for LINUX install script
+## Tripwire(R) 2.3 Open Source for FreeBSD install script
 ##
 #########################################################
 #########################################################
@@ -252,12 +252,14 @@
 	unamVER=`uname -v -r`
         if ((echo "$unamOS" | $GREP -i "Linux" > /dev/null) ||
 	    (echo "$unamOS" | $GREP -i "HP-UX" > /dev/null) ||
+	    (echo "$unamOS" | $GREP -i "FreeBSD" > /dev/null) ||
 	    (echo "$unamOS" | $GREP -i "AIX" > /dev/null)); then
 		unamHW=`uname -m`
 	else
 		unamHW=`uname -p`
 	fi
-	if (echo "$unamOS" | $GREP -i "Linux" > /dev/null); then
+	if (echo "$unamOS" | $GREP -i "Linux" > /dev/null) ||
+	   (echo "$unamOS" | $GREP -i "FreeBSD" > /dev/null); then
 			osokay=1
 	fi
 	if [ "$osokay" -eq 0 ] ; then
@@ -488,7 +490,11 @@
 BASE_DIR=`echo $0 | sed s/$BASE_DIR\$//`
 if [ ! -z "$BASE_DIR" ] ; then
 	TAR_DIR="${BASE_DIR}"
-	BIN_DIR="${BASE_DIR}bin/i686-pc-linux_r"
+	if (echo "$unamOS" | $GREP -i "FreeBSD" > /dev/null); then
+		BIN_DIR="${BASE_DIR}bin/${unamHW}-unknown-freebsd_r"
+	else
+		BIN_DIR="${BASE_DIR}bin/i686-pc-linux_r"
+	fi
 else
 	TAR_DIR="${BASE_DIR}"
 fi
@@ -621,15 +627,22 @@
 f1=' ff=$README ; d="" ; dd=$TWDOCS ; rr=0444 '
 f2=' ff=$REL_NOTES ; d="" ; dd=$TWDOCS ; rr=0444 '
 f3=' ff=$TWLICENSEFILE ; d="" ; dd=$TWDOCS ; rr=0444 '
-f4=' ff=tripwire ; d="/bin/i686-pc-linux_r" ; dd=$TWBIN ; rr=0550 '
-f5=' ff=twadmin ; d="/bin/i686-pc-linux_r" ; dd=$TWBIN ; rr=0550 '
-f6=' ff=twprint ; d="/bin/i686-pc-linux_r" ; dd=$TWBIN ; rr=0550 '
-f7=' ff=siggen ; d="/bin/i686-pc-linux_r" ; dd=$TWBIN ; rr=0550 '
+if (echo "$unamOS" | $GREP -i "Linux" > /dev/null); then
+	f4=' ff=tripwire ; d="/bin/i686-pc-linux_r" ; dd=$TWBIN ; rr=0550 '
+	f5=' ff=twadmin ; d="/bin/i686-pc-linux_r" ; dd=$TWBIN ; rr=0550 '
+	f6=' ff=twprint ; d="/bin/i686-pc-linux_r" ; dd=$TWBIN ; rr=0550 '
+	f7=' ff=siggen ; d="/bin/i686-pc-linux_r" ; dd=$TWBIN ; rr=0550 '
+elif (echo "$unamOS" | $GREP -i "FreeBSD" > /dev/null); then
+	f4=' ff=tripwire ; d="/bin/${unamHW}-unknown-freebsd_r" ; dd=$TWBIN ; rr=0550 '
+	f5=' ff=twadmin ; d="/bin/${unamHW}-unknown-freebsd_r" ; dd=$TWBIN ; rr=0550 '
+	f6=' ff=twprint ; d="/bin/${unamHW}-unknown-freebsd_r" ; dd=$TWBIN ; rr=0550 '
+	f7=' ff=siggen ; d="/bin/${unamHW}-unknown-freebsd_r" ; dd=$TWBIN ; rr=0550 '
+fi
 f8=' ff=TRADEMARK ; d="" ; dd=$TWDOCS ; rr=0444 '
-f9=' ff=policyguide.txt ; d="" ; dd=$TWDOCS ; rr=0444 '
+f9=' ff=policyguide.txt ; d="/policy/" ; dd=$TWDOCS ; rr=0444 '
 f10=' ff=twpol.txt ; d="/policy/" ; dd=$TWPOLICY ; rr=0640 '
-f11=' ff=twpolicy.4 ; d="/man/man4" ; dd=$TWMAN/man4 ; rr=0444 '
-f12=' ff=twconfig.4 ; d="/man/man4" ; dd=$TWMAN/man4 ; rr=0444 '
+f11=' ff=twpolicy.5 ; d="/man/man5" ; dd=$TWMAN/man5 ; rr=0444 '
+f12=' ff=twconfig.5 ; d="/man/man5" ; dd=$TWMAN/man5 ; rr=0444 '
 f13=' ff=twfiles.5 ; d="/man/man5" ; dd=$TWMAN/man5 ; rr=0444 '
 f14=' ff=siggen.8 ; d="/man/man8" ; dd=$TWMAN/man8 ; rr=0444 '
 f15=' ff=tripwire.8 ; d="/man/man8" ; dd=$TWMAN/man8 ; rr=0444 '
