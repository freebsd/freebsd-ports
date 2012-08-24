--- ./agef.c.orig	1989-02-26 23:37:25.000000000 +0100
+++ ./agef.c	2012-08-24 11:46:51.045913934 +0200
@@ -77,9 +77,11 @@
 long            sizes[MAXAGES];	/* block count */
 
 char            topdir[NAMELEN];/* our starting directory */
-long            today,
-                time();		/* today's date */
+long            today;
+time_t          time();		/* today's date */
 
+static void get_data(char *path);
+static void down(char *subdir);
 
 
 main(argc, argv)
@@ -198,6 +200,7 @@
   * Get the aged data on a file whose name is given.  If the file is a
   * directory, go down into it, and get the data from all files inside. 
   */
+static void
 get_data(path)
     char           *path;
 {
@@ -252,6 +255,7 @@
   * in there. 
   */
 
+static void
 down(subdir)
     char           *subdir;
 {
