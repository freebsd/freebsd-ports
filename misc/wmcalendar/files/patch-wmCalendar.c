--- wmCalendar.c.orig	2006-09-15 09:53:37 UTC
+++ wmCalendar.c
@@ -71,7 +71,7 @@ void initValues(){
     for(i = 0; i < 12; ++i) 
 	for( j = 0; j < 6; ++j)
 	    xdMonth[j][i] = xeMonth[j][i] - xsMonth[j][i] + 1;
-    for(i = 0; i < 12; ++i) 
+    for(i = 0; i < 10; ++i) 
 	for( j = 0; j < 2; ++j)
 	    xdYear[j][i] = xeYear[j][i] - xsYear[j][i] + 1;
     for(i = 0; i < MAXBUTTON; ++i) 
