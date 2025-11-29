From bfa2f733351da5b2ee2674408eac744b067622fb Mon Sep 17 00:00:00 2001
From: Nicholas Marriott <nicholas.marriott@gmail.com>
Date: Wed, 26 Nov 2025 10:41:17 +0000
Subject: [PATCH] Need signal.h for utempter, from Yasuhiro Kimura.

---
 server-fn.c | 1 +
 1 file changed, 1 insertion(+)

diff --git server-fn.c server-fn.c
index 6ab7fa48..29802a60 100644
--- server-fn.c
+++ server-fn.c
@@ -20,6 +20,7 @@
 #include <sys/wait.h>
 #include <sys/uio.h>
 
+#include <signal.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
-- 
2.52.0

