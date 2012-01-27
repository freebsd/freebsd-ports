--- ./snmplib/system.c.orig	2012-01-27 10:01:51.000000000 -0500
+++ ./snmplib/system.c	2012-01-27 10:04:22.000000000 -0500
@@ -933,17 +933,15 @@
 {
 #if HAVE_GETHOSTBYADDR
     struct hostent *hp = NULL;
-    struct sockaddr_in *saddr_in =
-        NETSNMP_REMOVE_CONST(struct sockaddr_in *,addr);
+    char buf[64];
 
-    DEBUGMSGTL(("dns:gethostbyaddr", "resolving { AF_INET, %s:%hu }\n",
-                inet_ntoa(saddr_in->sin_addr), ntohs(saddr_in->sin_port)));
+    DEBUGMSGTL(("dns:gethostbyaddr", "resolving %s\n",
+		inet_ntop(type, addr, buf, sizeof(buf))));
 
 #ifdef DNSSEC_LOCAL_VALIDATION
     val_status_t val_status;
-    hp = val_gethostbyaddr(netsnmp_validator_context(),
-                           (const void*)&saddr_in->sin_addr,
-                           sizeof(struct in_addr), AF_INET, &val_status);
+    hp = val_gethostbyaddr(netsnmp_validator_context(), addr, len, type,
+		&val_status);
     DEBUGMSGTL(("dns:sec:val", "val_status %d / %s; trusted: %d\n",
                 val_status, p_val_status(val_status),
                 val_istrusted(val_status)));
@@ -959,8 +957,7 @@
     else if (val_does_not_exist(val_status) && hp)
         hp = NULL;
 #else
-    hp = gethostbyaddr((const void*) &saddr_in->sin_addr,
-                       sizeof(struct in_addr), AF_INET);
+    hp = gethostbyaddr(addr, len, type);
 #endif
     if (hp == NULL) {
         DEBUGMSGTL(("dns:gethostbyaddr", "couldn't resolve addr\n"));
