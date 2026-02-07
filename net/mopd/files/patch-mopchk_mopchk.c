--- mopchk/mopchk.c.orig	1996-08-16 22:47:15 UTC
+++ mopchk/mopchk.c
@@ -48,7 +48,7 @@ static char rcsid[] = "$Id: mopchk.c,v 1.5 1996/08/16 
  * The list of all interfaces that are being listened to.  rarp_loop()
  * "selects" on the descriptors in this list.
  */
-struct if_info *iflist;
+extern struct if_info *iflist;
 
 #ifdef NO__P
 void   Usage         (/* void */);
