--- dolly.c.orig	Fri Jul 16 13:04:17 2004
+++ dolly.c	Fri Jul 16 13:06:23 2004
@@ -200,7 +200,7 @@
     if((sp = strchr(sp2, ' ')) == NULL) {
       sp = sp2 + strlen(sp2);
     }
-    if(compressed_in && (strncmp(&sp2[sp - sp2 - 3], ".gz", 3) != 0)) {
+    if(compressed_in && (strncmp(&sp2[sp - sp2 - 4], ".bz2", 4) != 0)) {
       char tmp_str[256];
       strncpy(tmp_str, sp2, sp - sp2);
       tmp_str[sp - sp2] = '\0';
@@ -235,7 +235,7 @@
     if((sp = strchr(sp2, ' ')) == NULL) {
       sp = sp2 + strlen(sp2);
     }
-    if(compressed_out && (strncmp(&sp2[sp - sp2 - 3], ".gz", 3) != 0)) {
+    if(compressed_out && (strncmp(&sp2[sp - sp2 - 4], ".bz2", 4) != 0)) {
       char tmp_str[256];
       strncpy(tmp_str, sp2, sp - sp2);
       tmp_str[sp - sp2] = '\0';
