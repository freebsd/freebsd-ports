--- mDNSPosix/mDNSUNP.c.orig	2018-06-05 21:34:11 UTC
+++ mDNSPosix/mDNSUNP.c
@@ -460,6 +460,8 @@ struct ifi_info *get_ifi_info(int family
                     ifi->ifi_netmask = (struct sockaddr*)calloc(1, sizeof(struct sockaddr_in6));
                     if (ifi->ifi_netmask == NULL) goto gotError;
                     sinptr6 = (struct sockaddr_in6 *) &ifr6.ifr_ifru.ifru_addr;
+                    /* SIOCGIFNETMASK_IN6 does not always set sin6_family */
+                    sinptr6->sin6_family = AF_INET6;
                     memcpy(ifi->ifi_netmask, sinptr6, sizeof(struct sockaddr_in6));
                 }
 #endif
