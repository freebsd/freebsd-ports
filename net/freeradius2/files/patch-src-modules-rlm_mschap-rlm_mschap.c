--- src/modules/rlm_mschap/rlm_mschap.c.orig	2010-09-28 13:03:56.000000000 +0200
+++ src/modules/rlm_mschap/rlm_mschap.c	2010-11-18 12:02:02.211071015 +0100
@@ -1273,8 +1273,9 @@
 		 *	return 'not found'.
 		 */
 		if (((smb_ctrl->vp_integer & ACB_DISABLED) != 0) ||
-		    ((smb_ctrl->vp_integer & ACB_NORMAL) == 0)) {
-			RDEBUG2("SMB-Account-Ctrl says that the account is disabled, or is not a normal account.");
+		    (((smb_ctrl->vp_integer & ACB_NORMAL) == 0) &&
+		    ((smb_ctrl->vp_integer & ACB_WSTRUST) == 0))) {
+			RDEBUG2("SMB-Account-Ctrl says that the account is disabled, or is not a normal or workstation trust account.");
 			mschap_add_reply(request, &request->reply->vps,
 					  *response->vp_octets,
 					  "MS-CHAP-Error", "E=691 R=1", 9);
