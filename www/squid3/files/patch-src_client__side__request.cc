http://www.squid-cache.org/Versions/v3/3.5/changesets/SQUID-2018_2.patch

commit 8232b83d3fa47a1399f155cb829db829369fbae9 (refs/remotes/origin/v3.5)
Author: squidadm <squidadm@users.noreply.github.com>
Date:   2018-01-21 08:07:08 +1300

    Fix indirect IP logging for transactions without a client connection (#129) (#136)

--- src/client_side_request.cc.orig	2018-02-23 13:39:32 UTC
+++ src/client_side_request.cc
@@ -488,9 +488,9 @@ clientFollowXForwardedForCheck(allow_t answer, void *d
         * Ensure that the access log shows the indirect client
         * instead of the direct client.
         */
-        ConnStateData *conn = http->getConn();
-        conn->log_addr = request->indirect_client_addr;
-        http->al->cache.caddr = conn->log_addr;
+        http->al->cache.caddr = request->indirect_client_addr;
+        if (ConnStateData *conn = http->getConn())
+            conn->log_addr = request->indirect_client_addr;
     }
     request->x_forwarded_for_iterator.clean();
     request->flags.done_follow_x_forwarded_for = true;
