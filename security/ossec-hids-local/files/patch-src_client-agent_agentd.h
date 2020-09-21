--- src/client-agent/agentd.h.orig	2020-02-14 19:46:22 UTC
+++ src/client-agent/agentd.h
@@ -83,7 +83,7 @@ extern int run_foreground;
 extern keystore keys;
 extern agent *agt;
 #ifndef WIN32
-struct imsgbuf server_ibuf;
+extern struct imsgbuf server_ibuf;
 #endif //WIN32
 
 #endif /* __AGENTD_H */
