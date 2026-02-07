--- src/rw-match.c.orig	2022-08-10 16:08:24 UTC
+++ src/rw-match.c
@@ -124,7 +124,7 @@ int main(int argc, char** argv) {
   }
 
   {
-    tain_t stamp;
+    tain stamp;
     struct tm* ptm;
     struct timeval tv;
     time_t t;
@@ -187,7 +187,7 @@ int main(int argc, char** argv) {
   }
 
   {
-    tain_t stamp;
+    tain stamp;
     struct timeval tv;
     time_t t;
     if (units==units_weekday) {
