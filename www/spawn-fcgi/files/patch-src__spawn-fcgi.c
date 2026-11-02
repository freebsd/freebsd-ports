From 875e0bd21eb926590ce1ff29ddd4d3c510d8662d Mon Sep 17 00:00:00 2001
From: Rodrigo Osorio <rodrigo@osorio.me>
Date: Sun, 1 Nov 2026 16:16:48 +0100
Subject: [PATCH] Don't rely on SUN_LEN to calculate sockaddr_un size

"Advanced Programming in the UNIX Environmen suggestion" (chapter 17.3):
The way we determine the size of the address to bind is to calculate
the offset of the sun_path member in the sockaddr_un structure and
add to it the length of the  to it the length of the pathname, not
including the terminating null byte.

Since implementations vary in which members precede sun_path in the
sockaddr_un structure, we use the offsetof macro from <stddef.h>
(included by apue.h) to calculate the offset of the sun_path member
from the start of the structure.

This is a rework of the suggested fix done by Philipp Wuensche
<cryx-ports@h3q.com> in  https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=300386
---
 src/spawn-fcgi.c | 11 +++++------
 1 file changed, 5 insertions(+), 6 deletions(-)

diff --git a/src/spawn-fcgi.c b/src/spawn-fcgi.c
index 436a515..3af99ea 100644
--- a/src/spawn-fcgi.c
+++ b/src/spawn-fcgi.c
@@ -8,6 +8,7 @@
 #include <sys/time.h>
 #include <sys/stat.h>
 
+#include <stddef.h>
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
@@ -94,12 +95,10 @@ static int bind_socket(const char *addr, unsigned short port, const char *unixso
 		if (strlen(unixsocket) > sizeof(fcgi_addr_un.sun_path) - 1) return -1;
 		strcpy(fcgi_addr_un.sun_path, unixsocket);
 
-#ifdef SUN_LEN
-		servlen = SUN_LEN(&fcgi_addr_un);
-#else
-		/* stevens says: */
-		servlen = strlen(fcgi_addr_un.sun_path) + sizeof(fcgi_addr_un.sun_family);
-#endif
+		/* don't rely on SUN_LEN (hidden on BSD with _XOPEN_SOURCE) or on
+		 * sun_path following sun_family directly (BSD has sun_len first) */
+		servlen = offsetof(struct sockaddr_un, sun_path) + strlen(fcgi_addr_un.sun_path);
+
 		socket_type = AF_UNIX;
 		fcgi_addr = (struct sockaddr *) &fcgi_addr_un;
 
-- 
2.56.0

