--- src/agent/subagents/freebsd/net.h.orig	2014-10-02 16:59:04.000000000 +0400
+++ src/agent/subagents/freebsd/net.h	2014-10-02 16:59:10.000000000 +0400
@@ -39,6 +39,6 @@
 LONG H_NetArpCache(const TCHAR *, const TCHAR *, StringList *);
 LONG H_NetIfList(const TCHAR *, const TCHAR *, StringList *);
 LONG H_NetRoutingTable(const TCHAR *, const TCHAR *, StringList *);
-LONG H_NetIfInfoFromKVM(const TCHAR *, const TCHAR *, TCHAR *);
+LONG H_NetIfInfo(const TCHAR *, const TCHAR *, TCHAR *);
 
 #endif // __NET_H__
