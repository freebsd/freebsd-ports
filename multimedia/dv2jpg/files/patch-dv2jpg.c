--- dv2jpg.c.orig	Sun Jun 24 00:47:02 2001
+++ dv2jpg.c	Sun Feb 23 19:45:30 2003
@@ -2,6 +2,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <fcntl.h>
+#include <string.h>
 #include <jpeglib.h>
 #include "avilib.h"
 #include "dvavilib.h"
@@ -51,10 +52,56 @@
 }
 
 
+void print_usage(void)
+{
+  printf ("Usage: dv2jpg [-w width] [-h height] <infile> <outfile>\n"
+	  "  By setting the width or height to 0, one can make dv2jpg output\n"
+	  "  video in either NTSC or PAL resoultions, whichever was set at compile\n"
+	  "  time.\n\n"
+	  "  If only one of width or height is given a positive value, and the other\n"
+	  "  left unspecified, the video will be scaled so as to keep its original aspect\n"
+	  "  ratio.\n");
+
+}
+
+void parse_command_line (int argc, char **argv, char **infile, char **outfile,
+			 long *width, long *height)
+{
+  int cntr;
+
+  for (cntr = 1; cntr < argc; cntr++) {
+    if (strcmp(argv[cntr], "-w") == 0) {
+      cntr++;
+      if (cntr == argc || (sscanf (argv[cntr], "%ld", width) != 1)) {
+	printf ("The -w option needs a valid argument!\n"); exit(1);
+      }
+    }
+    else if (strcmp(argv[cntr], "-h") == 0) {
+      cntr++;
+      if (cntr == argc || (sscanf (argv[cntr], "%ld", height) != 1)) {
+	printf ("The -h option needs a valid argument!\n"); exit(1);
+      }
+    }
+    else if (strcmp(argv[cntr], "--help") == 0) {
+      print_usage();
+      exit(0);
+    }
+    else {
+      if (*infile == NULL)
+	*infile = argv[cntr];
+      else if (*outfile == NULL)
+	*outfile = argv[cntr];
+      else
+	printf ("Argument %s ignored.\n", argv[cntr]);
+    }
+  }
+}
+
 
 int main(int ac,char **av) {
-  char *infile=av[1],*outfile=av[2];
+  char *infile = NULL,*outfile = NULL;
   long frames,width,height,audiochannels;
+  long in_width = -1, in_height = -1;
   long audiobits,audioformat,audiorate,audiobytes,audiosamps,audiobps;
   double fps;
   char *compressor;
@@ -65,14 +112,21 @@
   FILE *aufp;
   long now,left;
 
+  parse_command_line (ac, av, &infile, &outfile, &in_width, &in_height);
+  if (!infile || !outfile) {
+    print_usage();
+    exit(1);
+  }
 
-  decoder = dv_decoder_new();
-  dv_init();
+  decoder = dv_decoder_new(0, 0, 0);
+  dv_init(0, 0);
   decoder->quality = DV_QUALITY_BEST;
 
 
   printf("reading %s\n",infile);
 
+  inh=DVAVI_open_input_file(infile,1);
+
   if ((inh=DVAVI_open_input_file(infile,1))==NULL) {
     die("Can't read avi file");
   }
@@ -83,15 +137,27 @@
   width=DVAVI_video_width(inh);
   height=DVAVI_video_height(inh);
 
+  if (in_width == 0 || in_height == 0) {
 #if defined(PAL)
-  width=384;
-  height=288;
+    width=384;
+    height=288;
 #elif defined(NTSC)
-  width=352;         
-  height=240;
+    width=352;         
+    height=240;
 #else
-#error Please define either NTSC or PAL
+    #error Please define either NTSC or PAL
 #endif
+  }
+  else if (in_width * in_height < 0) {  /* Only one is positive. */
+    float ratio = (float)width/(float)height;
+    
+    if (in_width > 0)
+      in_height = (int)((float)in_width/ratio);
+    else
+      in_width = (int)((float)in_height*ratio);
+
+    width = in_width; height = in_height;
+  }
 
   fps=DVAVI_frame_rate(inh);
   compressor=DVAVI_video_compressor(inh);
@@ -136,7 +202,7 @@
         if (dv_parse_header(decoder, inbuf)<0) {
           die("Failed to parse dv image header");
         }
-    	dv_decode_full_frame(decoder, inbuf, e_dv_color_rgb, pixels, pitches);
+    	dv_decode_full_frame(decoder, inbuf, e_dv_color_rgb, pixels, (int *)pitches);
 	}
 
 
