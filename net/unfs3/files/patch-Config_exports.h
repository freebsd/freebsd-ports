--- Config/exports.h.orig	2021-09-06 22:17:18 UTC
+++ Config/exports.h
@@ -22,7 +22,7 @@
 extern exports	exports_nfslist;
 /* Options cache */
 extern int	exports_opts;
-const char      *export_path; 
+extern const char      *export_path; 
 extern uint32 	export_fsid;
 extern uint32   export_password_hash;
 
