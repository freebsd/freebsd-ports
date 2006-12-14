--- erpcd/acp_tcp.c.orig	Thu Dec 14 13:16:58 2006
+++ erpcd/acp_tcp.c	Thu Dec 14 13:17:32 2006
@@ -139,7 +139,7 @@
 #endif	/* _WIN32 */
 
 /* Forward Routine Declarations */
-int type_of_req();
+static int type_of_req();
 #define DOMAIN_DELIMIT '@'
 #define TLD_DELIMIT '.'
 #define REQ_TYPE_DROP 0
