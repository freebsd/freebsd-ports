commit 1ef8dc3dfbddcbe5610c276afc627c9fcfe30a65
Author: Ben Kaduk <kaduk@mit.edu>
Date:   Sat Dec 3 14:37:09 2011 -0500

    FBSD: switch afsi_SetServerIPRank implementation
    
    Upstream has removed the ia_net{,mask} elements from
    struct in_ifaddr, so we can no longer use them directly.
    Switch to passing an rx_ifaddr_t (i.e. struct ifaddr*) in instead,
    as that uses a slightly different codepath which still works
    for our purposes.
    
    We compile the kernel module with -Werror, so storing a pointer
    (memcpy return value) in an int is forbidden, hence the conditional
    declaration of 't'.
    
    Change-Id: Ifefef88a353f4bd50a714ad88afa3a6f012fa3a1
    Reviewed-on: http://gerrit.openafs.org/6203
    Tested-by: BuildBot <buildbot@rampaginggeek.com>
    Reviewed-by: Derrick Brashear <shadow@dementix.org>

diff --git a/src/afs/afs_server.c b/src/afs/afs_server.c
index ad28100..3f4e8d2 100644
--- a/src/afs/afs_server.c
+++ b/src/afs/afs_server.c
@@ -1025,7 +1025,7 @@ afsi_SetServerIPRank(struct srvAddr *sa, afs_int32 addr,
     return;
 }
 #else /* AFS_USERSPACE_IP_ADDR */
-#if (! defined(AFS_SUN5_ENV)) && (! defined(AFS_DARWIN_ENV)) && (! defined(AFS_OBSD47_ENV)) && defined(USEIFADDR)
+#if (! defined(AFS_SUN5_ENV)) && (! defined(AFS_DARWIN_ENV)) && (! defined(AFS_OBSD47_ENV)) && (! defined(AFS_FBSD_ENV)) && defined(USEIFADDR)
 void
 afsi_SetServerIPRank(struct srvAddr *sa, struct in_ifaddr *ifa)
 {
@@ -1062,7 +1062,7 @@ afsi_SetServerIPRank(struct srvAddr *sa, struct in_ifaddr *ifa)
 #endif /* IFF_POINTTOPOINT */
 }
 #endif /*(!defined(AFS_SUN5_ENV)) && defined(USEIFADDR) */
-#if (defined(AFS_DARWIN_ENV) || defined(AFS_OBSD47_ENV)) && defined(USEIFADDR)
+#if (defined(AFS_DARWIN_ENV) || defined(AFS_OBSD47_ENV) || defined(AFS_FBSD_ENV)) && defined(USEIFADDR)
 #ifndef afs_min
 #define afs_min(A,B) ((A)<(B)) ? (A) : (B)
 #endif
@@ -1071,7 +1071,11 @@ afsi_SetServerIPRank(struct srvAddr *sa, rx_ifaddr_t ifa)
 {
     struct sockaddr sout;
     struct sockaddr_in *sin;
+#if defined(AFS_DARWIN80_ENV) && !defined(UKERNEL)
     int t;
+#else
+    void *t;
+#endif
 
     afs_uint32 subnetmask, myAddr, myNet, myDstaddr, mySubnet, netMask;
     afs_uint32 serverAddr;
@@ -1393,7 +1397,7 @@ afs_SetServerPrefs(struct srvAddr *sa)
 #else
 	  TAILQ_FOREACH(ifa, &in_ifaddrhead, ia_link) {
 #endif
-	    afsi_SetServerIPRank(sa, ifa);
+	    afsi_SetServerIPRank(sa, &ifa->ia_ifa);
     }}
 #elif defined(AFS_OBSD_ENV)
     {
