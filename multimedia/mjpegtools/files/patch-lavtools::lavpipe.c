--- lavtools/lavpipe.c.orig	Thu Jul 22 18:17:47 2004
+++ lavtools/lavpipe.c	Thu Jul 22 18:18:08 2004
@@ -582,6 +582,7 @@
       mjpeg_info( "closing input %d (source %d)", i, current_index);
       decommission_pipe_source(source);
     KEEP_SOURCE:
+    ;
     }
   }
 }
