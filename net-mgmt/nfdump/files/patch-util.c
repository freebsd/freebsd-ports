
$FreeBSD$

--- util.c.orig
+++ util.c
@@ -301,6 +301,7 @@
 static char timestring[16];
 
 	when = localtime(&t);
+	when->tm_isdst = -1;
 	snprintf(timestring, 15, "%i%02i%02i%02i%02i", 
 		when->tm_year + 1900, when->tm_mon + 1, when->tm_mday, when->tm_hour, when->tm_min);
 	timestring[15] = '\0';
@@ -320,6 +321,7 @@
 	when.tm_sec  = 0;
 	when.tm_wday = 0;
 	when.tm_yday = 0;
+	when.tm_isdst = -1;
 
 	if ( strlen(timestring) != 12 ) {
 		LogError( "Wrong time format '%s'\n", timestring);
