
$FreeBSD$

--- src/flow-fanout.c.orig	Tue Aug 24 10:42:14 2004
+++ src/flow-fanout.c	Tue Aug 24 10:42:26 2004
@@ -840,8 +840,8 @@
       } /* fte.buf_size */
     
 skip1:
-
-    } /* if FD_ISSET */
+	;
+    		} /* if FD_ISSET */
 
     if (sig_quit_flag) {
       fterr_info("SIGQUIT");
