Index: src/ne_dates.c
===================================================================
RCS file: /home/cvs/neon/src/ne_dates.c,v
retrieving revision 1.28.2.1
diff -u -r1.28.2.1 ne_dates.c
--- src/ne_dates.c	2 May 2004 16:00:35 -0000	1.28.2.1
+++ src/ne_dates.c	2 May 2004 18:21:53 -0000
@@ -47,7 +47,7 @@
 /* RFC1123: Sun, 06 Nov 1994 08:49:37 GMT */
 #define RFC1123_FORMAT "%3s, %02d %3s %4d %02d:%02d:%02d GMT"
 /* RFC850:  Sunday, 06-Nov-94 08:49:37 GMT */
-#define RFC1036_FORMAT "%s %2d-%3s-%2d %2d:%2d:%2d GMT"
+#define RFC1036_FORMAT "%10s %2d-%3s-%2d %2d:%2d:%2d GMT"
 /* asctime: Wed Jun 30 21:49:08 1993 */
 #define ASCTIME_FORMAT "%3s %3s %2d %2d:%2d:%2d %4d"

@@ -133,7 +133,7 @@
 time_t ne_rfc1123_parse(const char *date)
 {
     struct tm gmt = {0};
-    static char wkday[4], mon[4];
+    char wkday[4], mon[4];
     int n;
 /*  it goes: Sun, 06 Nov 1994 08:49:37 GMT */
     n = sscanf(date, RFC1123_FORMAT,
@@ -156,7 +156,7 @@
 {
     struct tm gmt = {0};
     int n;
-    static char wkday[10], mon[4];
+    char wkday[11], mon[4];
     /* RFC850/1036 style dates: Sunday, 06-Nov-94 08:49:37 GMT */
     n = sscanf(date, RFC1036_FORMAT,
 		wkday, &gmt.tm_mday, mon, &gmt.tm_year,
@@ -189,7 +189,7 @@
 {
     struct tm gmt = {0};
     int n;
-    static char wkday[4], mon[4];
+    char wkday[4], mon[4];
     n = sscanf(date, ASCTIME_FORMAT,
 		wkday, mon, &gmt.tm_mday,
 		&gmt.tm_hour, &gmt.tm_min, &gmt.tm_sec,
