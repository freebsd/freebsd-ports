--- ansi.c.orig	Mon Sep  8 07:24:44 2003
+++ ansi.c	Mon Dec  1 17:17:17 2003
@@ -559,7 +559,7 @@
 	    {
 	    case '0': case '1': case '2': case '3': case '4':
 	    case '5': case '6': case '7': case '8': case '9':
-	      if (curr->w_NumArgs < MAXARGS)
+	      if (curr->w_NumArgs >= 0 && curr->w_NumArgs < MAXARGS)
 		{
 		  if (curr->w_args[curr->w_NumArgs] < 100000000)
 		    curr->w_args[curr->w_NumArgs] =
