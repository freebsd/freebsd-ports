--- topo/src/extractl1.c.orig	2023-04-26 07:45:08 UTC
+++ topo/src/extractl1.c
@@ -82,8 +82,6 @@ void mark_ifaces (int termif)
 Main function
 ******************************************************************************/
 
-MOBJ *mobjlist [NB_MOBJ] ;
-
 void usage (char *progname)
 {
     fprintf (stderr, "Usage : %s [-a|-n cidr|-v vlan|-e regexp|-E regexp|-t|-m]* [-b|-B]\n", progname) ;
