- Reset global cq state after destroying it.

Obtained from:	https://github.com/sam-github/libnet/commit/c9390bf8f3379c280ba8ceec67fbd8e908675d96

--- src/libnet_cq.c.orig	2012-03-19 16:59:50 UTC
+++ src/libnet_cq.c
@@ -344,6 +344,8 @@ libnet_cq_destroy() 
         libnet_destroy(tmp->context);
         free(tmp);
     }
+    l_cq = NULL;
+    memset(&l_cqd, 0, sizeof(l_cqd));
 }
 
 libnet_t *
