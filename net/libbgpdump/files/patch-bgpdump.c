--- bgpdump.c.old	2014-07-24 13:02:50.000000000 +0000
+++ bgpdump.c	2014-07-24 13:03:27.000000000 +0000
@@ -164,10 +164,6 @@
         exit(1);        
     }
 
-    // more efficient then line buffering
-    char buffer[16000];
-    setbuffer(stdout, buffer, sizeof buffer);
-    
     BGPDUMP *my_dump = bgpdump_open_dump(argv[0]);
     
     do {
