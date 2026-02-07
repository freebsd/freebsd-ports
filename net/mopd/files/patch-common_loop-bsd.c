--- common/loop-bsd.c.orig	1996-08-16 22:41:43 UTC
+++ common/loop-bsd.c
@@ -89,7 +89,7 @@ mopReadDL()
  * The list of all interfaces that are being listened to.  loop()
  * "selects" on the descriptors in this list.
  */
-struct if_info *iflist;
+extern struct if_info *iflist;
 
 void   mopProcess    __P((struct if_info *, u_char *));
 
