--- src/common/log.c.old	Sat Aug 21 17:21:16 2004
+++ src/common/log.c	Sat Aug 21 17:21:24 2004
@@ -276,9 +276,4 @@
     char *p;
     
     BUF_COPY(logprog, name);
-
-    if( (p = getenv("LOGFILE")) )
-       log_file(p);
-    if( (p = getenv("FIDOGATE_LOGFILE")) )
-       log_file(p);
 }
