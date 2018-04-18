From dc7804e1410971dabbe087193ca2b47f02131524 Mon Sep 17 00:00:00 2001
From: Jongsung Kim <jongsung.kim@gmail.com>
Date: Mon, 16 Apr 2018 13:01:41 +0900
Subject: [PATCH] tcp: fix tcp_socket_dead() for FreeBSD

The FreeBSD port of tvheadend couldn't stream Live TV, and debug
log shows webui judged the peer socket closed immediately after
starting streaming:

2018-04-15 06:30:04.996 [  DEBUG]:webui: Start streaming /stream/mux/c4bc67bdaa13457e33740ca883cc4d75?ticket=7D1B56AD0E434C5F7EBFA4677A7FBE4C94097974
2018-04-15 06:30:04.996 [  DEBUG]:webui: Stop streaming /stream/mux/c4bc67bdaa13457e33740ca883cc4d75?ticket=7D1B56AD0E434C5F7EBFA4677A7FBE4C94097974, client hung up

It looks because tcp_socket_dead() misunderstood the zero-return
from recv(). For the FreeBSD, recv() might return zero for alive
sockets which have nothing to read.

Patch tested with the latest FreeBSD port of tvheadend-4.2.6.
---
 src/tcp.c | 5 +++++
 1 file changed, 5 insertions(+)

diff --git a/src/tcp.c b/src/tcp.c
index 40f6c1c0cc..9b865eb292 100644
--- src/tcp.c
+++ src/tcp.c
@@ -453,8 +453,13 @@ tcp_socket_dead(int fd)
     return -errno;
   if (err)
     return -err;
+#ifdef PLATFORM_FREEBSD
+  if (recv(fd, NULL, 0, MSG_PEEK | MSG_DONTWAIT) < 0)
+    return -errno;
+#else
   if (recv(fd, NULL, 0, MSG_PEEK | MSG_DONTWAIT) == 0)
     return -EIO;
+#endif
   return 0;
 }
 
