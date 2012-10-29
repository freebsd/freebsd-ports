--- metamail/uue.c.orig	1993-07-29 03:31:02.000000000 +0900
+++ metamail/uue.c	2012-10-13 08:01:35.000000000 +0900
@@ -72,26 +72,26 @@
     while (1) {
 	if (getline (buf, sizeof buf, infp) < 0) {
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
 	if (getline (buf, sizeof buf, infp) < 0) {
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
