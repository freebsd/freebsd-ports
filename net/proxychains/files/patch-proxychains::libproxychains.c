--- proxychains/libproxychains.c.orig	Fri May  7 11:34:59 2004
+++ proxychains/libproxychains.c	Thu Jun 24 10:54:27 2004
@@ -73,7 +73,7 @@
 
    if(!(file=fopen("./proxychains.conf","r")))
         if(!(file=fopen(buff,"r")))
-                if(!(file=fopen("/etc/proxychains.conf","r")))
+                if(!(file=fopen(PREFIX_DIR "/etc/proxychains.conf","r")))
                 {
                         perror("Can't locate proxychains.conf");
                         exit(1);
