--- src/agent/subagents/freebsd/net.cpp.orig	2013-12-25 15:01:05 UTC
+++ src/agent/subagents/freebsd/net.cpp
@@ -32,7 +32,6 @@
 #include <net/if_media.h>
 #include <net/if_dl.h>
 #include <net/if_types.h>
-#include <net/if_var.h>
 #include <net/route.h>
 #include <net/iso88025.h>
 #include <netinet/if_ether.h>
@@ -40,8 +39,7 @@
 #include <ifaddrs.h>
 #include <arpa/inet.h>
 #include <net/ethernet.h>
-#include <kvm.h>
-#include <nlist.h>
+#include <ifaddrs.h>
 
 #include "net.h"
 
@@ -60,14 +58,6 @@ typedef struct t_IfList
 	int index;
 } IFLIST;
 
-struct nlist nl[] = {
-#define N_IFNET 0
-	{ (char *)"_ifnet" },
-	{ NULL },
-};
-
-kvm_t *kvmd = NULL;
-
 LONG H_NetIpForwarding(const TCHAR *pszParam, const TCHAR *pArg, TCHAR *pValue)
 {
 	int nVer = CAST_FROM_POINTER(pArg, int);
@@ -568,94 +558,66 @@ LONG H_NetIfList(const TCHAR *pszParam, 
 	return nRet;
 }
 
-LONG H_NetIfInfoFromKVM(const TCHAR *pszParam, const TCHAR *pArg, TCHAR *pValue)
+LONG H_NetIfInfo(const TCHAR *pszParam, const TCHAR *pArg, TCHAR *pValue)
 {
-	int nRet = SYSINFO_RC_SUCCESS;
 	char szArg[512];
-	u_long ifnetaddr;
-	struct ifnet ifnet;
-	struct ifnethead ifnethead;
-#if __FreeBSD__ < 5
-	char szTName[IFNAMSIZ];
-#endif
-	char szName[IFNAMSIZ];
+	struct ifaddrs *ifap, *ifa;
+	u_int index;
 
 	AgentGetParameterArgA(pszParam, 1, szArg, sizeof(szArg));
 
-	if (szArg[0] != 0)
+	if (szArg[0] == 0)
+		return SYSINFO_RC_SUCCESS;
+
+	if (szArg[0] >= '0' && szArg[0] <= '9')
+		index = atoi(szArg);
+	else
+		index = 0;
+
+	if (getifaddrs(&ifap) != 0)
 	{
-		if (szArg[0] >= '0' && szArg[0] <= '9')
-		{
-			// index
-			if (if_indextoname(atoi(szArg), szArg) != szArg)
-			{
-				// not found
-				nRet = SYSINFO_RC_ERROR;
-			}
-		}
+		return SYSINFO_RC_ERROR;
+	}
 
-		if (nRet == SYSINFO_RC_SUCCESS)
-		{
-			nRet = SYSINFO_RC_ERROR;
+	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
+		if (ifa->ifa_addr->sa_family != AF_LINK)
+			continue;
+		if (index) {
+			if (index != if_nametoindex(ifa->ifa_name))
+				continue;
+		} else if (strcmp(ifa->ifa_name, szArg) != 0)
+			continue;
 
-			if (kvmd == NULL) {
-				kvmd = kvm_openfiles(NULL, NULL, NULL, O_RDONLY, NULL);
-				if (kvmd == NULL)
-					return SYSINFO_RC_ERROR;
-				if (kvm_nlist(kvmd, nl) < 0)
-					return SYSINFO_RC_ERROR;
-				if (nl[0].n_type == 0)
-					return SYSINFO_RC_ERROR;
-			}
-			ifnetaddr = nl[N_IFNET].n_value;
-			if (kvm_read(kvmd, ifnetaddr, &ifnethead, sizeof(ifnethead)) != sizeof(ifnethead))
-				return SYSINFO_RC_ERROR;
-			ifnetaddr = (u_long)TAILQ_FIRST(&ifnethead);
-			while (ifnetaddr) {
-				if (kvm_read(kvmd, ifnetaddr, &ifnet, sizeof(ifnet)) != sizeof(ifnet))
-					return SYSINFO_RC_ERROR;
-				ifnetaddr = (u_long)TAILQ_NEXT(&ifnet, if_link);
-#if __FreeBSD__ >= 5
-				strlcpy(szName, ifnet.if_xname, sizeof(szName));
-#else
-				if (kvm_read(kvmd, ifnet.if_name, szTName, sizeof(szTName)) != sizeof(szTName))
-					return SYSINFO_RC_ERROR;
-				szTName[sizeof(szTName) - 1] = '\0';
-				snprintf(szName, sizeof(szName), "%s%d", szTName, ifnet.if_unit);
-#endif
-				if (strcmp(szName, szArg) == 0) {
-					nRet = SYSINFO_RC_SUCCESS;
-					switch((long)pArg)
-					{
-						case IF_INFO_BYTES_IN:
-							ret_uint(pValue, ifnet.if_ibytes);
-							break;
-						case IF_INFO_BYTES_OUT:
-							ret_uint(pValue, ifnet.if_obytes);
-							break;
-						case IF_INFO_IN_ERRORS:
-							ret_uint(pValue, ifnet.if_ierrors);
-							break;
-						case IF_INFO_OUT_ERRORS:
-							ret_uint(pValue, ifnet.if_oerrors);
-							break;
-						case IF_INFO_PACKETS_IN:
-							ret_uint(pValue, ifnet.if_ipackets);
-							break;
-						case IF_INFO_PACKETS_OUT:
-							ret_uint(pValue, ifnet.if_opackets);
-							break;
-						default:
-							nRet = SYSINFO_RC_UNSUPPORTED;
-							break;
-					}
-					break;
-				}
-				else
-					continue;
-			}
+#define	IFA_STAT(s)	(((struct if_data *)ifa->ifa_data)->ifi_ ## s)
+
+		switch((long)pArg)
+		{
+			case IF_INFO_BYTES_IN:
+				ret_uint(pValue, IFA_STAT(ibytes));
+				break;
+			case IF_INFO_BYTES_OUT:
+				ret_uint(pValue, IFA_STAT(obytes));
+				break;
+			case IF_INFO_IN_ERRORS:
+				ret_uint(pValue, IFA_STAT(ierrors));
+				break;
+			case IF_INFO_OUT_ERRORS:
+				ret_uint(pValue, IFA_STAT(oerrors));
+				break;
+			case IF_INFO_PACKETS_IN:
+				ret_uint(pValue, IFA_STAT(ipackets));
+				break;
+			case IF_INFO_PACKETS_OUT:
+				ret_uint(pValue, IFA_STAT(opackets));
+				break;
+			default:
+				freeifaddrs(ifap);
+				return SYSINFO_RC_UNSUPPORTED;
 		}
+		freeifaddrs(ifap);
+		return SYSINFO_RC_SUCCESS;
 	}
 
-	return nRet;
+	freeifaddrs(ifap);
+	return SYSINFO_RC_ERROR;
 }
