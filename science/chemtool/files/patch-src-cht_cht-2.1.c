
$FreeBSD$

--- src-cht/cht-2.1.c.orig	Fri Aug 30 01:25:46 2002
+++ src-cht/cht-2.1.c	Fri Aug 30 01:31:51 2002
@@ -1431,7 +1431,7 @@
 {
 #ifndef NO_TIME
     struct tm *tm;
-    long clock;
+    time_t clock;
 
     time(&clock);
     tm = localtime(&clock);
@@ -1449,7 +1449,7 @@
 Void VAXdate(s)
 char *s;
 {
-    long clock;
+    time_t clock;
     char *c;
     int i;
     static int where[] = {8, 9, 0, 4, 5, 6, 0, 20, 21, 22, 23};
@@ -1465,7 +1465,7 @@
 Void VAXtime(s)
 char *s;
 {
-    long clock;
+    time_t clock;
     char *c;
     int i;
 
