--- xinetd/builtins.c.orig	2012-05-09 16:03:17 UTC
+++ xinetd/builtins.c
@@ -617,7 +617,7 @@ static void tcpmux_handler( const struct server *serp 
    if( SC_IS_INTERNAL( scp ) ) {
       SC_INTERNAL(scp, nserp);
    } else {
-      exec_server(nserp);
+      child_process(nserp);
    }
 }
 
