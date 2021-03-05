--- buildtools/scripts/abi_gen.sh.orig	2019-01-15 10:07:00 UTC
+++ buildtools/scripts/abi_gen.sh
@@ -9,13 +9,14 @@ GDBSCRIPT="gdb_syms.$$"
 cat <<EOF
 set height 0
 set width 0
+set print sevenbit-strings on
 EOF
-nm "$SHAREDLIB" | cut -d' ' -f2- | egrep '^[BDGTRVWS]' | grep -v @ | egrep -v ' (__bss_start|_edata|_init|_fini|_end)' | cut -c3- | sort | while read s; do
-    echo "echo $s: "
-    echo p $s
+nm "$SHAREDLIB" | cut -d" "  -f2- | awk '/^[BDGTRVWS]/ && !/@|__bss_start|_edata|_init|_fini|_end/ { print $2 }' | sort | while read s; do
+    echo "echo $s:\\ "
+    echo whatis $s
 done
 ) > $GDBSCRIPT
 
 # forcing the terminal avoids a problem on Fedora12
-TERM=none gdb -n -batch -x $GDBSCRIPT "$SHAREDLIB" < /dev/null
+TERM=none %%GDB_CMD%% -n -batch -x $GDBSCRIPT "$SHAREDLIB" < /dev/null | sed -e 's/:type =/:/g'
 rm -f $GDBSCRIPT
