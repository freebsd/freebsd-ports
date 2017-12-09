From e751722a7b0c5b595794e60b054ade0b3f6cdb4d Mon Sep 17 00:00:00 2001
From: Michal Srb <msrb@suse.com>
Date: Fri, 7 Jul 2017 17:04:03 +0200
Subject: os: Make sure big requests have sufficient length.

A client can send a big request where the 32B "length" field has value
0. When the big request header is removed and the length corrected,
the value will underflow to 0xFFFFFFFF.  Functions processing the
request later will think that the client sent much more data and may
touch memory beyond the receive buffer.

Signed-off-by: Eric Anholt <eric@anholt.net>
Reviewed-by: Peter Hutterer <peter.hutterer@who-t.net>
(cherry picked from commit 9c23685009aa96f4b861dcc5d2e01dbee00c4dd9)

diff --git a/os/io.c b/os/io.c
index f80580c..70f07f3 100644
--- os/io.c
+++ os/io.c
@@ -441,6 +441,11 @@ ReadRequestFromClient(ClientPtr client)
     if (!gotnow)
         AvailableInput = oc;
     if (move_header) {
+        if (client->req_len < bytes_to_int32(sizeof(xBigReq) - sizeof(xReq))) {
+            YieldControlDeath();
+            return -1;
+        }
+
         request = (xReq *) oci->bufptr;
         oci->bufptr += (sizeof(xBigReq) - sizeof(xReq));
         *(xReq *) oci->bufptr = *request;
-- 
cgit v0.10.2

