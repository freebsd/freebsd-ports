--- tvchannels.c.orig	Tue Aug 16 20:12:35 2005
+++ tvchannels.c	Tue Aug 16 20:17:07 2005
@@ -106,6 +106,7 @@
           (*chan)->freq = freq;
           (*chan)->next = NULL;
 chan_done:
+	  ;
         } else {
           fprintf(stderr, "%s:%d: Warning: Frequency out of range, line ignored:\n%s\n",
               FNAME, lcount, line);
