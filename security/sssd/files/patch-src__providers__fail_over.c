From 08bc75705abe29a9e046a0a8871adcf42eeee35c Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Wed, 6 Nov 2013 22:01:20 +0100
Subject: [PATCH 07/25] patch-src__providers__fail_over.c

---
 src/providers/fail_over.c | 6 +++---
 1 file changed, 3 insertions(+), 3 deletions(-)

diff --git src/providers/fail_over.c src/providers/fail_over.c
index 59cbacd..197c0ef 100644
--- src/providers/fail_over.c
+++ src/providers/fail_over.c
@@ -1331,7 +1331,7 @@ resolve_srv_recv(struct tevent_req *req, struct fo_server **server)
  *******************************************************************/
 struct resolve_get_domain_state {
     char *fqdn;
-    char hostname[HOST_NAME_MAX];
+    char hostname[_POSIX_HOST_NAME_MAX + 1];
 };
 
 static void resolve_get_domain_done(struct tevent_req *subreq);
@@ -1351,13 +1351,13 @@ resolve_get_domain_send(TALLOC_CTX *mem_ctx,
         return NULL;
     }
 
-    ret = gethostname(state->hostname, HOST_NAME_MAX);
+    ret = gethostname(state->hostname, _POSIX_HOST_NAME_MAX);
     if (ret) {
         ret = errno;
         DEBUG(2, ("gethostname() failed: [%d]: %s\n",ret, strerror(ret)));
         return NULL;
     }
-    state->hostname[HOST_NAME_MAX-1] = '\0';
+    state->hostname[_POSIX_HOST_NAME_MAX] = '\0';
     DEBUG(7, ("Host name is: %s\n", state->hostname));
 
     subreq = resolv_gethostbyname_send(state, ev, resolv,
-- 
1.8.0

