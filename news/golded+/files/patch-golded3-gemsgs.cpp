--- golded3/gemsgs.cpp.orig	Sun Nov  2 20:05:14 2003
+++ golded3/gemsgs.cpp	Sun Nov  2 20:04:49 2003
@@ -55,7 +55,7 @@
   va_list a;
   va_start(a, cnt);
   for(int i = 0; i < cnt; i ++) {
-    use = va_arg(a, bool);
+    use = va_arg(a, int);
     if(dst[toklen] == '{') {
       char *p = strchr(dst+toklen, '}');
       if(p) {
