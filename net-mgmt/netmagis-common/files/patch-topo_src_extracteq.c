--- topo/src/extracteq.c.orig	2023-04-26 07:47:44 UTC
+++ topo/src/extracteq.c
@@ -205,8 +205,6 @@ void output_vlan (FILE *fp, vlan_t v, struct vlan *vob
 Main function
 ******************************************************************************/
 
-MOBJ *mobjlist [NB_MOBJ] ;
-
 void usage (char *progname)
 {
     fprintf (stderr, "Usage : %s [-a|-n cidr|-v vlan|-e regexp|-E regexp|-t|-m]* eq [iface]\n", progname) ;
