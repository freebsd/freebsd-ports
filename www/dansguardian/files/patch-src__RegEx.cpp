--- src/RegExp.cpp.orig	2008-11-18 11:27:04.000000000 +0000
+++ src/RegExp.cpp	2012-07-05 09:03:46.555469692 +0100
@@ -161,14 +161,17 @@
 	offsets.clear();
 	lengths.clear();
 	imatched = false;
-	regmatch_t *pmatch = new regmatch_t[reg.re_nsub + 1];  // to hold result
+	int num_sub_expressions = MAX_SUB_EXPRESSIONS;
+	if(reg.re_nsub < num_sub_expressions)
+		num_sub_expressions = reg.re_nsub;
+ 	regmatch_t *pmatch = new regmatch_t[num_sub_expressions + 1];  // to hold result	
 	if (!pmatch) {  // if it failed
 		delete[]pmatch;
 		imatched = false;
 		return false;
 		// exception?
 	}
-	if (regexec(&reg, pos, reg.re_nsub + 1, pmatch, 0)) {  // run regex
+	if (regexec(&reg, pos, num_sub_expressions + 1, pmatch, 0)) {  // run regex
 		delete[]pmatch;
 		imatched = false;
 //        #ifdef DGDEBUG
@@ -182,7 +185,7 @@
 	int error = 0;
 	while (error == 0) {
 		largestoffset = 0;
-		for (i = 0; i <= (signed) reg.re_nsub; i++) {
+		for (i = 0; i <= (signed) num_sub_expressions; i++) {
 			if (pmatch[i].rm_so != -1) {
 				matchlen = pmatch[i].rm_eo - pmatch[i].rm_so;
 				submatch = new char[matchlen + 1];
@@ -199,7 +202,7 @@
 		}
 		if (largestoffset > 0) {
 			pos += largestoffset;
-			error = regexec(&reg, pos, reg.re_nsub + 1, pmatch, REG_NOTBOL);
+			error = regexec(&reg, pos, num_sub_expressions + 1, pmatch, REG_NOTBOL);
 		} else {
 			error = -1;
 		}
