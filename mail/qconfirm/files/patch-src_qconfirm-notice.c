--- src/qconfirm-notice.c.orig	2004-12-12 16:57:17 UTC
+++ src/qconfirm-notice.c
@@ -386,7 +386,7 @@ int main(int argc, const char **argv) {
   }
 
   /* check for confirmation request message */
-  while ((i =getline(buffer_0, &sa)) > 0) {
+  while ((i =get_line(buffer_0, &sa)) > 0) {
     if ((i == 1) && (sa.s[0] == '\n')) break; /* end of headers */
     if (request && reply_to.s) break;
     for (i =0; i < sa.len; ++i) {
