-- Make old Lake test portable and non-hanging on FreeBSD.
-- BSD sed does not support `\s`, so use a POSIX character class. Also group
-- `grep ... || true` before piping so process substitution FIFOs are always read.
-- Update expected "Built ..." lines to the Lean 4.33.1 output format.

--- tests/lake/tests/old/test.sh.orig	2026-08-21 10:26:01 UTC
+++ tests/lake/tests/old/test.sh
@@ -10,9 +10,9 @@ diff_out() {
 # https://github.com/leanprover/lean4/issues/2822
 
 diff_out() {
-  grep 'Built' || true |
+  { grep 'Built' || true; } |
   sed 's/^.*\[.*\] //' |
-  sed 's/\s*(.*)$//' |
+  sed -E 's/[[:space:]]*(\(.*\))$//' |
   LANG=POSIX sort |
   diff -u --strip-trailing-cr "$1" -
 }
@@ -25,8 +25,8 @@ Built Hello.Basic
 echo 'def hello := "old"' > hello/Hello/Basic.lean
 $LAKE -d hello build --old | diff_out <(cat << 'EOF'
 Built Hello.Basic
-Built Hello.Basic:c
-Built hello
+Built Hello.Basic:c.o
+Built hello:exe
 EOF
 )
 
@@ -35,9 +35,10 @@ Built Hello.Basic
 $LAKE -d hello build | diff_out <(cat << 'EOF'
 Built Hello
 Built Hello.Basic
-Built Hello.Basic:c
+Built Hello.Basic:c.o
 Built Main
-Built hello
+Built Main:c.o
+Built hello:exe
 EOF
 )
 
