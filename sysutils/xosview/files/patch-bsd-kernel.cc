--- bsd/kernel.cc.orig	2015-09-23 13:28:14 UTC
+++ bsd/kernel.cc
@@ -28,6 +28,7 @@
 #include <string.h>
 #include <err.h>
 #include <errno.h>
+#include <ifaddrs.h>
 #include <sysexits.h>
 #include <sys/types.h>
 #include <sys/queue.h>
@@ -44,7 +45,6 @@
 static const char ACPIDEV[] = "/dev/acpi";
 static const char APMDEV[] = "/dev/apm";
 static int maxcpus = 1;
-#include <net/if_var.h>
 #include <sys/ioctl.h>
 #include <sys/resource.h>
 #include <dev/acpica/acpiio.h>
@@ -114,56 +114,41 @@ static struct nlist nlst[] =
 // this later on.  This keeps the indices within the nlist constant.
 #define DUMMY_SYM "dummy_sym"
 
-#if defined(XOSVIEW_FREEBSD)
-{ "_cnt" },
-#define VMMETER_SYM_INDEX    0
-#else
-{ DUMMY_SYM },
-#define DUMMY_0
-#endif
-#if !defined(XOSVIEW_OPENBSD)
-{ "_ifnet" },
-#define IFNET_SYM_INDEX      1
-#else
-{ DUMMY_SYM },
-#define DUMMY_1
-#endif
-
 #if defined(XOSVIEW_OPENBSD)
 { "_disklist" },
-#define DISKLIST_SYM_INDEX   2
+#define DISKLIST_SYM_INDEX   0
 #else
 { DUMMY_SYM },
-#define DUMMY_2
+#define DUMMY_0
 #endif
 #if defined(XOSVIEW_NETBSD)
 { "_allevents" },
-#define ALLEVENTS_SYM_INDEX  3
+#define ALLEVENTS_SYM_INDEX  1
 { "_bufmem" },
-#define BUFMEM_SYM_INDEX     4
+#define BUFMEM_SYM_INDEX     2
 #else
 { DUMMY_SYM },
-#define DUMMY_3
+#define DUMMY_1
 { DUMMY_SYM },
-#define DUMMY_4
+#define DUMMY_2
 #endif
 #if defined(XOSVIEW_FREEBSD)
 { "_intrnames" },
-#define INTRNAMES_SYM_INDEX  5
+#define INTRNAMES_SYM_INDEX  3
 # if __FreeBSD_version >= 900040
 { "_sintrnames" },
 # else
 { "_eintrnames" },
 # endif
-#define EINTRNAMES_SYM_INDEX 6
+#define EINTRNAMES_SYM_INDEX 4
 { "_intrcnt" },
-#define INTRCNT_SYM_INDEX    7
+#define INTRCNT_SYM_INDEX    5
 # if __FreeBSD_version >= 900040
 { "_sintrcnt" },
 # else
 { "_eintrcnt" },
 # endif
-#define EINTRCNT_SYM_INDEX   8
+#define EINTRCNT_SYM_INDEX   6
 #endif
 { NULL }
 };
@@ -338,7 +323,23 @@ BSDGetPageStats(uint64_t *meminfo, uint6
 #else  /* HAVE_UVM */
 	struct vmmeter vm;
 #if defined(XOSVIEW_FREEBSD)
-	safe_kvm_read_symbol(VMMETER_SYM_INDEX, &vm, sizeof(vm));
+	size_t size = sizeof(unsigned int);
+
+#define	GET_VM_STATS(name) \
+	sysctlbyname("vm.stats.vm." #name, &vm.name, &size, NULL, 0)
+	GET_VM_STATS(v_active_count);
+	GET_VM_STATS(v_inactive_count);
+	GET_VM_STATS(v_wire_count);
+#if __FreeBSD_version < 1200017
+	GET_VM_STATS(v_cache_count);
+#endif
+	GET_VM_STATS(v_free_count);
+	GET_VM_STATS(v_page_size);
+	GET_VM_STATS(v_vnodepgsin);
+	GET_VM_STATS(v_vnodepgsout);
+	GET_VM_STATS(v_swappgsin);
+	GET_VM_STATS(v_swappgsout);
+#undef GET_VM_STATS
 #else  /* XOSVIEW_DFBSD */
 	struct vmstats vms;
 	size_t size = sizeof(vms);
@@ -353,7 +354,11 @@ BSDGetPageStats(uint64_t *meminfo, uint6
 		meminfo[0] = (uint64_t)vm.v_active_count * vm.v_page_size;
 		meminfo[1] = (uint64_t)vm.v_inactive_count * vm.v_page_size;
 		meminfo[2] = (uint64_t)vm.v_wire_count * vm.v_page_size;
+#if __FreeBSD_version < 1200017
 		meminfo[3] = (uint64_t)vm.v_cache_count * vm.v_page_size;
+#else
+		meminfo[3] = 0;
+#endif
 		meminfo[4] = (uint64_t)vm.v_free_count * vm.v_page_size;
 #else  /* XOSVIEW_DFBSD */
 		meminfo[0] = (uint64_t)vms.v_active_count * vms.v_page_size;
@@ -468,99 +473,37 @@ BSDGetCPUTimes(uint64_t *timeArray, unsi
 int
 BSDNetInit() {
 	OpenKDIfNeeded();
-#if defined(XOSVIEW_NETBSD)
-	return ValidSymbol(IFNET_SYM_INDEX);
-#else
 	return 1;
-#endif
 }
 
 void
 BSDGetNetInOut(uint64_t *inbytes, uint64_t *outbytes, const char *netIface, bool ignored) {
-	char ifname[IFNAMSIZ];
+	struct ifaddrs *ifap, *ifa;
 	*inbytes = 0;
 	*outbytes = 0;
-#if defined(XOSVIEW_OPENBSD)
-	size_t size;
-	char *buf, *next;
-	struct if_msghdr *ifm;
-	struct if_data ifd;
-	struct sockaddr_dl *sdl;
 
-	if ( sysctl(mib_ifl, 6, NULL, &size, NULL, 0) < 0 )
-		err(EX_OSERR, "BSDGetNetInOut(): sysctl 1 failed");
-	if ( (buf = (char *)malloc(size)) == NULL)
-		err(EX_OSERR, "BSDGetNetInOut(): malloc failed");
-	if ( sysctl(mib_ifl, 6, buf, &size, NULL, 0) < 0 )
-		err(EX_OSERR, "BSDGetNetInOut(): sysctl 2 failed");
+	if (getifaddrs(&ifap) != 0)
+		return;
 
-	for (next = buf; next < buf + size; next += ifm->ifm_msglen) {
+	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
 		bool skipif = false;
-		ifm = (struct if_msghdr *)next;
-		if (ifm->ifm_type != RTM_IFINFO || ifm->ifm_addrs & RTAX_IFP == 0)
-			continue;
-		ifd = ifm->ifm_data;
-		sdl = (struct sockaddr_dl *)(ifm + 1);
-		if (sdl->sdl_family != AF_LINK)
-			continue;
-		if ( strncmp(netIface, "False", 5) != 0 ) {
-			memcpy(ifname, sdl->sdl_data, (sdl->sdl_nlen >= IFNAMSIZ ? IFNAMSIZ - 1 : sdl->sdl_nlen));
-			if ( (!ignored && strncmp(sdl->sdl_data, netIface, sdl->sdl_nlen) != 0) ||
-				 ( ignored && strncmp(sdl->sdl_data, netIface, sdl->sdl_nlen) == 0) )
-				skipif = true;
-		}
-		if (!skipif) {
-			*inbytes += ifd.ifi_ibytes;
-			*outbytes += ifd.ifi_obytes;
-		}
-	}
-	free(buf);
-#else  /* XOSVIEW_OPENBSD */
-	struct ifnet *ifnetp;
-	struct ifnet ifnet;
-#if defined (XOSVIEW_NETBSD)
-	struct ifnet_head ifnethd;
-#else
-	struct ifnethead ifnethd;
-#endif
-	safe_kvm_read(nlst[IFNET_SYM_INDEX].n_value, &ifnethd, sizeof(ifnethd));
-	ifnetp = TAILQ_FIRST(&ifnethd);
 
-	while (ifnetp) {
-		bool skipif = false;
-		//  Now, dereference the pointer to get the ifnet struct.
-		safe_kvm_read((unsigned long)ifnetp, &ifnet, sizeof(ifnet));
-		strlcpy(ifname, ifnet.if_xname, sizeof(ifname));
-#if defined(XOSVIEW_NETBSD)
-		ifnetp = TAILQ_NEXT(&ifnet, if_list);
-#else
-		ifnetp = TAILQ_NEXT(&ifnet, if_link);
-#endif
-		if (!(ifnet.if_flags & IFF_UP))
+		if (ifa->ifa_addr->sa_family != AF_LINK)
 			continue;
+
 		if ( strncmp(netIface, "False", 5) != 0 ) {
-			if ( (!ignored && strncmp(ifname, netIface, 256) != 0) ||
-			     ( ignored && strncmp(ifname, netIface, 256) == 0) )
+			if ( (!ignored && strncmp(ifa->ifa_name, netIface, 256) != 0) ||
+			     ( ignored && strncmp(ifa->ifa_name, netIface, 256) == 0) )
 				skipif = true;
 		}
+#define	IFA_STAT(s)	(((struct if_data *)ifa->ifa_data)->ifi_ ## s)
 		if (!skipif) {
-#if defined(XOSVIEW_DFBSD) && __DragonFly_version > 300304
-			struct ifdata_pcpu *ifdatap = ifnet.if_data_pcpu;
-			struct ifdata_pcpu ifdata;
-			int ncpus = BSDCountCpus();
-			for (int cpu = 0; cpu < ncpus; cpu++) {
-				safe_kvm_read((unsigned long)ifdatap + cpu * sizeof(ifdata),
-				              &ifdata, sizeof(ifdata));
-				*inbytes  += ifdata.ifd_ibytes;
-				*outbytes += ifdata.ifd_obytes;
-			}
-#else
-			*inbytes  += ifnet.if_ibytes;
-			*outbytes += ifnet.if_obytes;
-#endif
+			*inbytes  += IFA_STAT(ibytes);
+			*outbytes += IFA_STAT(obytes);
 		}
+#undef IFA_STAT
 	}
-#endif  /* XOSVIEW_OPENBSD */
+	freeifaddrs(ifap);
 }
 
 
