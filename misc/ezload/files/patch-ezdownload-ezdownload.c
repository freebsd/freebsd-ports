--- ezdownload/ezdownload.c.orig	2004-12-24 00:14:43.000000000 +0100
+++ ezdownload/ezdownload.c	2008-10-21 16:35:22.000000000 +0200
@@ -96,7 +96,7 @@
 /* See http://www.anchorchips.com for the
  * EZ-USB Technical Reference Manual (EZUSB_TRM.pdf).
  */
-#define CPUCS 0x7f92
+static unsigned int CPUCS = 0x7f92;
 #define USBSC 0x7fd6
 
 /* This whole reading routine sucks. you could do it in
@@ -340,7 +340,7 @@
 char * progname;
 void usage() 
 {
-	fprintf(stderr, "Syntax: %s [-r] [-v] [-f hexfile] device\n", progname);
+	fprintf(stderr, "Syntax: %s [-r] [-v] [-2] [-f hexfile] device\n", progname);
 	exit(1);
 }
 
@@ -363,7 +363,7 @@
 	progname = argv[0];
 
 	/* handle the arguments */
-	while((ch = getopt(argc, argv, "xrvf:")) != -1) 
+	while((ch = getopt(argc, argv, "2xrvf:")) != -1) 
 		switch (ch) {
 		case 'v':
 			verbose++;
@@ -374,6 +374,9 @@
 		case 'f':
 			hexfile = optarg;
 			break;
+		case '2':
+			CPUCS  = 0xe600;
+			break;
 		case 'x':
 			force = 1;
 			break;
