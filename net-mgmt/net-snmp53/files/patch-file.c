--- agent/mibgroup/ucd-snmp/file.c.orig	Thu Dec 25 23:57:14 2003
+++ agent/mibgroup/ucd-snmp/file.c	Thu Dec 25 23:57:37 2003
@@ -91,17 +91,19 @@
 file_parse_config(const char *token, char *cptr)
 {
     char space;
+    int items;
 	
     if (fileCount < MAXFILE) {
         fileTable[fileCount].max = -1;
 
-        sscanf(cptr, "%255s%c%d",
+	memset(fileTable[fileCount].name, 0, sizeof(fileTable[0].name));
+        items = sscanf(cptr, "%255s%c%d",
                fileTable[fileCount].name, &space, &fileTable[fileCount].max);
 	/*
 	 * Log an error then return if the string scanned in was larger then
 	 * it should have been.
 	 */
-	if (space != ' ') {
+	if (items != 1 && space != ' ') {
 		snmp_log(LOG_ERR, "file_parse_config: file name scanned " \
 		    "in from line %s is too large.  fileCount = %d\n", cptr,
 		    fileCount);
