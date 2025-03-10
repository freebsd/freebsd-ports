From ccb45df90df60fae36b9438cfb2b0088e590306b Mon Sep 17 00:00:00 2001
From: Vsevolod Stakhov <vsevolod@rspamd.com>
Date: Tue, 17 Dec 2024 13:37:54 +0000
Subject: [PATCH] [Fix] Fix crash on FreeBSD when Rspamd is built without
 hyperscan

---
 src/rspamd.c | 3 ++-
 1 file changed, 2 insertions(+), 1 deletion(-)

diff --git src/rspamd.c src/rspamd.c
index 088bfba49..dafd9aebe 100644
--- src/rspamd.c
+++ src/rspamd.c
@@ -56,9 +56,10 @@
 
 #ifdef WITH_HYPERSCAN
 #include "libserver/hyperscan_tools.h"
-#include "rspamd_simdutf.h"
 #endif
 
+#include "rspamd_simdutf.h"
+
 /* 2 seconds to fork new process in place of dead one */
 #define SOFT_FORK_TIME 2
 
-- 
2.47.1

