--- src/powerman/parse_util.c.orig	2024-02-05 21:09:39 UTC
+++ src/powerman/parse_util.c
@@ -229,7 +229,7 @@ static int string_to_level(char *s)
 static int string_to_level(char *s)
 {
     int level = -1;
-    CODE *record = prioritynames;
+    const CODE *record = prioritynames;
 
     if (!s || *s == '\0')
         return -1;
