--- ./ra.sh.orig	2010-12-13 04:42:49.000000000 +0100
+++ ./ra.sh	2014-06-29 12:15:04.248542975 +0200
@@ -91,7 +91,7 @@
 }
 
 usage() {
-    $ECHO "Usage:	$0 [ -ctV ] [ -D working-directory ] [ -h server ] [ -p port ] [ -w authlevel ] { trip | update | create | auto | force | checkout | checkin } [ /path/or/file ]" >&2
+    $ECHO "Usage:	$0 [ -cIltV ] [ -% | -q ] [ -C \"generate\" | -C <checksum> ] [ -D working-directory ] [ -h server ] [ -p port ] [ -w authlevel ] { trip | update | create | auto | force | checkout | checkin } [ /path/or/file ]" >&2
     exit 1
 }
 
@@ -128,6 +128,38 @@
     fi
 }
 
+cksum_generate() {
+    if [ -n "$FSDIFF_CHECKSUM" ]; then
+	FTMP_CHECKSUM=`openssl sha1 ${FTMP} | awk '{ print $2 }'`
+    fi
+}
+
+cksum_compare() {
+    if [ -n "$FSDIFF_CHECKSUM" -a \
+	    "$FSDIFF_CHECKSUM" != "generate" -a \
+	    "$FSDIFF_CHECKSUM" != "$FTMP_CHECKSUM" ]; then
+	return 1
+    fi
+
+    return 0
+}
+
+cksum_print() {
+    if [ -n "$FSDIFF_CHECKSUM" ]; then
+	$ECHO "Difference transcript checksum: $FTMP_CHECKSUM"
+    fi
+}
+
+cksum_mismatch() {
+    if [ -n "$FSDIFF_CHECKSUM" ]; then
+	$ECHO
+	$ECHO "**** Difference transcript checksum mismatch!"
+	$ECHO "****	Expected: $FSDIFF_CHECKSUM"
+	$ECHO "****	Actual:   $FTMP_CHECKSUM"
+	#ECHO
+    fi
+}
+
 update() {
     opt="$1"
     kopt=
@@ -211,6 +243,11 @@
     fi
     if [ x"${opt}" = x"interactive" ]; then
 	while [ 1 ]; do
+	    cksum_generate
+	    if ! cksum_compare; then
+		cksum_mismatch
+	    fi
+
 	    if [ x"${can_edit}" = x"yes" ]; then
 		$ECHO -n "(e)dit difference transcript, "
 	    fi
@@ -248,7 +285,8 @@
 		
     lapply ${CASE} ${PROGRESS} ${NETOPTS} ${CHECKSUM} ${FTMP}
     case "$?" in
-    0)	;;
+    0)	cksum_print
+	;;
 
     *)  if [ x"$opt" = x"hook" ]; then
 	    $ECHO -n "Applying changes failed, trying again "
@@ -284,7 +322,7 @@
     . "${DEFAULTS}"
 fi
 
-while getopts %cD:h:Ilp:qr:tU:Vw: opt; do
+while getopts %C:cD:h:Ilp:qr:tU:Vw: opt; do
     case $opt in
     %)  PROGRESS="-%"
 	FPROGRESS="-%"
@@ -293,6 +331,13 @@
     q)  PROGRESS="-q"
 	;;
 
+    C)	FSDIFF_CHECKSUM="$OPTARG"
+	if ! type openssl >/dev/null 2>&1; then
+	    $ECHO "-C requires openssl, but no openssl found in PATH $PATH"
+	    cleanup_and_exit
+	fi
+	;;
+
     c)	CHECKSUM="-csha1"
 	;;
 
@@ -524,6 +569,14 @@
 		cleanup
 		exit 1
 	    fi
+
+	    cksum_generate
+	    if ! cksum_compare; then
+		$ECHO "Auto failure: `hostname`: difference cksum mismatch" 
+		cksum_mismatch
+		cleanup_and_exit
+	    fi
+
 	    dopreapply ${FTMP}
 	    if [ -s ${FTMP} ]; then
 		lapply ${NETOPTS} ${CASE} ${PROGRESS} \
@@ -532,6 +585,7 @@
 		0)
 		    $ECHO Auto update: `hostname`
 		    cat ${FTMP}
+		    cksum_print
 		    dopostapply ${FTMP}
 		    cleanup
 		    break
@@ -588,14 +642,17 @@
 	exit 0
     fi
     
+    cksum_generate
+    cksum_compare || cksum_mismatch
     dopreapply ${FTMP}
     lapply ${CASE} ${PROGRESS} ${NETOPTS} ${CHECKSUM} ${FTMP}
     case "$?" in
-    0)	;;
+    0)	cksum_print
+	;;
 
     *)	cleanup
-	    exit $?
-	    ;;
+	exit $?
+	;;
     esac
     dopostapply ${FTMP}
     
