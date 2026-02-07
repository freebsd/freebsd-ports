--- mopd/mopd.c.orig	1996-03-31 19:21:00 UTC
+++ mopd/mopd.c
@@ -54,7 +54,7 @@ static char rcsid[] = "$Id: mopd.c,v 1.14 1996/03/31 1
  * The list of all interfaces that are being listened to. 
  * "selects" on the descriptors in this list.
  */
-struct if_info *iflist;
+extern struct if_info *iflist;
 
 #ifdef NO__P
 void   Loop	     (/* void */);
