--- src/dvdbackup.c.orig	Mon Aug  5 02:08:39 2002
+++ src/dvdbackup.c	Tue Mar  1 05:01:19 2005
@@ -210,6 +210,7 @@
 	fprintf(stderr,"\t-v X\t\twhere X is the amount of verbosity\n");
 	fprintf(stderr,"\t-I\t\tfor information about the DVD\n");
 	fprintf(stderr,"\t-o directory\twhere directory is your backup target\n");
+	fprintf(stderr,"\t-n\t\tuse this as DVD name (if we can't get it)\n");
 	fprintf(stderr,"\t-M\t\tbackup the whole DVD\n");
 	fprintf(stderr,"\t-F\t\tbackup the main feature of the DVD\n");
 	fprintf(stderr,"\t-T X\t\tbackup title set X\n");
@@ -219,8 +220,8 @@
 	fprintf(stderr,"\t-a 0\t\tto get aspect ratio 4:3 instead of 16:9 if both are present\n");
 	fprintf(stderr,"\t-h\t\tprint a brief usage message\n");
 	fprintf(stderr,"\t-?\t\tprint a brief usage message\n\n");
-	fprintf(stderr,"\t-i is manditory\n");
-	fprintf(stderr,"\t-o is manditory except if you use -I\n");
+	fprintf(stderr,"\t-i is mandatory\n");
+	fprintf(stderr,"\t-o is mandatory except if you use -I\n");
 	fprintf(stderr,"\t-a is option to the -F switch and has no effect on other options\n");
 	fprintf(stderr,"\t-s and -e should prefereibly be used together with -t \n\n");
 	exit(1);
@@ -782,7 +783,7 @@
 	 to consider the second one a feature title we are doing two checks (biggest  + biggest - second) /second == 1
 	 and biggest%second * 3 < biggest */
 
-	if ( CheckSizeArray(size_size_array, 0, 1)  == 1 ) {
+	if ( CheckSizeArray(size_size_array, 0, 1)  == 1 && title_sets >1 ) {
 		/* We have a dual DVD with two feature films - now lets see if they have the same amount of chapters*/
 
 		chapters_1 = 0;
@@ -1530,7 +1531,7 @@
 
 	/* Seek to title of first track, which is at (track_no * 32768) + 40 */
 
-	if ( 32808 != lseek(filehandle, 32808, SEEK_SET) ) {
+	if ( 32768 != lseek(filehandle, 32768, SEEK_SET) ) {
 		close(filehandle);
 		fprintf(stderr, "Can't seek DVD device %s - check your DVD device\n", device);
 		return(1);
@@ -1538,12 +1539,18 @@
 
 	/* Read the DVD-Video title */
 
-	if ( 32 != read(filehandle, title, 32)) {
+#define	DVD_SEC_SIZ	2048
+	{
+	 char tempBuf[ DVD_SEC_SIZ ];
+
+	if ( DVD_SEC_SIZ != read(filehandle, tempBuf, DVD_SEC_SIZ)) {
 		close(filehandle);
 		fprintf(stderr, "Can't read title from DVD device %s\n", device);
 		return(1);
 	}
 
+	snprintf( title, 32, "%s", tempBuf + 40 );
+	}
 	/* Terminate the title string */
 
 	title[32] = '\0';
@@ -2164,7 +2171,7 @@
 	DVDGetTitleName(dvd,title_name);
 
 
-	fprintf(stdout,"\n\n\nDVD-Video information of the DVD with tile %s\n\n", title_name);
+	fprintf(stdout,"\n\n\nDVD-Video information of the DVD with title %s\n\n", title_name);
 
 	/* Print file structure */
 
