--- src/agent/subagents/freebsd/net.h.orig	2013-12-25 15:01:05 UTC
+++ src/agent/subagents/freebsd/net.h
@@ -39,6 +39,6 @@ LONG H_NetIfLink(const TCHAR *, const TC
 LONG H_NetArpCache(const TCHAR *, const TCHAR *, StringList *);
 LONG H_NetIfList(const TCHAR *, const TCHAR *, StringList *);
 LONG H_NetRoutingTable(const TCHAR *, const TCHAR *, StringList *);
-LONG H_NetIfInfoFromKVM(const TCHAR *, const TCHAR *, TCHAR *);
+LONG H_NetIfInfo(const TCHAR *, const TCHAR *, TCHAR *);
 
 #endif // __NET_H__
