--- src/libdspam.c	2 Nov 2005 19:39:28 -0000	1.142
+++ src/libdspam.c	8 Nov 2005 15:26:44 -0000	1.143
@@ -672,6 +672,8 @@
     current_heading = (ds_header_t) node_nt->ptr;
     if (!strcmp (current_heading->heading, "Received"))
     {
+      char *data, *ptr, *tok;
+
       // detect and skip "Received: (qmail..." lines
       if (!strncmp(current_heading->data, "(qmail", 6))
       {
@@ -680,9 +682,8 @@
         continue;
       }
 
-      char *data = strdup (current_heading->data);
-      char *ptr = strstr (data, "from");
-      char *tok;
+      data = strdup (current_heading->data);
+      ptr = strstr (data, "from");
 
       if (ptr != NULL)
       {
