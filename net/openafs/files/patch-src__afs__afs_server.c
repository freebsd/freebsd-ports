diff --git a/src/afs/afs_server.c b/src/afs/afs_server.c
index ad28100..cafd355 100644
--- a/src/afs/afs_server.c
+++ b/src/afs/afs_server.c
@@ -1032,7 +1032,7 @@ afsi_SetServerIPRank(struct srvAddr *sa, struct in_ifaddr *ifa)
     struct sockaddr_in *sin;
     int t;
 
-    if ((ntohl(sa->sa_ip) & ifa->ia_netmask) == ifa->ia_net) {
+    if (1) {
 	if ((ntohl(sa->sa_ip) & ifa->ia_subnetmask) == ifa->ia_subnet) {
 	    sin = IA_SIN(ifa);
 	    if (SA2ULONG(sin) == ntohl(sa->sa_ip)) {	/* ie, ME!!!  */
