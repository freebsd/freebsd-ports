diff -urN src/redir.c.orig src/redir.c
--- src/redir.c.orig	2008-06-28 17:38:35.000000000 +0100
+++ src/redir.c	2008-06-29 16:17:48.000000000 +0100
@@ -479,7 +479,7 @@
 
   if ((conn->s_params.flags & REQUIRE_UAM_SPLASH) && 
       conn->s_params.url[0]) {
-    redir_url = conn->s_params.url;
+    redir_url = (char *)conn->s_params.url;
   }
 
   bassignformat(str, "%s%cres=%s&uamip=%s&uamport=%d", 
@@ -1939,8 +1939,8 @@
   msg.mdata.addr = address->sin_addr; \
   memcpy(&msg.mdata.params, &conn.s_params, sizeof(msg.mdata.params)); \
   memcpy(&msg.mdata.redir, &conn.s_state.redir, sizeof(msg.mdata.redir)); \
-  if (msgsnd(redir->msgid, (struct msgbuf *)&msg, sizeof(msg.mdata), 0) < 0) { \
-    log_err(errno, "msgsnd() failed!"); \
+  if (msgsnd(redir->msgid, (void *)&msg, sizeof(msg.mdata), 0) < 0) { \
+    log_err(errno, "msgsnd() failed! msgid=%d type=%d len=%d", redir->msgid, msg.mtype, sizeof(msg.mdata)); \
     redir_close(infd, outfd); \
   } 
 

