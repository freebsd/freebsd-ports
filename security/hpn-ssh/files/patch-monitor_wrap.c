--- monitor_wrap.c.orig	Tue Sep  2 14:51:17 2003
+++ monitor_wrap.c	Tue Sep 16 20:05:44 2003
@@ -894,6 +894,7 @@
 	return ((authok == 0) ? -1 : 0);
 }
 
+#ifdef SKEY
 int
 mm_skey_query(void *ctx, char **name, char **infotxt,
    u_int *numprompts, char ***prompts, u_int **echo_on)
@@ -957,6 +958,7 @@
 
 	return ((authok == 0) ? -1 : 0);
 }
+#endif
 
 void
 mm_ssh1_session_id(u_char session_id[16])
