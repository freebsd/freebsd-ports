--- agent/mibgroup/mibII/interfaces.c.orig	Tue Jan  4 00:51:32 2005
+++ agent/mibgroup/mibII/interfaces.c	Thu Apr  7 11:47:45 2005
@@ -399,6 +399,133 @@
     return NULL;
 }
 
+#if defined(freebsd2)
+static char    *physaddrbuf;
+static int      nphysaddrs;
+struct sockaddr_dl **physaddrs;
+
+void
+init_interfaces_setup(void)
+{
+    int             naddrs, ilen, bit;
+    static int      mib[6]
+    = { CTL_NET, PF_ROUTE, 0, AF_LINK, NET_RT_IFLIST, 0 };
+    char           *cp;
+    size_t          len;
+    struct rt_msghdr *rtm;
+    struct if_msghdr *ifm;
+    struct ifa_msghdr *ifam;
+    struct sockaddr *sa;
+
+    naddrs = 0;
+    if (physaddrs)
+        free(physaddrs);
+    if (physaddrbuf)
+        free(physaddrbuf);
+    physaddrbuf = 0;
+    physaddrs = 0;
+    nphysaddrs = 0;
+    len = 0;
+    if (sysctl(mib, 6, 0, &len, 0, 0) < 0)
+        return;
+
+    cp = physaddrbuf = malloc(len);
+    if (physaddrbuf == 0)
+        return;
+    if (sysctl(mib, 6, physaddrbuf, &len, 0, 0) < 0) {
+        free(physaddrbuf);
+        physaddrbuf = 0;
+        return;
+    }
+
+  loop:
+    ilen = len;
+    cp = physaddrbuf;
+    while (ilen > 0) {
+        rtm = (struct rt_msghdr *) cp;
+        if (rtm->rtm_version != RTM_VERSION || rtm->rtm_type != RTM_IFINFO) {
+            free(physaddrs);
+            physaddrs = 0;
+            free(physaddrbuf);
+            physaddrbuf = 0;
+        }
+        ifm = (struct if_msghdr *) rtm;
+#if defined(freebsd3) || defined(freebsd4) || defined(freebsd5)
+        if (physaddrs != 0)
+            physaddrs[naddrs] = (void *) (ifm + 1);
+        naddrs++;
+#endif
+        ilen -= ifm->ifm_msglen;
+        cp += ifm->ifm_msglen;
+        rtm = (struct rt_msghdr *) cp;
+        while (ilen > 0 && rtm->rtm_type == RTM_NEWADDR) {
+#if defined(freebsd3) || defined(freebsd4) || defined(freebsd5)
+            ilen -= rtm->rtm_msglen;
+            cp += rtm->rtm_msglen;
+#else
+            int             is_alias = 0;
+            ifam = (struct ifa_msghdr *) rtm;
+            ilen -= sizeof(*ifam);
+            cp += sizeof(*ifam);
+            sa = (struct sockaddr *) cp;
+#define ROUND(x) (((x) + sizeof(long) - 1) & ~sizeof(long))
+            for (bit = 1; bit && ilen > 0; bit <<= 1) {
+                if (!(ifam->ifam_addrs & bit))
+                    continue;
+                ilen -= ROUND(sa->sa_len);
+                cp += ROUND(sa->sa_len);
+
+                if (bit == RTA_IFA) {
+                    if (physaddrs)
+#define satosdl(sa) ((struct sockaddr_dl *)(sa))
+                        physaddrs[naddrs++]
+                            = satosdl(sa);
+                    else
+                        naddrs++;
+                }
+                sa = (struct sockaddr *) cp;
+            }
+#endif
+            rtm = (struct rt_msghdr *) cp;
+        }
+    }
+    if (physaddrs) {
+        nphysaddrs = naddrs;
+        return;
+    }
+    physaddrs = malloc(naddrs * sizeof(*physaddrs));
+    if (physaddrs == 0)
+        return;
+    naddrs = 0;
+    goto loop;
+
+}
+
+static int
+get_phys_address(int iindex, char **ap, int *len)
+{
+    int             i;
+    int             once = 1;
+
+    do {
+        for (i = 0; i < nphysaddrs; i++) {
+            if (physaddrs[i]->sdl_index == iindex)
+                break;
+        }
+        if (i < nphysaddrs)
+            break;
+        init_interfaces_setup();
+    } while (once--);
+
+    if (i < nphysaddrs) {
+        *ap = LLADDR(physaddrs[i]);
+        *len = physaddrs[i]->sdl_alen;
+        return 0;
+    }
+    return -1;
+}
+#endif
+
 #ifdef USE_SYSCTL_IFLIST
 
 static u_char  *if_list = 0;
@@ -607,10 +734,20 @@
         }
         return (u_char *) & long_return;
     case IFPHYSADDRESS:
+#if defined(freebsd2)
+        {
+            char           *cp;
+            if (get_phys_address(interface, &cp, var_len))
+                return NULL;
+            else
+                return cp;
+        }
+#else
         /*
          * XXX 
          */
         return NULL;
+#endif
     case IFADMINSTATUS:
         long_return = if_msg.ifm_flags & IFF_UP ? 1 : 2;
         return (u_char *) & long_return;
@@ -2250,129 +2387,17 @@
 u_char         *var_ifEntry(struct variable *, oid *, size_t *, int,
                             size_t *, WriteMethod ** write);
 
-static char    *physaddrbuf;
-static int      nphysaddrs;
-struct sockaddr_dl **physaddrs;
-
 void
-init_interfaces_setup(void)
+Interface_Scan_Init(void)
 {
-    int             naddrs, ilen, bit;
-    static int      mib[6]
-    = { CTL_NET, PF_ROUTE, 0, AF_LINK, NET_RT_IFLIST, 0 };
-    char           *cp;
-    size_t          len;
-    struct rt_msghdr *rtm;
-    struct if_msghdr *ifm;
-    struct ifa_msghdr *ifam;
-    struct sockaddr *sa;
-
-    naddrs = 0;
-    if (physaddrs)
-        free(physaddrs);
-    if (physaddrbuf)
-        free(physaddrbuf);
-    physaddrbuf = 0;
-    physaddrs = 0;
-    nphysaddrs = 0;
-    len = 0;
-    if (sysctl(mib, 6, 0, &len, 0, 0) < 0)
-        return;
-
-    cp = physaddrbuf = malloc(len);
-    if (physaddrbuf == 0)
-        return;
-    if (sysctl(mib, 6, physaddrbuf, &len, 0, 0) < 0) {
-        free(physaddrbuf);
-        physaddrbuf = 0;
-        return;
-    }
-
-  loop:
-    ilen = len;
-    cp = physaddrbuf;
-    while (ilen > 0) {
-        rtm = (struct rt_msghdr *) cp;
-        if (rtm->rtm_version != RTM_VERSION || rtm->rtm_type != RTM_IFINFO) {
-            free(physaddrs);
-            physaddrs = 0;
-            free(physaddrbuf);
-            physaddrbuf = 0;
-        }
-        ifm = (struct if_msghdr *) rtm;
-#if defined(freebsd3) || defined(freebsd4) || defined(freebsd5)
-        if (physaddrs != 0)
-            physaddrs[naddrs] = (void *) (ifm + 1);
-        naddrs++;
-#endif
-        ilen -= ifm->ifm_msglen;
-        cp += ifm->ifm_msglen;
-        rtm = (struct rt_msghdr *) cp;
-        while (ilen > 0 && rtm->rtm_type == RTM_NEWADDR) {
-#if defined(freebsd3) || defined(freebsd4) || defined(freebsd5)
-            ilen -= rtm->rtm_msglen;
-            cp += rtm->rtm_msglen;
-#else
-            int             is_alias = 0;
-            ifam = (struct ifa_msghdr *) rtm;
-            ilen -= sizeof(*ifam);
-            cp += sizeof(*ifam);
-            sa = (struct sockaddr *) cp;
-#define ROUND(x) (((x) + sizeof(long) - 1) & ~sizeof(long))
-            for (bit = 1; bit && ilen > 0; bit <<= 1) {
-                if (!(ifam->ifam_addrs & bit))
-                    continue;
-                ilen -= ROUND(sa->sa_len);
-                cp += ROUND(sa->sa_len);
-
-                if (bit == RTA_IFA) {
-                    if (physaddrs)
-#define satosdl(sa) ((struct sockaddr_dl *)(sa))
-                        physaddrs[naddrs++]
-                            = satosdl(sa);
-                    else
-                        naddrs++;
-                }
-                sa = (struct sockaddr *) cp;
-            }
-#endif
-            rtm = (struct rt_msghdr *) cp;
-        }
-    }
-    if (physaddrs) {
-        nphysaddrs = naddrs;
-        return;
-    }
-    physaddrs = malloc(naddrs * sizeof(*physaddrs));
-    if (physaddrs == 0)
-        return;
-    naddrs = 0;
-    goto loop;
-
 }
 
-static int
-get_phys_address(int iindex, char **ap, int *len)
+int
+Interface_Scan_Next(short *Index,
+                    char *Name,
+                    struct ifnet *Retifnet, struct in_ifaddr *Retin_ifaddr)
 {
-    int             i;
-    int             once = 1;
-
-    do {
-        for (i = 0; i < nphysaddrs; i++) {
-            if (physaddrs[i]->sdl_index == iindex)
-                break;
-        }
-        if (i < nphysaddrs)
-            break;
-        init_interfaces_setup();
-    } while (once--);
-
-    if (i < nphysaddrs) {
-        *ap = LLADDR(physaddrs[i]);
-        *len = physaddrs[i]->sdl_alen;
-        return 0;
-    }
-    return -1;
+    return 0;
 }
 
 int
