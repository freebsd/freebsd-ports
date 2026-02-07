Fix with Clang6:

 - Weird type for buffer for fread()
 - Initialization of base through another buffer

--- src/output.cc.orig	2018-07-04 10:31:59 UTC
+++ src/output.cc
@@ -98,7 +98,7 @@ void init_file(const char *filename)
 	
 	/* Copy data */
 	while (!feof(source)) {
-		char *buf[4096] = {'\0'};
+		char buf[4096] = {'\0'};
 		int c = fread((void *)&buf[0], 1, 4096, source);
 		fwrite((void *)&buf[0], 1, c, dest);
 	}
@@ -118,7 +118,8 @@ void html_header(FILE *outfile, const char *rootpath) 
 	 * file will reside in to the top level output directory. This string
 	 * is only used if srg.outputURL is not set
 	 */
-	char *base="";
+	static char _base[]="";
+	char *base=_base;
 
 	if (strlen(srg.outputURL)==0 && strlen(rootpath)>0) {
 		base = strdup(rootpath);
@@ -173,7 +174,8 @@ void html_footer(FILE *outfile, const char *rootpath) 
 	 * file will reside in to the top level output directory. This string
 	 * is only used if srg.outputURL is not set
 	 */
-	char *base="";
+	static char _base[] = "";
+	char *base=_base;
 
 	if (strlen(srg.outputURL)==0 && strlen(rootpath)>0)
 		base = strdup(rootpath);
