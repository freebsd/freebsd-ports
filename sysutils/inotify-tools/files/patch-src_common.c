--- src/common.c.orig	2010-02-02 14:55:19 UTC
+++ src/common.c
@@ -41,9 +41,9 @@ void print_event_descriptions() {
 }
 
 int isdir( char const * path ) {
-	static struct stat64 my_stat;
+	static struct stat my_stat;
 
-	if ( -1 == lstat64( path, &my_stat ) ) {
+	if ( -1 == lstat( path, &my_stat ) ) {
 		if (errno == ENOENT) return 0;
 		fprintf(stderr, "Stat failed on %s: %s\n", path, strerror(errno));
 		return 0;
