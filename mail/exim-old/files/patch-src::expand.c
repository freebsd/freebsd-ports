--- src/expand.c.orig	Tue Feb 19 12:10:43 2002
+++ src/expand.c	Wed Apr  3 18:11:56 2002
@@ -572,10 +572,9 @@
       lseek(deliver_datafile, start_offset, SEEK_SET);
       len = read(deliver_datafile, body, len);
       if (len >= 0) body[len] = 0;
-      while (*body != 0)
+      while (len > 0)
         {
-        if (*body == '\n') *body = ' ';
-        body++;
+        if (body[--len] == '\n' || body[len] == 0) body[len] = ' ';
         }
       }
     return (*ss == NULL)? "" : *ss;
