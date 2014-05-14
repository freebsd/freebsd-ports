--- fomalib.h.orig	2012-11-17 13:46:43.000000000 +0400
+++ fomalib.h	2014-05-07 18:16:20.000000000 +0400
@@ -298,7 +298,7 @@
 FEXPORT int save_defined();
 FEXPORT int save_stack_att();
 FEXPORT int write_prolog(struct fsm *net, char *filename);
-FEXPORT int foma_net_print(struct fsm *net, gzFile *outfile);
+FEXPORT int foma_net_print(struct fsm *net, gzFile outfile);
 
 /* Lookups */
 
