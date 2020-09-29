--- mopprobe/mopprobe.c.orig	1996-08-11 22:31:43 UTC
+++ mopprobe/mopprobe.c
@@ -52,7 +52,7 @@ static char rcsid[] = "$Id: mopprobe.c,v 1.11 1996/08/
  * The list of all interfaces that are being listened to.  rarp_loop()
  * "selects" on the descriptors in this list.
  */
-struct if_info *iflist;
+extern struct if_info *iflist;
 
 #ifdef NO__P
 void   Loop	     (/* void */);
