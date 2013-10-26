From b668ec58a5d60c65e24c3b123ab7589fb28c3e83 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 15/34] patch-src__responder__common__responder_common.c

---
 src/responder/common/responder_common.c | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git src/responder/common/responder_common.c src/responder/common/responder_common.c
index c5d7577..965a870 100644
--- src/responder/common/responder_common.c
+++ src/responder/common/responder_common.c
@@ -308,7 +308,7 @@ static void client_recv(struct cli_ctx *cctx)
         talloc_free(cctx);
         break;
 
-    case ENODATA:
+    case ECONNRESET:
         DEBUG(5, ("Client disconnected!\n"));
         talloc_free(cctx);
         break;
-- 
1.8.0

