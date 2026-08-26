--- buildtools/scripts/abi_gen.sh.orig	2026-01-20 15:42:53 UTC
+++ buildtools/scripts/abi_gen.sh
@@ -9,6 +9,7 @@ set width 0
 	cat <<EOF
 set height 0
 set width 0
+set print sevenbit-strings on
 EOF
 
 	# On older linker versions _init|_fini symbols are not hidden.
@@ -22,5 +23,5 @@ EOF
 ) >$GDBSCRIPT
 
 # forcing the terminal avoids a problem on Fedora12
-TERM=none gdb -n -batch -x $GDBSCRIPT "$SHAREDLIB" </dev/null
+TERM=none true -n -batch -x $GDBSCRIPT "$SHAREDLIB" < /dev/null
 rm -f $GDBSCRIPT
