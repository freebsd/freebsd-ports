--- /usr/ports/security/libfwbuilder/work/libfwbuilder-2.1.12/src/fwbuilder/dns.h~	2007-07-14 16:58:54.973991313 +0200
+++ /usr/ports/security/libfwbuilder/work/libfwbuilder-2.1.12/src/fwbuilder/dns.h	2007-07-14 17:08:29.365424298 +0200
@@ -69,6 +69,7 @@
 {
 
     void init_dns() throw(FWException);
+    void *DNS_bulkBackResolve_Thread(void *);
 
 
 class HostEnt
