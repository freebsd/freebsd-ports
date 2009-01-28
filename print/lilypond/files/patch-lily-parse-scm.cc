diff -u lily/parse-scm.cc~ lily/parse-scm.cc
--- lily/parse-scm.cc~	2008-09-10 06:47:20.000000000 +0200
+++ lily/parse-scm.cc	2009-01-23 17:31:48.000000000 +0100
@@ -38,9 +38,6 @@
   SCM answer = SCM_UNSPECIFIED;
   SCM form = scm_read (port);
 
-  /* Reset read_buf for scm_ftell.
-     Shouldn't scm_read () do this for us?  */
-  scm_fill_input (port);
   SCM to = scm_ftell (port);
   ps->nchars = scm_to_int (to) - scm_to_int (from);
   
