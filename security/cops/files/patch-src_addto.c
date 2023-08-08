--- src/addto.c.orig	1992-03-26 16:14:28.000000000 -0800
+++ src/addto.c	2023-02-14 21:35:27.391968000 -0800
@@ -26,6 +26,8 @@
 #define	LINELEN	600		/* Max chars in a line. */
 #define	SUCCESS	"Success"	/* Filename to put success messages. */
 
+#define NUL	'\0'
+
 main(argc, argv)
 int	argc;
 char	*argv[];
@@ -45,13 +47,13 @@
 		
 	tmpfile = NULL;
 		
- 	keypending[0] = NULL;
+ 	keypending[0] = NUL;
 	strcat(keypending, key);
 	strcat(keypending, " ");
 /*
  * If the uid is known, print out the comments and exit.
  */
-	filename[0] = NULL;
+	filename[0] = NUL;
 	strcat(filename, type);
 	strcat(filename, ".k");
 	if ((tmpfile = fopen(filename, "r")) == NULL)  {
@@ -82,7 +84,7 @@
 /*
  * If a duplicate, don't add it.
  */
-	filename[0] = NULL;
+	filename[0] = NUL;
 	strcat(filename, type);
 	strcat(filename, ".p");
 	if (freopen(filename, "r", tmpfile) == NULL)  {
@@ -97,7 +99,7 @@
 /*
  * Add the goal to the pending file. 
  */
-	filename[0] = NULL;
+	filename[0] = NUL;
 	strcat(filename, type);
 	strcat(filename, ".p");
 	if (freopen(filename, "a", tmpfile) == NULL)  {
@@ -109,7 +111,7 @@
 /*
  * Add the goal to the next goal (type) file.
  */
-	filename[0] = NULL;
+	filename[0] = NUL;
 	strcat(filename, type);
 	strcat(filename, ".n");
 	if (freopen(filename, "a", tmpfile) == NULL)  {
