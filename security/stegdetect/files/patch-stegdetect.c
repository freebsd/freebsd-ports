--- stegdetect.c.orig	2004-09-03 04:01:35 UTC
+++ stegdetect.c
@@ -78,7 +78,6 @@ char *progname;
 float DCThist[257];
 float scale = 1;		/* Sensitivity scaling */
 
-static int debug = 0;
 static int quiet = 0;
 static int ispositive = 0;	/* Current images contain stego */
 static char *transformname;	/* Current transform name */
@@ -1227,7 +1226,7 @@ detect(char *filename, int scans)
 			strlcat(outbuf, quality(tmp, stars), sizeof(outbuf));
 			flag = 1;
 		}
-	no_f5:
+	no_f5:;
 	a_wasted_var = 0;
 	}
 
@@ -1267,7 +1266,7 @@ detect(char *filename, int scans)
 			strlcat(outbuf, tmp, sizeof(outbuf));
 		}
 		
-	no_invisiblesecrets:
+	no_invisiblesecrets:;
 	a_wasted_var = 0;
 	}
 
@@ -1332,7 +1331,7 @@ detect(char *filename, int scans)
 		}
 
 		free(dcts);
-	jsteg_error:
+	jsteg_error:;
 	a_wasted_var = 0;
 	}
 
