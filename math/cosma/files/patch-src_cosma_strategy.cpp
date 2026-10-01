-- Avoid undefined behavior when enable_overlapping_comm_and_comp() is called
-- on an empty strategy. With n_steps() == 0, last_step becomes -1 and the
-- subsequent split_dimension[last_step] access is out-of-bounds; Clang turns
-- that path into a ud2 "privileged opcode" and the process dies with SIGILL.
-- This is exercised by the parameterized test.multiply case (3,4,5,1).

--- src/cosma/strategy.cpp.orig	2026-10-01 04:56:44 UTC
+++ src/cosma/strategy.cpp
@@ -927,6 +927,10 @@ void Strategy::enable_overlapping_comm_and_comp() {

 // enables overlapping and updates the value of the `irregular` variable
 void Strategy::enable_overlapping_comm_and_comp() {
+    if (n_steps() == 0) {
+        return;
+    }
+
     int last_step = n_steps() - 1;

     // if comm and comp are overlapped, then in the last step
