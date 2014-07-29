--- xinetd/builtins.c.orig	2013-10-03 16:04:32.562080623 +0400
+++ xinetd/builtins.c	2013-10-03 16:04:57.297350342 +0400
@@ -617,7 +617,7 @@
    if( SC_IS_INTERNAL( scp ) ) {
       SC_INTERNAL(scp, nserp);
    } else {
-      exec_server(nserp);
+      child_process(nserp);
    }
 }
 
