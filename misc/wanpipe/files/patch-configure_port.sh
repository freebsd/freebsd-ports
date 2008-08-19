--- configure_port.sh	2008-07-15 14:27:24.000000000 +0000
+++ /tmp/configure_port.sh	2008-08-19 00:14:36.000000000 +0000
@@ -1286,7 +1286,9 @@
 {
 	local	dir
 
+	echo dir: $dir
 	path=`find $1 -name 'zaptel.h'`
+	echo path: $path
 	if [ -z $path ]; then
 		print
 		print -e "\tZaptel sources are not found!"
@@ -1337,9 +1339,10 @@
 OSYSTEM_VER=`uname -r`
 PKG_NAME=$1
 PKG_ACTION=$2
-WAN_BASE=$3
-PKG_ARG1=$4
-PKG_ARG2=$5
+WRKDIR=$3
+WAN_BASE=$4
+PKG_ARG1=$5
+PKG_ARG2=$6
 SYSDIR=/usr/src/sys
 WAN_BUILDDIR=/
 WAN_BIN_DIR=${WAN_BASE}/sbin
@@ -1348,8 +1351,6 @@
 YACC=yacc
 LEX=lex
 
-WRKDIR=`pwd`/work/$1
-
 OUTPUT_TYPE=NORMAL
 
 ZAPTEL_PORT=/usr/ports/misc/zaptel
@@ -1362,11 +1363,12 @@
 
 init_global_params
 
-if [ -z "$PKG_ARG1" ]; then
-	# No options are selected, compile both TDM and WAN
-	PKG_ARG1="WITH_TDM_VOICE"
-	PKG_ARG2="WITH_WAN_PROTOCOL"
-fi
+# This conflicts with the default settings of OPTIONS
+#if [ -z "$PKG_ARG1" ]; then
+#	# No options are selected, compile both TDM and WAN
+#	PKG_ARG1="WITH_TDM_VOICE"
+#	PKG_ARG2="WITH_WAN_PROTOCOL"
+#fi
 if [ "$PKG_ARG1" = "WITH_TDM_VOICE" ]; then
 	MODES="${MODES}-${TDM_MODES}"
 	get_zaptel_path $ZAPTEL_PORT
