From 5fcf9d93df255105ec065b168ddc11d98b5bb5d1 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Wed, 6 Nov 2013 22:01:21 +0100
Subject: [PATCH 24/25] patch-src__util__util.h

---
 src/util/util.h | 2 ++
 1 file changed, 2 insertions(+)

diff --git src/util/util.h src/util/util.h
index eab1f78..8e29fb5 100644
--- src/util/util.h
+++ src/util/util.h
@@ -571,4 +571,6 @@ errno_t sss_br_lock_file(int fd, size_t start, size_t len,
 #define BUILD_WITH_PAC_RESPONDER false
 #endif
 
+#include "util/sss_bsd_errno.h"
+
 #endif /* __SSSD_UTIL_H__ */
-- 
1.8.0

