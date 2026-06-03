--- benchmark.c.orig	2025-09-08 19:02:36 UTC
+++ benchmark.c
@@ -40,8 +40,9 @@ static void
 
 /** interruptBench is used to stop the current benchmark */
 static void
-interruptBench(int) {
+interruptBench(int sig) {
   finished = true;
+  (void)sig;
 }
 
 /** print_and_clean was supposed to make the binary somewhat smaller but
