--- metamail/uue.c.orig	1993-07-28 18:31:02 UTC
+++ metamail/uue.c
@@ -30,7 +30,7 @@ FILE *outfp;
 }
 
 
-getline (buf, size, fp)
+get_line (buf, size, fp)
 char *buf;
 int size;
 FILE *fp;
@@ -70,28 +70,28 @@ int *ctptr;
     char buf[63];
 
     while (1) {
-	if (getline (buf, sizeof buf, infp) < 0) {
+	if (get_line (buf, sizeof buf, infp) < 0) {
 	    fprintf (stderr, "Premature EOF!\n");
-	    return;
+	    return(0);
 	}
 	if (strncmp (buf, "begin", 5) == 0)
 	    break;
 	else if (buf[0] == '-' && buf[1] == '-') {
 	    if (boundaries && PendingBoundary (buf, boundaries, ctptr))
-		return;
+		return(0);
 	}
     }	
     while (1) {
-	if (getline (buf, sizeof buf, infp) < 0) {
+	if (get_line (buf, sizeof buf, infp) < 0) {
 	    fprintf (stderr, "Premature EOF!\n");
-	    return;
+	    return(0);
 	}
 	else if (strncmp (buf, "end", 5) == 0)
 	    break;
 	else if (buf[0] == '-' && buf[1] == '-') {
 	    if (boundaries && PendingBoundary (buf, boundaries, ctptr)) {
 		fprintf (stderr, "premature end of x-uue body part\n");
-		return;
+		return(0);
 	    }
 	    else {
 		fprintf (stderr, "ignoring invalid boundary marker\n");
