--- src/vm/vm.c.orig	2014-01-30 07:10:55.000000000 +0100
+++ src/vm/vm.c	2014-01-30 07:13:13.000000000 +0100
@@ -179,7 +179,7 @@
         if (off == ( (off_t) DVD_VIDEO_LB_LEN )) {
           fprintf(MSG_OUT, "libdvdnav: DVD Title: ");
           for(i=25; i < 73; i++ ) {
-            if((data[i] == 0)) break;
+            if(data[i] == 0) break;
             if((data[i] > 32) && (data[i] < 127)) {
               fprintf(MSG_OUT, "%c", data[i]);
             } else {
@@ -190,7 +190,7 @@
           name[48] = 0;
           fprintf(MSG_OUT, "\nlibdvdnav: DVD Serial Number: ");
           for(i=73; i < 89; i++ ) {
-            if((data[i] == 0)) break;
+            if(data[i] == 0) break;
             if((data[i] > 32) && (data[i] < 127)) {
               fprintf(MSG_OUT, "%c", data[i]);
             } else {
@@ -201,7 +201,7 @@
           serial[14] = 0;
           fprintf(MSG_OUT, "\nlibdvdnav: DVD Title (Alternative): ");
           for(i=89; i < 128; i++ ) {
-            if((data[i] == 0)) break;
+            if(data[i] == 0) break;
             if((data[i] > 32) && (data[i] < 127)) {
               fprintf(MSG_OUT, "%c", data[i]);
             } else {
