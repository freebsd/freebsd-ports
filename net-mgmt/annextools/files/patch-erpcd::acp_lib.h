--- erpcd/acp_lib.h.orig	Tue Jan 27 17:46:14 1998
+++ erpcd/acp_lib.h	Thu Sep 18 20:10:32 2003
@@ -9,7 +9,7 @@
 
 #ifndef _WIN32		/* is this needed at all? */
 struct annex_status_return {
-  int errno;
+  int xerrno;
 }; 
 #endif /* not _WIN32 */
 
