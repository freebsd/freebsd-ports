--- src/dcalc.c.orig	Fri Jul 12 15:26:18 2002
+++ src/dcalc.c	Fri Jul 12 15:26:06 2002
@@ -3247,7 +3247,7 @@
 	    oldX = 1.0;
 
 	sprintf(fromarg, "%f %s", oldX, from);
-	argv[0] = "units";
+	argv[0] = "gunits";
 	argv[1] = "-o %.20g";
 	argv[2] = fromarg;
 	argv[3] = to;
@@ -3296,7 +3296,7 @@
 		       does not use stderr! */
 		    msg("Bad units");
 		else
-		    msg("Can't find the units program - please install it!");
+		    msg("Can't find the gunits program - please install it!");
 
 		fclose(p); /* no need to close fd[1] too */
 	    }
