--- bulk_mailer.c.orig	Wed May 24 23:34:33 2000
+++ bulk_mailer.c	Thu Sep 12 17:32:58 2002
@@ -95,11 +95,16 @@
 #include <sysexits.h>
 #include <errno.h>
 #include <time.h>
+#include <unistd.h>
+#include <stdlib.h>
 #ifdef HAVE_STRING_H
 #include <string.h>
 #endif
 #include "patchlevel.h"
 
+#define COMMAND_BUF_SIZE (32*1024)
+#define DATEBUF_SIZE (100)
+
 #ifndef PIPECOMMAND
 #define PIPECOMMAND "/usr/lib/sendmail -bs %s"
 #endif
@@ -122,9 +127,11 @@
 char *strchr();
 char *strrchr();
 #endif
+#ifndef __FreeBSD__
 char *malloc ();
 char *realloc ();
 char *mktemp ();
+#endif
 
 /*
  * (default) max different domains per envelope.
@@ -296,6 +303,7 @@
  * memory, appending a NUL to the copy.
  */
 
+/*
 static char *
 strndup (str, len)
 char *str;
@@ -307,6 +315,7 @@
     result[len] = '\0';
     return result;
 }
+*/
 
 /*
  * sort by case-folded reversed domain
@@ -337,15 +346,15 @@
 {
     char *at;
     char *ptr;
-    char *domain;
+/*    char *domain; */
     char tempbuf[1024];
-    char c;
+/*    char c; */
 
     /*
      * make sure there's room in the buffer.
      */
     if (num_addrs >= num_addr_slots) {
-	struct address *new;
+/*	struct address *new; */
 	
 	num_addr_slots += 1000;
 	if (address_list == NULL)
@@ -571,12 +580,12 @@
 open_envelope ()
 {
     FILE *fp;
-    char command_buf[32*1024];
+    char command_buf[COMMAND_BUF_SIZE];
 
     if (debug_flag)
 	fp = stderr;
     else {
-	sprintf (command_buf, PIPECOMMAND, sendmail_flags);
+	snprintf (command_buf, COMMAND_BUF_SIZE, PIPECOMMAND, sendmail_flags);
 
 	if ((fp = popen (command_buf, "w")) == NULL) {
 	    fprintf (stderr, "can't open pipe to sendmail: %s\n",
@@ -927,7 +936,7 @@
 {
     struct tm gmt;
     struct tm *lt;
-    static char datebuf[100];
+    static char datebuf[DATEBUF_SIZE];
     int gmtoff;
     char sign;
     static char *months[] = {
@@ -960,7 +969,7 @@
 	sign = '-';
 	gmtoff = -gmtoff;
     }
-    sprintf (datebuf, "%s, %d %s %04d %02d:%02d:%02d %c%02d%02d",
+    snprintf (datebuf, DATEBUF_SIZE, "%s, %d %s %04d %02d:%02d:%02d %c%02d%02d",
 	     wdays[lt->tm_wday], lt->tm_mday, months[lt->tm_mon], lt->tm_year + 1900,
 	     lt->tm_hour, lt->tm_min, lt->tm_sec,
 	     sign,
@@ -985,7 +994,7 @@
 copy_message (out, in)
 FILE *out, *in;
 {
-    int c;
+/*    int c; */
     char linebuf[32*1024];
     int has_valid_approved_hdr = 0;
     int has_resent_to_hdr = 0;
@@ -1218,14 +1227,14 @@
      */
     lines = 0;
     while (fgets (linebuf, sizeof (linebuf), in) != NULL) {
-	if (lines < 5 && 
+	if (lines < 5 && (
 	    /*
 	     * these often occur in English-text unsubscribe requests
 	     */
 	    contains (linebuf, "delete me") ||
 	    contains (linebuf, "remove me") ||
 	    contains (linebuf, "subscribe") ||
-	    contains (linebuf, "unsubscribe"))
+	    contains (linebuf, "unsubscribe")))
 	    saw_command = 1;
 	++lines;
 	fputs (linebuf, out);
@@ -1326,13 +1335,14 @@
 int argc;
 char *argv[];
 {
-    int i;
+/*    int i; */
     FILE *fp;
     FILE *tmp;
     static char template[] = "/tmp/blkXXXXXX";
     char *tempname;
-    int c;
-    char buf[1024];
+/*    int c; */
+/*    char buf[1024]; */
+    int fd;
 
     while (argc > 1 && (*argv[1] == '-' || *argv[1] == '+')) {
 	if (strcmp (argv[1], "-comment") == 0 && argc > 2) {
@@ -1513,8 +1523,9 @@
 	exit (EX_OSFILE);
     }
 
-    tempname = mktemp (template);
-    tmp = fopen (template, "w");
+    fd = mkstemp (template);
+    tempname = template;
+    tmp = fdopen (fd, "w+");
     switch (copy_message (tmp, stdin)) {
 
     case HAS_EMBEDDED_COMMAND:
@@ -1592,4 +1603,5 @@
 	
 	exit (EX_OK);
     }
+    exit (EX_OK);
 }
