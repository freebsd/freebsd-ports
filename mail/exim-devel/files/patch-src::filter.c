Fix the message_body_size filter variable bug reported by Phil Chambers
to the exim-users mailing list on 2001-09-19 using the patch posted to
the list by the author on 2001-09-24.

--- src/filter.c.orig	Wed Aug 15 13:09:09 2001
+++ src/filter.c	Wed Sep 26 18:16:20 2001
@@ -2566,7 +2566,7 @@
 BOOL
 filter_runtest(int fd, BOOL is_system, BOOL dot_ended)
 {
-int rc, body_len, action;
+int rc, body_len, action, header_size;
 register int ch;
 BOOL yield, delivered;
 struct stat statbuf;
@@ -2658,6 +2658,7 @@
 s = message_body_end;
 body_len = 0;
 body_linecount = 0;
+header_size = message_size;
 
 if (!dot_ended && !feof(stdin))
   {
@@ -2713,6 +2714,7 @@
   }
 
 message_body[body_len] = 0;
+message_body_size = message_size - header_size;
 
 /* body_len stops at message_body_visible; it if got there, we may have
 wrapped round in message_body_end. */
