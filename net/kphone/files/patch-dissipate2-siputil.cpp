--- dissipate2/siputil.cpp.orig	Sun Oct 17 15:37:31 2004
+++ dissipate2/siputil.cpp	Sun Oct 17 15:37:15 2004
@@ -5,6 +5,9 @@
 #include <sys/time.h>
 #include <sys/errno.h>
 #include <sys/ioctl.h>
+#if defined (__FreeBSD__) || defined(__NetBSD__)
+#include <ifaddrs.h>
+#endif
 #include <net/if_arp.h>
 #include <net/route.h>
 #include <net/if.h>
@@ -25,6 +28,8 @@
 /* max number of network interfaces*/
 #define MAX_IF 5
 
+#ifdef __linux__
+
 /* Path to the route entry in proc filesystem */
 #define PROCROUTE "/proc/net/route"
 
@@ -40,6 +45,8 @@
 #define SIOCGIFCOUNT 0x8935
 #endif
 
+#endif /* not Linux */
+
 char iface[16];
 
 
@@ -61,6 +68,7 @@
  */
 char *getdefaultdev()
 {
+#ifdef __linux__
 	FILE *fp = fopen( PROCROUTE, "r");
 	char buff[4096], gate_addr[128], net_addr[128];
 	char mask_addr[128];
@@ -84,6 +92,8 @@
 			return iface;
 	}
 	fclose(fp);
+#endif /* Linux */
+
 /* didn't find a default gateway */
 	return NULL;
 }
@@ -91,12 +101,38 @@
 
 void findFqdn( void )
 {
-	int sock, err, if_count, i, j = 0;
+	int if_count, i, j = 0;
+#if !(defined(__FreeBSD__) || defined(__NetBSD__))
+        int sock, err;
 	struct ifconf netconf;
 	char buffer[32*MAX_IF];
-	char if_name[10][21];
-	char if_addr[10][21];
+#endif
+	char if_name[MAX_IF][21];
+	char if_addr[MAX_IF][21];
 	char *default_ifName;
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+        struct ifaddrs *ifp, *oifp;
+        
+        if(getifaddrs(&ifp) < 0 )
+                printf( "Error with getifaddrs(): %i.\n", errno );
+        oifp=ifp; /* save ifp */
+        for (if_count = 0; ifp != NULL; ifp = ifp->ifa_next) {
+                if(ifp->ifa_addr->sa_family != AF_INET) continue;
+
+        if ( strncmp( ifp->ifa_name, "lo", 2 ) != 0 ) {
+                if(j == MAX_IF) printf( "Error: cannot handle more than %d interfaces.\n",MAX_IF);
+                else
+                {
+                        strncpy( if_name[j], ifp->ifa_name, 20);
+                        strncpy( if_addr[j], inet_ntoa(((struct sockaddr_in *)ifp->ifa_addr)->sin_addr ), 20);
+                        j++;
+                }
+                }
+        if_count++;
+        }
+        if (oifp != NULL) freeifaddrs(oifp);
+
+#else /* not FreeBSD or NetBSD */
 	netconf.ifc_len = 32 * MAX_IF;
 	netconf.ifc_buf = buffer;
 	sock=socket( PF_INET, SOCK_DGRAM, 0 );
@@ -104,9 +140,11 @@
 	if ( err < 0 ) printf( "Error in ioctl: %i.\n", errno );
 	close( sock );
 	if_count = netconf.ifc_len / 32;
+#endif
 	printf( "Found %i interfaces.\n", if_count );
 
 //#test
+#if !(defined(__FreeBSD__) || defined(__NetBSD__))
 	if ( if_count == 1 ) {
 		strncpy( if_name[j], netconf.ifc_req[0].ifr_name, 20 );
 		strncpy( if_addr[j], inet_ntoa(((struct sockaddr_in*)(&netconf.ifc_req[0].ifr_addr))->sin_addr), 20 );
@@ -120,13 +158,15 @@
 			}
 		}
 	}
+#endif /* not FreeBSD or NetBSD */
+
 	if( j == 1 ) {
 		dissipate_our_fqdn = strdup( if_addr[0] );
 	} else {
 		default_ifName = getdefaultdev();
-		if( default_ifName != NULL) {
+		/*if( default_ifName != NULL) {*/
 			for( i = 0; i < j; i++ ) {
-				if( strcmp( if_name[i], default_ifName ) == 0 ) {
+				if( default_ifName != NULL && strcmp( if_name[i], default_ifName ) == 0 ) {
 					QMessageBox mb( "KPhone",
 						"KPhone found more than one interface.\n"
 						"Do you want to use the default interface:\n\n" +
@@ -147,7 +187,7 @@
 				}
 			}
 			for( i = 0; i < j; i++ ) {
-				if( strcmp( if_name[i], default_ifName ) != 0 ) {
+				if(default_ifName == NULL || strcmp( if_name[i], default_ifName ) != 0 ) {
 					if( i == j-1 ) {
 						QMessageBox mb( "KPhone",
 							"Do you want to use " + QString(if_name[i]) + "  (IP:\"" + QString(if_addr[i]) + "\")",
@@ -181,7 +221,7 @@
 					}
 				}
 			}
-		}
+		/*}*/
 	}
 }
 
