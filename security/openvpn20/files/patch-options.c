--- ./options.c.orig	2011-06-20 23:21:51.000000000 +0200
+++ ./options.c	2011-06-20 23:22:06.000000000 +0200
@@ -3002,7 +3002,7 @@
 		    {
 		      if (options->inetd != -1)
 			{
-			  msg (msglevel, opterr);
+			  msg (msglevel, "%s", opterr);
 			  goto err;
 			}
 		      else
@@ -3012,7 +3012,7 @@
 		    {
 		      if (options->inetd != -1)
 			{
-			  msg (msglevel, opterr);
+			  msg (msglevel, "%s", opterr);
 			  goto err;
 			}
 		      else
@@ -3022,7 +3022,7 @@
 		    {
 		      if (name != NULL)
 			{
-			  msg (msglevel, opterr);
+			  msg (msglevel, "%s", opterr);
 			  goto err;
 			}
 		      name = p[z];
