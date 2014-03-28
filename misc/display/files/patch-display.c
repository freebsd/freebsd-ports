--- ./display.c.orig	2005-12-14 04:40:15.000000000 +0100
+++ ./display.c	2014-03-20 01:01:07.000000000 +0100
@@ -12,6 +12,10 @@
 #include <signal.h>
 #include <ctype.h>
 #include <time.h>
+#include <stdio.h>
+#include <unistd.h>
+#include <stdlib.h>
+#include <string.h>
 
 #define		DEFAULT_DELAY	5
 #define         DISPLAY_VERSION "1.2"
@@ -19,17 +23,16 @@
 static	char	*Command;
 static	int	Delay;
 
+static void die(), display(), parse_args(), usage();
+
 char lt[128];
 int ntimes;
 
-main(argc, argv)
+int main(argc, argv)
 int	argc;
 char	*argv[];
 {
   int i, c;
-  extern	void	parse_args(),
-    die(),
-    display();
   
   for(i = 0; i < 128; i++)
     {
@@ -90,7 +93,7 @@
 
 void display()
 {
-	FILE	*fp, *popen();
+	FILE	*fp;
 	int	ch;
 	char    *dt;
 	time_t  tnow;
@@ -133,7 +136,6 @@
 int	argc;
 char	*argv[];
 {
-	extern	void	usage();
 	auto	int	argn,
 			delay_found;
 
