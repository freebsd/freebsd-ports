From 36ea9e6d18578237b9e7ffef382788736eab49f5 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 19/34] patch-src__sss_client__nss_group.c

---
 src/sss_client/nss_group.c | 71 ++++++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 71 insertions(+)

diff --git src/sss_client/nss_group.c src/sss_client/nss_group.c
index e6ea54b..88cd1ab 100644
--- src/sss_client/nss_group.c
+++ src/sss_client/nss_group.c
@@ -343,6 +343,77 @@ out:
 }
 
 
+#define MIN(a, b)((a) < (b) ? (a) : (b))
+
+gr_addgid(gid_t gid, gid_t *groups, int maxgrp, int *grpcnt)
+{
+  int     ret, dupc;
+
+  for (dupc = 0; dupc < MIN(maxgrp, *grpcnt); dupc++) {
+    if (groups[dupc] == gid)
+      return 1;
+  }
+
+  ret = 1;
+  if (*grpcnt < maxgrp)
+    groups[*grpcnt] = gid;
+  else
+    ret = 0;
+
+  (*grpcnt)++;
+
+  return ret;
+}
+
+enum nss_status _nss_sss_getgroupmembership(const char *uname, gid_t agroup, gid_t *groups,
+					    int maxgrp, int *grpcnt)
+{
+    struct sss_cli_req_data rd;
+    uint8_t *repbuf;
+    size_t replen;
+    enum nss_status nret;
+    uint32_t *rbuf;
+    uint32_t num_ret;
+    long int l, max_ret;
+    int errnop;
+
+    rd.len = strlen(uname) +1;
+    rd.data = uname;
+
+    sss_nss_lock();
+
+    nret = sss_nss_make_request(SSS_NSS_INITGR, &rd,
+                                &repbuf, &replen, &errnop);
+    if (nret != NSS_STATUS_SUCCESS) {
+        goto out;
+    }
+
+    /* no results if not found */
+    num_ret = ((uint32_t *)repbuf)[0];
+    if (num_ret == 0) {
+        free(repbuf);
+        nret = NSS_STATUS_NOTFOUND;
+        goto out;
+    }
+    max_ret = num_ret;
+
+    gr_addgid(agroup, groups, maxgrp, grpcnt);
+
+    rbuf = &((uint32_t *)repbuf)[2];
+    for (l = 0; l < max_ret; l++) {
+      gr_addgid(rbuf[l], groups, maxgrp, grpcnt);
+    }
+
+    free(repbuf);
+    nret = NSS_STATUS_SUCCESS;
+
+out:
+    sss_nss_unlock();
+    return nret;
+
+
+}
+
 enum nss_status _nss_sss_getgrnam_r(const char *name, struct group *result,
                                     char *buffer, size_t buflen, int *errnop)
 {
-- 
1.8.0

