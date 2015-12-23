--- ./buildtools/scripts/abi_gen.sh.orig	2013-02-10 00:47:43.199878737 +0000
+++ ./buildtools/scripts/abi_gen.sh	2013-02-10 00:47:55.789877693 +0000
@@ -9,6 +9,7 @@
 cat <<EOF
 set height 0
 set width 0
+set print sevenbit-strings on
 EOF
 nm "$SHAREDLIB" | cut -d' ' -f2- | egrep '^[BDGTRVWS]' | grep -v @ | egrep -v ' (__bss_start|_edata|_init|_fini|_end)' | cut -c3- | sort | while read s; do
     echo "echo $s: "
@@ -17,5 +17,5 @@
 ) > $GDBSCRIPT
 
 # forcing the terminal avoids a problem on Fedora12
-TERM=none gdb -batch -x $GDBSCRIPT "$SHAREDLIB" < /dev/null
+TERM=none %%GDB_CMD%% -batch -x $GDBSCRIPT "$SHAREDLIB" < /dev/null
 rm -f $GDBSCRIPT
