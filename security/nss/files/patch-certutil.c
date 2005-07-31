--- cmd/certutil/certutil.c	Fri Apr 22 22:12:00 2005
+++ cmd/certutil/certutil.c	Fri Jul 22 02:02:20 2005
@@ -131,3 +131,3 @@
 	fflush (stdout);
-	if (gets (buffer) == NULL) {
+	if (fgets(buffer, sizeof buffer, stdin) == NULL) {
 	    PORT_SetError(SEC_ERROR_INPUT_LEN);
@@ -206,3 +206,3 @@
     puts (prompt);
-    gets (buffer);
+    fgets(buffer, sizeof buffer, stdin);
     if (strlen (buffer) > 0) {
@@ -1424,3 +1424,3 @@
 	fprintf(stdout, "%-25s Other to finish\n", "");
-	if (gets (buffer)) {
+	if (fgets(buffer, sizeof buffer, stdin)) {
 	    value = atoi (buffer);
@@ -1439,3 +1439,3 @@
     puts ("Is this a critical extension [y/n]? ");
-    gets (buffer);	
+    fgets(buffer, sizeof buffer, stdin);	
 
@@ -1580,3 +1580,3 @@
 
-    if (gets(buffer) == NULL) {
+    if (fgets(buffer, sizeof buffer, stdin) == NULL) {
         PORT_SetError(SEC_ERROR_INPUT_LEN);
@@ -1621,3 +1621,3 @@
   puts ("Is this a critical extension [y/n]? ");
-  gets (buffer);	
+  fgets(buffer, sizeof buffer, stdin);	
 
@@ -1650,3 +1650,3 @@
 	fprintf(stdout, "%-25s Other to finish\n", "");
-	if (gets (buffer) == NULL) {
+	if (fgets(buffer, sizeof buffer, stdin) == NULL) {
 	    PORT_SetError(SEC_ERROR_INPUT_LEN);
@@ -1664,3 +1664,3 @@
     puts ("Is this a critical extension [y/n]? ");
-    gets (buffer);	
+    fgets(buffer, sizeof buffer, stdin);	
 
@@ -1769,3 +1769,3 @@
 	puts ("Is this a CA certificate [y/n]?");
-	gets (buffer);
+	fgets(buffer, sizeof buffer, stdin);
 	basicConstraint.isCA = (buffer[0] == 'Y' || buffer[0] == 'y') ?
@@ -1774,3 +1774,3 @@
 	puts ("Enter the path length constraint, enter to skip [<0 for unlimited path]:");
-	gets (buffer);
+	fgets(buffer, sizeof buffer, stdin);
 	if (PORT_Strlen (buffer) > 0)
@@ -1784,3 +1784,3 @@
 	puts ("Is this a critical extension [y/n]? ");
-	gets (buffer);	
+	fgets(buffer, sizeof buffer, stdin);	
 	rv = CERT_AddExtension
@@ -1908,3 +1908,3 @@
 	puts ("Is this a critical extension [y/n]? ");
-	gets (buffer);	
+	fgets(buffer, sizeof buffer, stdin);	
 
@@ -1963,3 +1963,3 @@
 		fflush (stdout);
-		gets (buffer);
+		fgets(buffer, sizeof buffer, stdin);
 		/* For simplicity, use CERT_AsciiToName to converse from a string
@@ -2031,3 +2031,3 @@
 	puts ("Is this a critical extension [y/n]? ");
-	gets (buffer);	
+	fgets(buffer, sizeof buffer, stdin);	
 	
