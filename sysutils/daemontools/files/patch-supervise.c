diff -urN supervise.c supervise.c
--- supervise.c	Mon Mar  6 07:21:09 2000
+++ supervise.c	Mon Apr 23 11:15:10 2001
@@ -90,7 +90,12 @@
 void trystart(void)
 {
   int f;
+  static int firstpassed = 0;
 
+  if (firstpassed)
+    sleep(1);
+  else
+    firstpassed = 1;
   switch(f = fork()) {
     case -1:
       strerr_warn4(WARNING,"unable to fork for ",dir,", sleeping 60 seconds: ",&strerr_sys);
@@ -105,7 +110,6 @@
   pid = f;
   pidchange();
   announce();
-  sleep(1);
 }
 
 void doit(void)
