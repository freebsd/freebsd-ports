--- lib/ftfile.c	Tue Apr 24 14:07:18 2001
+++ lib/ftfile.c	Tue Apr 16 16:52:49 2002
@@ -449,7 +449,7 @@
   } else if (nest == -2) {
     sprintf(dbuf, "%2.2d-%2.2d/%2.2d-%2.2d-%2.2d/",
       (int)tm->tm_year+1900, (int)tm->tm_mon+1,
-      (int)tm->tm_year+1900, (int)tm->tm_mon+1, (int)tm->tm_mon+1);
+      (int)tm->tm_year+1900, (int)tm->tm_mon+1, (int)tm->tm_mday);
   } else if (nest == -1) {
     sprintf(dbuf, "%2.2d/%2.2d-%2.2d/%2.2d-%2.2d-%2.2d/",
       (int)tm->tm_year+1900,
