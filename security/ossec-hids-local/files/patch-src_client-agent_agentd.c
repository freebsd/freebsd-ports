--- src/client-agent/agentd.c.orig	2020-02-14 19:46:22 UTC
+++ src/client-agent/agentd.c
@@ -15,6 +15,8 @@
 #include "os_dns/os_dns.h"
 #endif //WIN32
 
+struct imsgbuf server_ibuf;
+
 /* Start the agent daemon */
 void AgentdStart(const char *dir, int uid, int gid, const char *user, const char *group)
 {
@@ -39,7 +41,6 @@ void AgentdStart(const char *dir, int uid, int gid, co
     merror("starting imsg stuff");
     /* Prepare for os_dns */
     struct imsgbuf osdns_ibuf;
-    extern struct imsgbuf server_ibuf;
     //struct imsgbuf osdns_ibuf;
     int imsg_fds[2];
     merror("Creating socketpair()");
