--- build.sh.orig	2012-01-18 18:50:23.000000000 -0500
+++ build.sh	2012-03-18 20:45:51.836691332 -0400
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 #
 # p0f - build script
 # ------------------
@@ -154,7 +154,7 @@
 rm -f "$TMP" || exit 1
 
 echo "int main() { return 0; }" >"$TMP.c" || exit 1
-$CC $BASIC_CFLAGS $BASIC_LDFLAGS "$TMP.c" -o "$TMP" &>"$TMP.log"
+$CC $BASIC_CFLAGS $BASIC_LDFLAGS "$TMP.c" -o "$TMP" >"$TMP.log" 2>&1
 
 if [ ! -x "$TMP" ]; then
 
@@ -179,7 +179,7 @@
 rm -f "$TMP" "$TMP.c" "$TMP.log" || exit 1
 
 echo "int main() { return 0; }" >"$TMP.c" || exit 1
-$CC $USE_CFLAGS $USE_LDFLAGS "$TMP.c" -o "$TMP" &>"$TMP.log"
+$CC $USE_CFLAGS $USE_LDFLAGS "$TMP.c" -o "$TMP" >"$TMP.log" 2>&1
 
 if [ ! -x "$TMP" ]; then
 
@@ -198,7 +198,7 @@
 rm -f "$TMP" "$TMP.c" "$TMP.log" || exit 1
 
 echo -e "#include \"types.h\"\nvolatile u8 tmp[6]; int main() { printf(\"%d\x5cn\", *(u32*)(tmp+1)); return 0; }" >"$TMP.c" || exit 1
-$CC $USE_CFLAGS $USE_LDFLAGS "$TMP.c" -o "$TMP" &>"$TMP.log"
+$CC $USE_CFLAGS $USE_LDFLAGS "$TMP.c" -o "$TMP" >"$TMP.log" 2>&1
 
 if [ ! -x "$TMP" ]; then
 
@@ -215,8 +215,8 @@
 
 else
 
-  ulimit -c 0 &>/dev/null
-  ./"$TMP" &>/dev/null
+  ulimit -c 0 >/dev/null 2>&1
+  ./"$TMP" >/dev/null 2>&1
 
   if [ "$?" = "0" ]; then
 
@@ -237,7 +237,7 @@
 rm -f "$TMP" "$TMP.c" "$TMP.log" || exit 1
 
 echo -e "#include <pcap.h>\nint main() { char i[PCAP_ERRBUF_SIZE]; pcap_lookupdev(i); return 0; }" >"$TMP.c" || exit 1
-$CC $USE_CFLAGS $USE_LDFLAGS "$TMP.c" -o "$TMP" $USE_LIBS &>"$TMP.log"
+$CC $USE_CFLAGS $USE_LDFLAGS "$TMP.c" -o "$TMP" $USE_LIBS >"$TMP.log" 2>&1
 
 if [ ! -x "$TMP" ]; then
   echo "FAIL"
@@ -282,14 +282,14 @@
 rm -f "$TMP" "$TMP.c" "$TMP.log" || exit 1
 
 echo -e "#include <pcap.h>\n#include <pcap-bpf.h>\nint main() { return 0; }" >"$TMP.c" || exit 1
-$CC $USE_CFLAGS $USE_LDFLAGS "$TMP.c" -o "$TMP" $USE_LIBS &>"$TMP.log"
+$CC $USE_CFLAGS $USE_LDFLAGS "$TMP.c" -o "$TMP" $USE_LIBS >"$TMP.log" 2>&1
 
 if [ ! -x "$TMP" ]; then
 
   rm -f "$TMP" "$TMP.c" "$TMP.log" || exit 1
 
   echo -e "#include <pcap.h>\n#include <net/bpf.h>\nint main() { return 0; }" >"$TMP.c" || exit 1
-  $CC $USE_CFLAGS $USE_LDFLAGS "$TMP.c" -o "$TMP" $USE_LIBS &>"$TMP.log"
+  $CC $USE_CFLAGS $USE_LDFLAGS "$TMP.c" -o "$TMP" $USE_LIBS >"$TMP.log" 2>&1
 
   if [ ! -x "$TMP" ]; then
     echo "FAIL"
@@ -318,7 +318,7 @@
 
 rm -f "$PROGNAME" || exit 1
 
-$CC $USE_CFLAGS $USE_LDFLAGS "$PROGNAME.c" $OBJFILES -o "$PROGNAME" $USE_LIBS &>"$TMP.log"
+$CC $USE_CFLAGS $USE_LDFLAGS "$PROGNAME.c" $OBJFILES -o "$PROGNAME" $USE_LIBS >"$TMP.log" 2>&1
 
 if [ ! -x "$PROGNAME" ]; then
 
@@ -349,6 +349,9 @@
 
 fi
 
+echo "[*] Compiling tools: "
+cd tools && make 
+
 echo
 echo "Well, that's it. Be sure to review README. If you run into any problems, you"
 echo "can reach the author at <lcamtuf@coredump.cx>."
