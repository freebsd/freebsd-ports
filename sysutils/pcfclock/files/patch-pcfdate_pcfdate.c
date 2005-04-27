--- pcfdate/pcfdate.c.orig	Tue Apr 20 07:26:04 2004
+++ pcfdate/pcfdate.c	Tue Nov 23 23:16:23 2004
@@ -162,16 +162,23 @@
 		char buf[256];
 
 		tp = localtime(&newtime);
-		strftime(buf, sizeof(buf), "%c", tp);
-		fprintf(stdout, "%s\n", buf);
+		strftime(buf, sizeof(buf), "%+", tp);
+		fprintf(stdout, "%s", buf);
 		if (verbose) {
+		  /*
 			fprintf(stdout, " - DST: \t%s\n", (
 				(timecode[8]&3)==1 ? "Yes" :
 				((timecode[8]&3)==2 ? "No" : "unknown" ))
 			);
 			fprintf(stdout, " - Sync:\t%s\n", (timecode[1] & 1 ? "Error" : "Ok"));
 			fprintf(stdout, " - Battery:\t%s\n", (timecode[8] & 4 ? "Replace" : "Ok"));
+		  */
+		  /* Not too verbose: */
+		  fprintf(stdout," [Sync: %s, Battery: %s]",
+			 (timecode[1] & 1 ? "Error" : "Ok"),
+			 (timecode[8] & 4 ? "Replace" : "Ok"));
 		}
+		fprintf(stdout, "\n");
 	}
 
 	return 0;
