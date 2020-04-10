Chicken and egg: Make tests runnable without afl++ already installed.

[!] LTO llvm_mode failed
clang-9: error: invalid linker name in argument '-fuse-ld=/usr/local/lib/afl/afl-ld'
[!] llvm_mode LTO persistent mode feature compilation failed

Setting AFL_CC is not necessary since all programs should be compiled
with the right settings already.

--- test/test.sh.orig	2020-04-09 08:23:37 UTC
+++ test/test.sh
@@ -220,14 +220,6 @@ test "$SYS" = "i686" -o "$SYS" = "x86_64" -o "$SYS" = 
 
 $ECHO "$BLUE[*] Testing: llvm_mode, afl-showmap, afl-fuzz, afl-cmin and afl-tmin"
 test -e ../afl-clang-fast -a -e ../split-switches-pass.so && {
-  # on FreeBSD need to set AFL_CC
-  test `uname -s` = 'FreeBSD' && {
-    if type clang >/dev/null; then
-      export AFL_CC=`command -v clang`
-    else
-      export AFL_CC=`$LLVM_CONFIG --bindir`/clang
-    fi
-  }
   ../afl-clang-fast -o test-instr.plain ../test-instr.c > /dev/null 2>&1
   AFL_HARDEN=1 ../afl-clang-fast -o test-compcov.harden test-compcov.c > /dev/null 2>&1
   test -e test-instr.plain && {
@@ -398,16 +390,7 @@ test -e ../afl-clang-fast -a -e ../split-switches-pass
 
 $ECHO "$BLUE[*] Testing: LTO llvm_mode"
 test -e ../afl-clang-lto -a -e ../afl-llvm-lto-instrumentation.so && {
-  # on FreeBSD need to set AFL_CC
-  test `uname -s` = 'FreeBSD' && {
-    if type clang >/dev/null; then
-      export AFL_CC=`command -v clang`
-    else
-      export AFL_CC=`$LLVM_CONFIG --bindir`/clang
-    fi
-  }
-
-  ../afl-clang-lto -o test-instr.plain ../test-instr.c > /dev/null 2>&1
+  ../afl-clang-lto -fuse-ld="$(realpath ../afl-ld)" -o test-instr.plain ../test-instr.c > /dev/null 2>&1
   test -e test-instr.plain && {
     $ECHO "$GREEN[+] llvm_mode LTO compilation succeeded"
     echo 0 | ../afl-showmap -m ${MEM_LIMIT} -o test-instr.plain.0 -r -- ./test-instr.plain > /dev/null 2>&1
@@ -452,7 +435,7 @@ test -e ../afl-clang-lto -a -e ../afl-llvm-lto-instrum
 #    CODE=1
 #  }
 #  rm -f test-compcov test.out whitelist.txt
-  ../afl-clang-lto -o test-persistent ../examples/persistent_demo/persistent_demo.c > /dev/null 2>&1
+  ../afl-clang-lto -fuse-ld="$(realpath ../afl-ld)" -o test-persistent ../examples/persistent_demo/persistent_demo.c > /dev/null 2>&1
   test -e test-persistent && {
     echo foo | ../afl-showmap -o /dev/null -q -r ./test-persistent && {
       $ECHO "$GREEN[+] llvm_mode LTO persistent mode feature works correctly"
@@ -472,8 +455,6 @@ test -e ../afl-clang-lto -a -e ../afl-llvm-lto-instrum
 
 $ECHO "$BLUE[*] Testing: gcc_plugin"
 test -e ../afl-gcc-fast -a -e ../afl-gcc-rt.o && {
-  SAVE_AFL_CC=${AFL_CC}
-  export AFL_CC=`command -v gcc`
   ../afl-gcc-fast -o test-instr.plain.gccpi ../test-instr.c > /dev/null 2>&1
   AFL_HARDEN=1 ../afl-gcc-fast -o test-compcov.harden.gccpi test-compcov.c > /dev/null 2>&1
   test -e test-instr.plain.gccpi && {
@@ -575,7 +556,6 @@ test -e ../afl-gcc-fast -a -e ../afl-gcc-rt.o && {
     CODE=1
   }
   rm -f test-persistent
-  export AFL_CC=${SAVE_AFL_CC}
 } || {
   $ECHO "$YELLOW[-] gcc_plugin not compiled, cannot test"
   INCOMPLETE=1
