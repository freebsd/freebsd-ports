--- otherOS/loop.c.orig	1996-08-07 23:49:12 UTC
+++ otherOS/loop.c
@@ -39,7 +39,7 @@ static char rcsid[] = "$Id: loop.c,v 1.8 1996/08/07 23
  * The list of all interfaces that are being listened to.  loop()
  * "selects" on the descriptors in this list.
  */
-struct if_info *iflist;
+extern struct if_info *iflist;
 u_char	buf[BUFSIZE];
 
 void   mopProcess   (/* struct if_info *, u_char * */);
