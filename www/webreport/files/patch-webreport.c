--- webreport.c.org	Sat Feb  7 17:06:38 2004
+++ webreport.c	Sat Feb  7 17:06:47 2004
@@ -22,7 +22,7 @@
 #include <errno.h>
 #include <string.h>
 #include <time.h>
-#include <getopt.h>
+#include <unistd.h>
 
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -808,7 +808,7 @@
 }
 
 char *comma_string_long(in_long )
- ulong in_long;
+ unsigned long in_long;
 {
  char tmpbuf[MAX_TINY_BUF];
  static char tmpbuf1[MAX_TINY_BUF];
@@ -1866,10 +1866,10 @@
 
 report_open_files()
 {
-	strncpy( Globals.TextReportName, "/usr/tmp/webreport.text.XXXXXX", 100);
+	strncpy( Globals.TextReportName, "/var/tmp/webreport.text.XXXXXX", 100);
 	mkstemp(Globals.TextReportName);
 
-	strncpy( Globals.HTMLReportName, "/usr/tmp/webreport.html.XXXXXX", 100);
+	strncpy( Globals.HTMLReportName, "/var/tmp/webreport.html.XXXXXX", 100);
 	mkstemp(Globals.HTMLReportName);
 
 	Globals.TextReport = fopen(Globals.TextReportName, "w");
@@ -2084,7 +2084,7 @@
 			fputs( Globals.TmpBuf, fs);
 		}
 	} else {
-		fprintf( Globals.HTMLReport, 
+		fprintf(Globals.HTMLReport, 
 			"Subject: %s\n", Globals.cur_site->title);
 		fprintf( Globals.HTMLReport, 
 			"Content-Type: text/html; charset=us-ascii\n");
