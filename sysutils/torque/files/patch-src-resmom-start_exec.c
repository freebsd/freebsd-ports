--- src/resmom/start_exec.c.orig	Sat Nov 18 15:11:38 2006
+++ src/resmom/start_exec.c	Sat Nov 18 15:12:18 2006
@@ -4772,7 +4772,7 @@
 
           return(-1);
           }
-        if (statbuf.st_gid != exgid)
+        if (statbuf.st_gid != exgid && statbuf.st_gid != 0)
           {
           log_err(-1,"open_std_file","std file exists with the wrong group, someone is doing something fishy");
 
