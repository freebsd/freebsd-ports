--- erpcd/acp_lib.c.orig	Thu Feb  5 15:14:00 1998
+++ erpcd/acp_lib.c	Thu Sep 18 20:10:32 2003
@@ -2437,7 +2437,7 @@
 int acp_annex_status_return(msg)
 struct annex_status_return *msg;
 {
-if (msg->errno == ESUCCESS)return(TRUE);
+if (msg->xerrno == ESUCCESS)return(TRUE);
 else return(FALSE);
 
 }
