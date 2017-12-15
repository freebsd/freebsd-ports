--- buildtools/scripts/abi_gen.sh.orig	2017-01-11 07:55:14 UTC
+++ buildtools/scripts/abi_gen.sh
@@ -9,6 +9,7 @@ GDBSCRIPT="gdb_syms.$$"
 cat <<EOF
 set height 0
 set width 0
+set print sevenbit-strings on
 EOF
 nm "$SHAREDLIB" | cut -d' ' -f2- | egrep '^[BDGTRVWS]' | grep -v @ | egrep -v ' (__bss_start|_edata|_init|_fini|_end)' | cut -c3- | sort | while read s; do
     echo "echo $s: "
@@ -17,5 +18,5 @@ done
 ) > $GDBSCRIPT
 
 # forcing the terminal avoids a problem on Fedora12
-TERM=none gdb -batch -x $GDBSCRIPT "$SHAREDLIB" < /dev/null
+TERM=none %%GDB_CMD%% -batch -x $GDBSCRIPT "$SHAREDLIB" < /dev/null
 rm -f $GDBSCRIPT
