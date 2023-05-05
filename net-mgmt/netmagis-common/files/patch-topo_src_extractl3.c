--- topo/src/extractl3.c.orig	2023-04-26 07:45:37 UTC
+++ topo/src/extractl3.c
@@ -543,8 +543,6 @@ void walkl3 (FILE *fp, struct node *n)
 Main function
 ******************************************************************************/
 
-MOBJ *mobjlist [NB_MOBJ] ;
-
 void usage (char *progname)
 {
     fprintf (stderr, "Usage : %s [-a|-n cidr|-v vlan|-e regexp|-E regexp|-t|-m]* cidr ... cidr\n", progname) ;
