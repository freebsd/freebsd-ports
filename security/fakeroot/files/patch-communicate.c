--- communicate.c.orig	2024-12-20 14:24:24 UTC
+++ communicate.c
@@ -482,7 +482,7 @@ static void open_comm_sd(void)
     fail("fcntl(F_SETFD, FD_CLOEXEC)");
 
   int val = 1;
-  if (setsockopt(comm_sd, SOL_TCP, TCP_NODELAY, &val, sizeof (val)) < 0)
+  if (setsockopt(comm_sd, IPPROTO_TCP, TCP_NODELAY, &val, sizeof (val)) < 0)
       fail("setsockopt(TCP_NODELAY)");
 
   while (1) {
