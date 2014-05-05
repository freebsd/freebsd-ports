--- ansi.c.orig	2014-04-26 04:32:54.000000000 -0700
+++ ansi.c	2014-04-29 19:08:26.631287189 -0700
@@ -569,6 +569,7 @@
 		case '0': case '1': case '2': case '3': case '4':
 		case '5': case '6': case '7': case '8': case '9':
 		  if (curr->w_NumArgs < MAXARGS)
+		  if (curr->w_NumArgs >= 0 && curr->w_NumArgs < MAXARGS)
 		    {
 		      if (curr->w_args[curr->w_NumArgs] < 100000000)
 			curr->w_args[curr->w_NumArgs] =
