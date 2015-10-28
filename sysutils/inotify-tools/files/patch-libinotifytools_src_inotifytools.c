--- libinotifytools/src/inotifytools.c.orig	2010-02-02 14:55:19 UTC
+++ libinotifytools/src/inotifytools.c
@@ -1309,14 +1309,14 @@ int inotifytools_watch_recursively_with_
 
 	static struct dirent * ent;
 	char * next_file;
-	static struct stat64 my_stat;
+	static struct stat my_stat;
 	ent = readdir( dir );
 	// Watch each directory within this directory
 	while ( ent ) {
 		if ( (0 != strcmp( ent->d_name, "." )) &&
 		     (0 != strcmp( ent->d_name, ".." )) ) {
 			nasprintf(&next_file,"%s%s", my_path, ent->d_name);
-			if ( -1 == lstat64( next_file, &my_stat ) ) {
+			if ( -1 == lstat( next_file, &my_stat ) ) {
 				error = errno;
 				free( next_file );
 				if ( errno != EACCES ) {
@@ -1595,9 +1595,9 @@ int inotifytools_error() {
  * @internal
  */
 int isdir( char const * path ) {
-	static struct stat64 my_stat;
+	static struct stat my_stat;
 
-	if ( -1 == lstat64( path, &my_stat ) ) {
+	if ( -1 == lstat( path, &my_stat ) ) {
 		if (errno == ENOENT) return 0;
 		fprintf(stderr, "Stat failed on %s: %s\n", path, strerror(errno));
 		return 0;
