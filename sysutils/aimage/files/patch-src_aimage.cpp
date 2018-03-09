--- src/aimage.cpp.orig	2018-02-26 16:24:29.829120000 -0800
+++ src/aimage.cpp	2018-02-26 16:25:21.187218000 -0800
@@ -344,7 +344,7 @@
 	/* log if necessary */
 	if(logfile){
 	    fprintf(logfile,
-		    "   pagenum=%"I64d" bytes_to_write=%d bytes_written=%d lap_time=%f\n",
+		    "   pagenum=%" I64d" bytes_to_write=%d bytes_written=%d lap_time=%f\n",
 		    acbi->pagenum,
 		    acbi->bytes_to_write,
 		    acbi->bytes_written,
@@ -621,7 +621,7 @@
     int64 ret=0;
     int multiplier=1;
     char ch,junk;
-    switch(sscanf(arg,"%"I64d"%c%c",&ret,&ch,&junk)){
+    switch(sscanf(arg,"%" I64d"%c%c",&ret,&ch,&junk)){
     case 1:
 	return ret;			// no multiplier
     case 2:
