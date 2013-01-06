--- ./scan_engine.cc.orig	2013-01-06 16:38:44.000000000 +0100
+++ ./scan_engine.cc	2013-01-06 16:38:44.000000000 +0100
@@ -2999,7 +2999,7 @@
   }
   if (o.spoofsource && !bind_failed) {
     o.SourceSockAddr(&ss, &sslen);
-    if (bind(sd, (struct sockaddr*)&ss, sslen) != 0) {
+    if (::bind(sd, (struct sockaddr*)&ss, sslen) != 0) {
       error("%s: Problem binding source address (%s), errno: %d", __func__, inet_socktop(&ss), socket_errno());
       perror("bind");
       bind_failed = 1;
