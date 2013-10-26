From 58d918d01b03a3332b3e9da917a45b4b7ef7a427 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 27 Jul 2013 15:01:26 +0200
Subject: [PATCH 30/34] patch-src__providers__ldap__sdap_async_sudo_hostinfo.c

---
 src/providers/ldap/sdap_async_sudo_hostinfo.c | 6 +++---
 1 file changed, 3 insertions(+), 3 deletions(-)

diff --git src/providers/ldap/sdap_async_sudo_hostinfo.c src/providers/ldap/sdap_async_sudo_hostinfo.c
index 0a695cd..108b4c2 100644
--- src/providers/ldap/sdap_async_sudo_hostinfo.c
+++ src/providers/ldap/sdap_async_sudo_hostinfo.c
@@ -371,7 +371,7 @@ static struct tevent_req *sdap_sudo_get_hostnames_send(TALLOC_CTX *mem_ctx,
     struct tevent_req *subreq = NULL;
     struct sdap_sudo_get_hostnames_state *state = NULL;
     char *dot = NULL;
-    char hostname[HOST_NAME_MAX + 1];
+    char hostname[_POSIX_HOST_NAME_MAX + 1];
     int resolv_timeout;
     int ret;
 
@@ -395,14 +395,14 @@ static struct tevent_req *sdap_sudo_get_hostnames_send(TALLOC_CTX *mem_ctx,
     /* get hostname */
 
     errno = 0;
-    ret = gethostname(hostname, HOST_NAME_MAX);
+    ret = gethostname(hostname, _POSIX_HOST_NAME_MAX);
     if (ret != EOK) {
         ret = errno;
         DEBUG(SSSDBG_CRIT_FAILURE, ("Unable to retrieve machine hostname "
                                     "[%d]: %s\n", ret, strerror(ret)));
         goto done;
     }
-    hostname[HOST_NAME_MAX] = '\0';
+    hostname[_POSIX_HOST_NAME_MAX] = '\0';
 
     state->hostnames[0] = talloc_strdup(state->hostnames, hostname);
     if (state->hostnames[0] == NULL) {
-- 
1.8.0

