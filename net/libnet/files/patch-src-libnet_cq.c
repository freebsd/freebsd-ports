- Reset global cq state after destroying it.

Obtained from:	https://github.com/sam-github/libnet/commit/c9390bf8f3379c280ba8ceec67fbd8e908675d96

--- src/libnet_cq.c.orig	2012-03-20 00:59:50.000000000 +0800
+++ src/libnet_cq.c	2015-01-18 03:09:08.170403000 +0800
@@ -344,6 +344,8 @@
         libnet_destroy(tmp->context);
         free(tmp);
     }
+    l_cq = NULL;
+    memset(&l_cqd, 0, sizeof(l_cqd));
 }
 
 libnet_t *
