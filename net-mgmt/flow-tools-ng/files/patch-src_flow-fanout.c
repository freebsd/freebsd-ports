--- src/flow-fanout.c.orig	2008-01-28 05:48:55.000000000 +0900
+++ src/flow-fanout.c	2008-08-02 02:18:10.000000000 +0900
@@ -854,6 +854,7 @@
     } /* if FD_ISSET */
 
 skip1:
+	;
 
     if (sig_quit_flag) {
       fterr_info("SIGQUIT");
