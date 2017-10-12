--- src/cvecheck.c.orig	2017-03-27 16:42:38 UTC
+++ src/cvecheck.c
@@ -1170,15 +1170,11 @@ int load_watch_list(struct workstate * ws) {
 			rc = delete_cpe(line, ws);
 			if (rc) {
 				fprintf(stderr, " ! An error occurred while interpreting CPE on line %d\n", linenum-1);
-				zero_string(line, CPELINESIZE);
-				continue;
 			};
 		} else {
 			rc = add_cpe(line, ws);
 			if (rc) {
 				fprintf(stderr, " ! An error occurred while interpreting CPE on line %d\n", linenum-1);
-				zero_string(line, CPELINESIZE);
-				continue;
 			};
 		};
 		zero_string(line, CPELINESIZE);
@@ -1366,9 +1362,9 @@ int load_cve(struct workstate * ws) {
 		fieldCounter = 0;
 
 		// Split based on ':' character
+		int invalid_line = 0;
 		while (sscanf(bufferptr, "%[^:]s", field) == 1) {
 			int fieldLength = swstrlen(field);	// Capture field length up front as strtok_r modifies the string
-
 			if (fieldCounter == 0) {
 				// Should be "CVE-####-####+" (CVE identifier)
 				char * sCVE;
@@ -1431,7 +1427,8 @@ int load_cve(struct workstate * ws) {
 					(strncmp(field, "/o", 2) != 0) &&
 					(strncmp(field, "/h", 2) != 0) ) {
 					fprintf(stderr, " ! Error while reading in CVE entries: CPE type in line %d is not one of a/o/h\n", linenum);
-					return 1;
+					invalid_line = 1;
+					break;
 				}
 				snprintf(tmpCpeId, 3, "%s", field);
 
@@ -1463,7 +1460,8 @@ int load_cve(struct workstate * ws) {
 			bufferptr = bufferptr + fieldLength + 1;
 			++fieldCounter;
 		}
-
+		if (invalid_line)
+			continue;
 		// Build the CPE up
 		snprintf(cpeId, CPELINESIZE, "cpe:%s:%s:%s:%s:%s:%s:%s", tmpCpeId, tmpCpeVendor, tmpCpeProduct, tmpCpeVersion, tmpCpeUpdate, tmpCpeEdition, tmpCpeLanguage);
 
