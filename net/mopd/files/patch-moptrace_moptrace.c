--- moptrace/moptrace.c.orig	1996-08-07 22:48:04 UTC
+++ moptrace/moptrace.c
@@ -52,7 +52,7 @@ static char rcsid[] = "$Id: moptrace.c,v 1.10 1996/08/
  * The list of all interfaces that are being listened to. 
  * "selects" on the descriptors in this list.
  */
-struct if_info *iflist;
+extern struct if_info *iflist;
 
 #ifdef NO__P
 void   Loop	     (/* void */);
