--- src/filter.c.orig	Tue Feb 19 12:10:43 2002
+++ src/filter.c	Wed Apr  3 18:11:56 2002
@@ -2566,12 +2566,12 @@
 BOOL
 filter_runtest(int fd, BOOL is_system, BOOL dot_ended)
 {
-int rc, body_len, action, header_size;
+int rc, body_len, body_end_len, action, header_size;
 register int ch;
 BOOL yield, delivered;
 struct stat statbuf;
 address_item *generated = NULL;
-char *body, *error, *filebuf, *s;
+char *error, *filebuf, *s;
 
 /* Read the filter file into store as will be done by the director
 in a real case. */
@@ -2653,7 +2653,7 @@
 function as efficient as possible. Handling message_body_end is somewhat more
 tedious. Pile it all into a circular buffer and sort out at the end. */
 
-message_body = body = store_malloc(message_body_visible + 1);
+message_body = store_malloc(message_body_visible + 1);
 message_body_end = store_malloc(message_body_visible + 1);
 s = message_body_end;
 body_len = 0;
@@ -2729,24 +2729,25 @@
     memcpy(temp, message_body_end, below);
     memmove(message_body_end, s+1, above);
     memcpy(message_body_end + above, temp, below);
-    message_body_end[message_body_visible] = 0;
+    s = message_body_end + message_body_visible;
     }
   }
-else *s = 0;
 
-/* Convert newlines in the body variables to spaces */
+*s = 0;
+body_end_len = s - message_body_end;
 
-while (*body != 0)
+/* Convert newlines and nulls in the body variables to spaces */
+while (body_len > 0)
   {
-  if (*body == '\n') *body = ' ';
-  body++;
+  if (message_body[--body_len] == '\n' || message_body[body_len] == 0)
+    message_body[body_len] = ' ';
   }
 
-body = message_body_end;
-while (*body != 0)
+while (body_end_len > 0)
   {
-  if (*body == '\n') *body = ' ';
-  body++;
+  if (message_body_end[--body_end_len] == '\n' ||
+      message_body_end[body_end_len] == 0)
+    message_body_end[body_end_len] = ' ';
   }
 
 /* Now pass the filter file to the function that interprets it. Because
