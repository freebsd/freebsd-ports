--- plugger-helper.c~	2004-07-20 17:17:23.000000000 +0200
+++ plugger-helper.c	2011-12-20 20:28:35.572299134 +0100
@@ -310,10 +310,10 @@
 
   int x;
 
-  if(!(flags & H_SWALLOW)) return;
-  if(!victim) return;
-  if(!WINDOW) return;
-  if(old_parent == WINDOW) return;
+  if(!(flags & H_SWALLOW)) return 0;
+  if(!victim) return 0;
+  if(!WINDOW) return 0;
+  if(old_parent == WINDOW) return 0;
 
   switch(gobble_state)
   {
@@ -486,7 +486,7 @@
   exit(EX_UNAVAILABLE);
 }
 
-static int run(void)
+static void run(void)
 {
   char *argv[10];
   char buffer[65536];
