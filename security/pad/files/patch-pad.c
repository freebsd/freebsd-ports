--- pad.c.orig	Sun Jul 23 09:14:10 2000
+++ pad.c	Wed Oct 15 06:43:08 2003
@@ -31,17 +31,17 @@
 #include "pad.h"
 #include "md5.h"
 
-int main(argc, argv)
-  int argc;
-  char **argv;
-{
-  char *ifname[256], *ofname[256];                      /* Names of files */
-  FILE *ifp[256], *ofp[256];                  /* file pointers themselves */
+int main (int argc, char *argv[]) {
+
+  char *ifname[256];                         /* array of input file names */
+  char *ofname[256][FILENAME_MAX];    /* array of temp. output file names */
+  FILE *ifp[256];
+  int ofp[256];
   struct md5_ctx context[256];                            /* md5 contexts */
   unsigned char digest[256][16];                           /* md5 digests */
   unsigned char currentbyte, readbyte;   /* just a place to put new bytes */
   char *outputname=NULL;                              /* output file name */
-  char buf[256];                                /* temporary string space */
+  char buf[FILENAME_MAX];                       /* temporary string space */
   int defined_output=0, lastout, rands=-1, i, j;             /* misc ints */
   unsigned long bytecount=0, bytelimit=0; /* to limit/expand the filesize */
 
@@ -151,42 +151,42 @@
   {
     if ((j != filesize(ifp[i])) && (i != 0))
     {
-      fprintf(stderr, "Warning: Input files sizes differ. Output will match the size of the smallest input.\n");
+      fprintf(stderr, "Warning: sizes of input files differ.  Unless -s option was given,\noutput will match the size of the smallest input.\n");
       break;
     }
     j=filesize(ifp[i]);
   }
 
   /* And now to figure out the names of our output files... */
-  ofname[0] = NULL;
+  ofname[0][0] = (char)0;
   for (i=0; i<rands; i++)
   {
-    ofname[i] = tempnam("./", "pad"); /* if tmpnam doesn't like "./" and starts
-					 giving us /tmp/, this could be a
-					 problem later on when renaming */
-    ofname[i+1] = NULL;
-  }
-
-  if (defined_output)
-    ofname[i] = outputname;
-  else
-    ofname[i] = tempnam("./", "pad");
-  lastout=i;
-  ofname[i+1] = NULL;
-
-
-  /* Open the output files for writing */
-  for (i=0; ofname[i] != NULL; i++)
-  {
-    if ((ofp[i]=fopen(ofname[i], "w"))==NULL)
-    {
+    (void) strlcpy ((char*)ofname[i], "pad.XXXXXX", sizeof(ofname[i]));
+    ofp[i] = mkstemp ((char*)ofname[i]);
+    if (ofp[i] == -1) { // couldn't create file, just bail...
       fprintf(stderr,"Error opening %s: %s\n", ofname[i], strerror(errno));
       exit(1);
     }
-    ofp[i+1] = NULL;
+    ofname[i+1][0] = (char)0; /* clear next name */
+    ofp[i+1] = -1; /* clear next fd */
+  } // for i
+
+  // deal with the final file...
+  (void) strlcpy ((char*)ofname[i], "pad.XXXXXX", sizeof(ofname[i]));
+  ofp[i] = mkstemp ((char*)ofname[i]);
+  if (ofp[i] == -1) { // couldn't create file, just bail...
+    fprintf(stderr,"Error opening %s: %s\n", ofname[i], strerror(errno));
+    exit(1);
   }
+  if (defined_output) {
+    (void) rename ((char*)ofname[i], outputname);
+    (void) strlcpy ((char*)ofname[i], outputname, sizeof(ofname[i]));
+  }
+  lastout = i;
+  ofname[i+1][0] = (char)0; /* clear next name */
+  ofp[i+1] = -1; /* clear next fd */
 
-  for (i=0; ofp[i] != NULL; i++)
+  for (i=0; ofp[i] != -1; i++)
     MD5_start(&context[i]); /* start calculating md5 for each output file */
   
   /* This while() is the heart of the program - the read/write loop */
@@ -203,12 +203,12 @@
       {
         RAND_bytes(&readbyte, 1);
         MD5_feed(&context[j], readbyte);
-        fputc(readbyte, ofp[j]);
+        (void) write (ofp[j], (void*) &readbyte, 1);
         currentbyte=currentbyte^readbyte;
       }
     }
     MD5_feed(&context[lastout], currentbyte);
-    fputc(currentbyte, ofp[lastout]);
+    (void) write (ofp[lastout], (void *) &currentbyte, 1);
     bytecount++;
     if ((bytelimit && (bytecount == bytelimit)))
     { /* user's -s flag limited us to this size - we're done */
@@ -227,16 +227,16 @@
       {
         RAND_bytes(&readbyte, 1);
         MD5_feed(&context[j], readbyte);
-        fputc(readbyte, ofp[j]);
+        (void *) write (ofp[j], (void *) &readbyte, 1);
       }
       bytecount++;
     }
   }
 
   /* Close all outputs, tell MD5 processor they're finished */
-  for (i=0; ofp[i] != NULL; i++)
+  for (i=0; ofp[i] != -1; i++)
   {
-    fclose(ofp[i]);
+    (void) close(ofp[i]);
     MD5_stop(&context[i], digest[i]);
   }
 
@@ -247,20 +247,24 @@
   }
 
   /* Rename output files to match their md5-sums */
-  for (i=0; ofname[i] != NULL; i++)
+  for (i=0; ofname[i][0] != (char)0; i++)
   {
-    if ((defined_output) && (lastout == i))
-      sprintf(buf, outputname);
-    else
-      sprintf(buf, "pad-md5-%s.dat", hexize(digest[i]));
-
-    if (rename(ofname[i], buf)) /* note: no renaming across filesystems */
-      fprintf(stderr, "Error renaming: %s\n", strerror(errno));
-    else 
+    if ((defined_output) && (lastout == i)) {
+      snprintf(buf, sizeof(buf), outputname);
+    } else {
+      snprintf(buf, sizeof(buf), "pad-md5-%s.dat", hexize(digest[i]));
+    }
+    if (rename((char *)ofname[i], buf)) { /* note: no renaming across filesystems */
+      fprintf (stderr,
+	       "Error renaming file: %s (%s -> %s)\n",
+	       strerror(errno), ofname[i], buf
+	       );
+    } else {
       fprintf(stderr, "Wrote %s\n", buf);
-  }
+    }
+  } // for i
   exit(0);
-}
+} // main()
 
 /* Return size of fp passed */
 long filesize(FILE *fp)
@@ -277,24 +281,24 @@
 /* print out the help message */
 void printhelp()
 {
-  fprintf(stderr, "Usage: pad [options] [input files]
-
-options:
-
-  -r [num]    - Pad will XOR in [num] pads generated from random data. if this
-                is ommited, pad will use either 1 or 0 random pads, depending on
-                if there is only one input file or more than one, respectively.
-
-  -o [output] - The result of all the XOR operations will be stored in this
-                file. If [output] is ommitted, pad will name the file according
-                to its MD5-sum, along with the rest of the random pads.
-
-  -s [size]   - The output data will be [size] bytes. If this is less than the
-                smallest input file, the output will be clipped to match, if it
-                is larger, random data will be appended to the end.
-
-  -h          - Show usage.
-
+  fprintf(stderr, "Usage: pad [options] [input files]\n\
+\n\
+options:\n\
+\n\
+  -r [num]    - Pad will XOR in [num] pads generated from random data. if this\n\
+                is omitted, pad will use either 1 or 0 random pads, depending on\n\
+                if there is only one input file or more than one, respectively.\n\
+\n\
+  -o [output] - The result of all the XOR operations will be stored in this\n\
+                file. If [output] is omitted, pad will name the file according\n\
+                to its MD5-sum, along with the rest of the random pads.\n\
+\n\
+  -s [size]   - The output data will be [size] bytes. If this is less than the\n\
+                smallest input file, the output will be clipped to match, if it\n\
+                is larger, random data will be appended to the end.\n\
+\n\
+  -h          - Show usage.\n\
+\n\
 ");
 }
 
@@ -325,8 +329,8 @@
   buf[0] = '\0';
   for ( j=0 ; j<16 ; j++ )
   {
-    sprintf(buf, "%s%c", buf, (hexdigits[digest[j]>>4]));
-    sprintf(buf, "%s%c", buf, (hexdigits[digest[j]&0xf]));
+    snprintf(buf, sizeof(buf), "%s%c", buf, (hexdigits[digest[j]>>4]));
+    snprintf(buf, sizeof(buf), "%s%c", buf, (hexdigits[digest[j]&0xf]));
   }
   return((char *)strdup(buf));
 }
