--- src/face/dir.cpp.orig        Wed Jul 28 19:36:02 2004
+++ src/face/dir.cpp     Wed Jul 28 19:45:24 2004
@@ -329,7 +329,7 @@
 short i,i1,j ;
 char  c[10] ;

-struct tm *tm1 = localtime( &file.date );
+struct tm *tm1 = localtime( (const time_t*)&file.date );
 minut  = tm1->tm_min ;
 uhr    = tm1->tm_hour ;
 tag    = tm1->tm_mday ;

