From 074dd84d5ed0e5d2b48d2aeb1b92e51507516c2d Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:12 +0200
Subject: [PATCH 27/34] patch-src__util__sss_ldap.c

---
 src/util/sss_ldap.c | 7 +++++--
 1 file changed, 5 insertions(+), 2 deletions(-)

diff --git src/util/sss_ldap.c src/util/sss_ldap.c
index 060aacf..a2cc82a 100644
--- src/util/sss_ldap.c
+++ src/util/sss_ldap.c
@@ -208,6 +208,9 @@ static void sdap_async_sys_connect_done(struct tevent_context *ev,
     errno = 0;
     ret = connect(state->fd, (struct sockaddr *) &state->addr,
                   state->addr_len);
+    if (errno == EISCONN) {
+        ret = EOK;
+    }
     if (ret != EOK) {
         ret = errno;
         if (ret == EINPROGRESS || ret == EINTR) {
@@ -268,7 +271,7 @@ static errno_t set_fd_flags_and_opts(int fd)
                   strerror(ret)));
     }
 
-    ret = setsockopt(fd, SOL_TCP, TCP_NODELAY, &dummy, sizeof(dummy));
+    ret = setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &dummy, sizeof(dummy));
     if (ret != 0) {
         ret = errno;
         DEBUG(5, ("setsockopt TCP_NODELAY failed.[%d][%s].\n", ret,
@@ -341,7 +344,7 @@ struct tevent_req *sss_ldap_init_send(TALLOC_CTX *mem_ctx,
     DEBUG(9, ("Using file descriptor [%d] for LDAP connection.\n", state->sd));
 
     subreq = sdap_async_sys_connect_send(state, ev, state->sd,
-                                         (struct sockaddr *) addr, addr_len);
+                                         (struct sockaddr *) addr, sizeof(struct sockaddr));
     if (subreq == NULL) {
         ret = ENOMEM;
         DEBUG(1, ("sdap_async_sys_connect_send failed.\n"));
-- 
1.8.0

