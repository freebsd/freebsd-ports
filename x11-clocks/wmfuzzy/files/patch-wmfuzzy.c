--- wmfuzzy.c.orig	Wed Mar 17 16:58:40 2004
+++ wmfuzzy.c	Sat Mar 27 22:15:00 2004
@@ -55,10 +55,10 @@
 }
 
 void display_time(const struct tm* tm) {
+  const ApproximateTime approximation = approximate(tm, gGranularity);
+
   static char text[30];
   memset(text, 0, ARRAY_SIZE(text));  
-
-  const ApproximateTime approximation = approximate(tm, gGranularity);
 
   if (approximation.minutes == 0)
   {
