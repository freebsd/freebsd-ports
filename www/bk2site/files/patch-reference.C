--- reference.C.orig	Fri Feb 18 21:11:01 2005
+++ reference.C	Fri Feb 18 21:17:18 2005
@@ -305,7 +305,7 @@
 string getRFC822Time (long int time){
   time_t li = time;
   struct tm * t = localtime(&li);
-  char formatedTime[100];
+  static char formatedTime[100];
   strftime(formatedTime, 100, "%a, %d %b %Y %T %Z", t);
   return formatedTime;
 }
