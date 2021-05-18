From 96fb72e7cbac29086e51c57e5b629ac5a739e0e2 Mon Sep 17 00:00:00 2001
From: "Todd C. Miller" <Todd.Miller@sudo.ws>
Date: Wed, 12 May 2021 07:27:09 -0600
Subject: [PATCH] Explicitly include netinet/in.h for struct sockaddr_in and
 sockaddr+_in6. Fixes a compilation problem on FreeBSD.

---
 lib/iolog/hostcheck.c | 1 +
 1 file changed, 1 insertion(+)

diff --git lib/iolog/hostcheck.c lib/iolog/hostcheck.c
index 0dee14b79..3eeabd262 100644
--- lib/iolog/hostcheck.c
+++ lib/iolog/hostcheck.c
@@ -24,6 +24,7 @@
 #if defined(HAVE_OPENSSL)
 # include <sys/types.h>
 # include <sys/socket.h>
+# include <netinet/in.h>
 # include <arpa/inet.h>
 # include <stdlib.h>
 # include <string.h>
-- 
2.31.1

