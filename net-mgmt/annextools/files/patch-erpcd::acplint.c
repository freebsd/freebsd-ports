--- erpcd/acplint.c.orig	Thu Dec 14 13:27:34 2006
+++ erpcd/acplint.c	Thu Dec 14 13:29:12 2006
@@ -60,7 +60,8 @@
 #endif
 
 void uprof_dump();
- 
+static void usage();
+
 char *err_text[] = {
     "ACPU_ESUCCESS",
     "ACPU_ESKIP",
@@ -87,7 +88,6 @@
 	int opt, flags = 0;
 	Uprof uprof;
 	Access access;
-	static void usage();
 	struct environment_spec env, *env_p = &env;
 
 
