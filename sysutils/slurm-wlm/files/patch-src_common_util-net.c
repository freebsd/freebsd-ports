--- src/common/util-net.c.orig	2026-01-15 20:26:01 UTC
+++ src/common/util-net.c
@@ -60,6 +60,7 @@
 #include "src/common/xassert.h"
 #include "src/common/xmalloc.h"
 #include "src/common/xstring.h"
+#include "src/common/slurm_sockaddr.h"
 
 static pthread_mutex_t hostentLock = PTHREAD_MUTEX_INITIALIZER;
 static pthread_rwlock_t getnameinfo_cache_lock = PTHREAD_RWLOCK_INITIALIZER;
@@ -400,8 +401,18 @@ static char *_getnameinfo(const slurm_addr_t *addr)
 {
 	char hbuf[NI_MAXHOST] = "\0";
 	int err;
+	struct sockaddr_storage ss;
+	socklen_t alen = 0;
 
-	err = getnameinfo((const struct sockaddr *) addr, sizeof(*addr),
+
+	if (slurm_sockaddr_copy_fix(&ss, (const struct sockaddr *)addr,
+				    (socklen_t)sizeof(*addr), &alen) < 0) {
+		log_flag(NET, "%s: slurm_sockaddr_copy_fix(%pA) failed",
+			 __func__, addr);
+		return NULL;
+	}
+
+	err = getnameinfo((const struct sockaddr *)&ss, alen,
 			  hbuf, sizeof(hbuf), NULL, 0, NI_NAMEREQD);
 	if (err == EAI_SYSTEM) {
 		log_flag(NET, "%s: getnameinfo(%pA) failed: %s: %m",
