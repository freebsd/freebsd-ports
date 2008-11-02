--- src/iat.c.orig	2008-11-02 05:00:31.000000000 +0300
+++ src/iat.c	2008-11-02 05:01:16.000000000 +0300
@@ -14,12 +14,20 @@
     along with this program; if not, write to the
     Free Software Foundation, Inc.,
     59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
-*/
+    */
 
 /* Support Large File */
 
+/*
+ * Modified by Dmitry E. Oboukhov <dimka@avanto.org>
+ *  [+] Use 'getopt' function;
+ *  [+] Use STDOUT as output file (if not defined);
+ *  [*] Fix percent output.
+ */
+
 #define _FILE_OFFSET_BITS 64
 
+#include <unistd.h>
 #include <getopt.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -29,6 +37,12 @@
 #define VERSION "0.1.3"
 #define BLOCK_ISO_CD 2048
 
+
+#define OPTIONS_LIST   "h"
+
+
+static char *input_file=0, *output_file=0;
+
 /* Signature for Image ISO-9660 */
 const char ISO_9660_START[] = { 
   (char) 0x01,
@@ -91,7 +105,7 @@
 };
 
 
-long img_size;
+off_t img_size;
 int  img_detect = 2;
 
 int  img_header = 0;
@@ -106,35 +120,49 @@
 
 int previous_percent=-1;
 void main_percent (int percent_bar)
-// Prints a progress bar, takes a percentage as argument.
+  // Prints a progress bar, takes a percentage as argument.
 {
   //int progress_bar, progress_space;
   
   if (percent_bar==previous_percent) return;  // Nothing changed, don't waste CPU cycles.
   
-  printf("%3d%% [:%.*s>%.*s:]\r",percent_bar,percent_bar/5,"====================",
-                                        20-(percent_bar/5),"                    ");
-
+  if (isatty(fileno(stderr)))
+  {
+  fprintf(stderr, 
+    "\r%3d%% [:%.*s>%.*s:]",
+    percent_bar,
+    percent_bar/5,
+    "====================",
+    20-(percent_bar/5),
+    "                    ");
+  }
+  else
+  {
+    if (previous_percent==-1) fprintf(stderr, "Working ");
+    if ((percent_bar/5)*5==percent_bar) fprintf(stderr, ".");
+  }
+  previous_percent=percent_bar;
 }
 
 
-void
+  void
 usage ()
 {
-
-  printf ("Web     : http://developer.berlios.de/projects/iat\n");
-  printf ("Email   : salvatore.santagati@gmail.com\n");
-  printf ("Irc     : irc.freenode.net #ignus\n");
-  printf ("Note	   : What's My Age Again? \n");
-  
-  printf ("Usage :\n");
-  printf ("iat  OPTIONS[inputfile] OPTIONS[outputfile]\n\n");
-//  printf ("OPTIONS\n");
-//  printf ("\t-i	--iso     		Generate iso image from bin image\n");
-//  printf ("\t-l	--log     		Generate log  for debug image\n");
-//  printf ("\t-v	--verbose 	 	Print verbose messages\n");
-//  printf ("\t-o --output filename       Write output to file\n");
-  printf ("\t-h --help    		Display this notice\n\n");
+  fprintf (stderr, "Web     : http://developer.berlios.de/projects/iat\n");
+  fprintf (stderr, "Email   : salvatore.santagati@gmail.com\n");
+  fprintf (stderr, "Irc     : irc.freenode.net #ignus\n\n");
+
+  fprintf (stderr, "Usage   : ");
+  fprintf (stderr, "iat  input_file [output_file.iso]\n\n");
+  fprintf (stderr, "\tIf output file name is not defined, \n"
+            "\tthen stdout will be used instead.\n");
+  //  printf ("OPTIONS\n");
+  //  printf ("\t-i	--iso     		Generate iso image from bin image\n");
+  //  printf ("\t-l	--log     		Generate log  for debug image\n");
+  //  printf ("\t-v	--verbose 	 	Print verbose messages\n");
+  //  printf ("\t-o --output filename       Write output to file\n");
+  fprintf (stderr, "\nOptions :\n");
+  fprintf (stderr, "\t-h    		Display this notice\n\n");
 }
 
 
@@ -142,15 +170,15 @@
 int image_convert()
 {
 	
-	long source_length, i;
+	off_t source_length, i;
 	char buf[2448];
 
 
-	fseek (fsource, 0L, SEEK_END);
-	source_length = (ftell (fsource) - img_offset) / img_size_sector;
+	fseeko (fsource, 0L, SEEK_END);
+	source_length = (ftello (fsource) - img_offset) / img_size_sector;
 	
 	  
-	      fseek (fsource, img_offset, SEEK_SET);
+	      fseeko (fsource, img_offset, SEEK_SET);
 
 	      {
 		for (i = 0; i < source_length; i++)
@@ -158,26 +186,29 @@
 		  {
 		    main_percent(i*100/source_length);
 		    	
-		    fseek (fsource, img_header, SEEK_CUR);
+		    fseeko (fsource, img_header, SEEK_CUR);
 		    if (fread (buf, sizeof (char),  BLOCK_ISO_CD, fsource));
 
 		    else
 		      {
-			printf ("%s\n", strerror (errno));
+        fprintf (stderr, "%s\n", strerror (errno));
 			exit (EXIT_FAILURE);
 		      };
 		    if (fwrite (buf, sizeof (char),  BLOCK_ISO_CD, fdest));
 
 		    else
 		      {
-			printf ("%s\n", strerror (errno));
+        fprintf (stderr, "%s\n", strerror (errno));
 			exit (EXIT_FAILURE);
 		      };
-		    fseek (fsource, img_ecc, SEEK_CUR);
+		    fseeko (fsource, img_ecc, SEEK_CUR);
 	      	}
 	      }
- 	printf ("100%% [:=====================:]\n");	
-return 0;
+  if (isatty(fileno(stderr)))
+    fprintf (stderr, "\rDone                           \n");
+  else
+    fprintf (stderr, " Done\n");
+  return 0;
 }
 
 
@@ -196,23 +227,23 @@
     int raw_check = 0;
 
 
-    	fseek(fsource, 0L, SEEK_END);
-    	img_size = (((ftell(fsource))) / 8);
+    	fseeko(fsource, 0L, SEEK_END);
+    	img_size = (((ftello(fsource))) / 8);
 	for (i = 0; img_detect == 2; i = i + 1)
 	{
-		fseek(fsource, 0L, SEEK_SET);
-		fseek(fsource, i, SEEK_CUR);
+		fseeko(fsource, 0L, SEEK_SET);
+		fseeko(fsource, i, SEEK_CUR);
 		fread(buf, sizeof(char), 8, fsource);
 		fread(raw, sizeof(char), 12, fsource);
 		
 		if (!memcmp(ISO_9660_START, buf, 8))
 	    	{
-	    		printf("Detect Signature ISO9660 START at %d\n", i);
+	    		fprintf(stderr, "Detect Signature ISO9660 START at %d\n", i);
 			if (block_image_start == 0) block_image_start = i ;
 		}
 			if (!memcmp(ISO_9660, buf, 8))
 	    	{
-	    		printf("Detect Signature ISO9660 at %d\n", i);
+	    		fprintf(stderr, "Detect Signature ISO9660 at %d\n", i);
 			if (block_image_end == 0)
 				{
 					block_image_end = i;
