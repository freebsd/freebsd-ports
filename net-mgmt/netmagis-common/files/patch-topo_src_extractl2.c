--- topo/src/extractl2.c.orig	2023-04-26 07:47:11 UTC
+++ topo/src/extractl2.c
@@ -184,8 +184,6 @@ void output_vlans (FILE *fp, vlanset_t vs)
 Main function
 ******************************************************************************/
 
-MOBJ *mobjlist [NB_MOBJ] ;
-
 void usage (char *progname)
 {
     fprintf (stderr, "Usage : %s [-a|-n cidr|-v vlan|-e regexp|-E regexp|-t|-m]* [eq [iface]] vlanid\n", progname) ;
