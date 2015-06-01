--- src/agent/subagents/freebsd/freebsd.cpp.orig	2013-12-25 15:01:05 UTC
+++ src/agent/subagents/freebsd/freebsd.cpp
@@ -48,14 +48,14 @@ static NETXMS_SUBAGENT_PARAM m_parameter
 	{ _T("FileSystem.UsedPerc(*)"),       H_DiskInfo,        (const TCHAR *)DISK_USED_PERC,    DCI_DT_FLOAT,	DCIDESC_FS_USEDPERC },
 
 	{ _T("Net.Interface.AdminStatus(*)"), H_NetIfAdmStatus,  NULL,				DCI_DT_INT,	DCIDESC_NET_INTERFACE_ADMINSTATUS },
-	{ _T("Net.Interface.BytesIn(*)"),     H_NetIfInfoFromKVM, (const TCHAR *)IF_INFO_BYTES_IN,    DCI_DT_UINT64, DCIDESC_NET_INTERFACE_BYTESIN },
-	{ _T("Net.Interface.BytesOut(*)"),    H_NetIfInfoFromKVM, (const TCHAR *)IF_INFO_BYTES_OUT,   DCI_DT_UINT64, DCIDESC_NET_INTERFACE_BYTESOUT },
-	{ _T("Net.Interface.InErrors(*)"),    H_NetIfInfoFromKVM, (const TCHAR *)IF_INFO_IN_ERRORS,   DCI_DT_UINT64, DCIDESC_NET_INTERFACE_INERRORS },
+	{ _T("Net.Interface.BytesIn(*)"),     H_NetIfInfo, (const TCHAR *)IF_INFO_BYTES_IN,    DCI_DT_UINT64, DCIDESC_NET_INTERFACE_BYTESIN },
+	{ _T("Net.Interface.BytesOut(*)"),    H_NetIfInfo, (const TCHAR *)IF_INFO_BYTES_OUT,   DCI_DT_UINT64, DCIDESC_NET_INTERFACE_BYTESOUT },
+	{ _T("Net.Interface.InErrors(*)"),    H_NetIfInfo, (const TCHAR *)IF_INFO_IN_ERRORS,   DCI_DT_UINT64, DCIDESC_NET_INTERFACE_INERRORS },
 	{ _T("Net.Interface.Link(*)"),        H_NetIfLink,       NULL,				DCI_DT_DEPRECATED,	DCIDESC_DEPRECATED },
 	{ _T("Net.Interface.OperStatus(*)"),  H_NetIfLink,       NULL,				DCI_DT_INT,	DCIDESC_NET_INTERFACE_OPERSTATUS },
-	{ _T("Net.Interface.OutErrors(*)"),   H_NetIfInfoFromKVM, (const TCHAR *)IF_INFO_OUT_ERRORS,  DCI_DT_UINT64, DCIDESC_NET_INTERFACE_OUTERRORS },
-	{ _T("Net.Interface.PacketsIn(*)"),   H_NetIfInfoFromKVM, (const TCHAR *)IF_INFO_PACKETS_IN,  DCI_DT_UINT64, DCIDESC_NET_INTERFACE_PACKETSIN },
-	{ _T("Net.Interface.PacketsOut(*)"),  H_NetIfInfoFromKVM, (const TCHAR *)IF_INFO_PACKETS_OUT, DCI_DT_UINT64, DCIDESC_NET_INTERFACE_PACKETSOUT },
+	{ _T("Net.Interface.OutErrors(*)"),   H_NetIfInfo, (const TCHAR *)IF_INFO_OUT_ERRORS,  DCI_DT_UINT64, DCIDESC_NET_INTERFACE_OUTERRORS },
+	{ _T("Net.Interface.PacketsIn(*)"),   H_NetIfInfo, (const TCHAR *)IF_INFO_PACKETS_IN,  DCI_DT_UINT64, DCIDESC_NET_INTERFACE_PACKETSIN },
+	{ _T("Net.Interface.PacketsOut(*)"),  H_NetIfInfo, (const TCHAR *)IF_INFO_PACKETS_OUT, DCI_DT_UINT64, DCIDESC_NET_INTERFACE_PACKETSOUT },
 	{ _T("Net.IP.Forwarding"),            H_NetIpForwarding, (const TCHAR *)4,			DCI_DT_INT,	DCIDESC_NET_IP_FORWARDING },
 	{ _T("Net.IP6.Forwarding"),           H_NetIpForwarding, (const TCHAR *)6,			DCI_DT_INT,	DCIDESC_NET_IP6_FORWARDING },
 
