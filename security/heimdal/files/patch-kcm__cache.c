--- kcm/cache.c.orig	2013-03-28 14:22:47.807924196 +1030
+++ kcm/cache.c	2013-03-28 14:23:09.600166386 +1030
@@ -102,7 +102,7 @@
     for (p = ccache_head; p != NULL; p = p->next) {
 	if ((p->flags & KCM_FLAGS_VALID) == 0)
 	    continue;
-	if (memcmp(p->uuid, uuid, sizeof(uuid)) == 0) {
+	if (memcmp(p->uuid, uuid, sizeof(kcmuuid_t)) == 0) {
 	    ret = 0;
 	    break;
 	}
