--- ./src/pwman.c.orig	2010-09-14 02:40:54.339906437 +0000
+++ ./src/pwman.c	2010-09-14 02:41:09.300167146 +0000
@@ -169,6 +169,7 @@
 int
 main(int argc, char *argv[])
 {
+    setenv("LC_ALL", "C", 1);
 	pwman_init(argc, argv);
 
 	ui_run();
