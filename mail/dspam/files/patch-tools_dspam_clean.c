Index: tools/dspam_clean.c
===================================================================
RCS file: /usr/local/cvsroot/dspam-3.2/tools/dspam_clean.c,v
retrieving revision 1.5
diff -u -r1.5 dspam_clean.c
--- tools/dspam_clean.c	25 Oct 2004 22:57:56 -0000	1.5
+++ tools/dspam_clean.c	28 Jan 2005 19:58:49 -0000
@@ -188,7 +188,7 @@
       nt_add(users, argv[i]);
   }
 
-  if (!do_probs && !do_sigs && !do_unused) {
+  if (help || !do_probs && !do_sigs && !do_unused) {
     fprintf(stderr, "%s", CLEANSYNTAX);
     _ds_destroy_attributes(agent_config);
     nt_destroy(users);

L.
