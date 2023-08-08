--- tv_addrtoname.c.orig	1993-04-22 20:40:35 UTC
+++ tv_addrtoname.c
@@ -110,6 +110,7 @@ struct ipproto {
   u_short p;
 };
 
+#define IPPROTO_HELLO           63              /* "hello" routing protocol */
 struct ipproto ipproto_db[] = {
   { "IP", IPPROTO_IP },
   { "ICMP", IPPROTO_ICMP },
@@ -307,7 +308,7 @@ intoa(addr)
 	register int n;
 	static char buf[sizeof(".xxx.xxx.xxx.xxx")];
 
-	NTOHL(addr);
+	ntohl(addr);
 	cp = &buf[sizeof buf];
 	*--cp = '\0';
 
@@ -643,7 +644,7 @@ int flag;
   static char buffer[8];
   char *cp;
 
-  NTOHS(port); 
+  ntohs(port); 
 
   if (!(flag&ADDR_NUMERICAL)) {
     for(i=0;eproto_db[i].s;i++) {
@@ -668,7 +669,7 @@ u_short pro;
 {
   int i;
 
-/*  NTOHS(pro); */
+/*  ntohs(pro); */
   
   for(i=0;ipproto_db[i].s;i++) {
     if (ipproto_db[i].p == pro)
@@ -750,7 +751,7 @@ init_servarray()
   register struct hnamemem *table;
   
   while (sv = GetServent()) {
-    NTOHS(sv->s_port);
+    ntohs(sv->s_port);
     if (strcmp(sv->s_proto, "tcp") == 0) {
       table = lookup_port(sv->s_port,LOOKUP_TCP);
     } else if (strcmp(sv->s_proto, "udp") == 0) {
