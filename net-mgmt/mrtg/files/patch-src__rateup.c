--- src/rateup.c.orig	2012-05-10 05:40:49.259760823 -0300
+++ src/rateup.c	2012-05-10 05:44:32.297657818 -0300
@@ -1132,9 +1132,10 @@
   gdImageDestroy (brush_outp);
   free (lhist);
   free (graph_label);
-  if (kMG)
+  if (kMG) {
     free(short_si);
-
+    short_si = short_si_def;
+  }

 #ifdef WIN32
   /* got to remove the target under win32
@@ -1563,8 +1564,10 @@
 	}
       else
 	{
-	  strcpy (last.in, in);
-	  strcpy (last.out, out);
+	  strncpy (last.in, in, MAXL);
+	  last.in[MAXL-1]='\0';
+	  strncpy (last.out, out,MAXL);
+	  last.out[MAXL-1]='\0';
 	}
       fprintf (fo, "%lu " LLD " " LLD " " LLD " " LLD "\n",
 	       (unsigned long) now, inrate, outrate, inrate, outrate);
@@ -2114,6 +2117,7 @@
 	      history[x].in = rand () % atoi (argv[argi + 1]);
 	      history[x].out = rand () % atoi (argv[argi + 2]);
 	    }
+	   /* fallthrough */
 	case 'u':		/* Update file */
 	  if (argv[argi][1] == 'p')
 	    {
