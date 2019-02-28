From cba99f16a4ec9a229358ce1ed96080bd5ae04a7e Mon Sep 17 00:00:00 2001
From: "Jason A. Donenfeld" <Jason@zx2c4.com>
Date: Thu, 28 Feb 2019 19:03:11 +0100
Subject: wg-quick: freebsd: rebreak interface loopback, while fixing localhost

The commit 7c833642 ("wg-quick: freebsd: allow loopback to work") was
supposed to make things better, but actually it just started sending
legitimate localhost traffic over the WireGuard interface, which is
really quite bad.

This reverts commit 7c833642dfa342218602ab18e7091e86408d2982.
---
 src/tools/wg-quick/freebsd.bash | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/src/tools/wg-quick/freebsd.bash b/src/tools/wg-quick/freebsd.bash
index 93f1a3b7..e83dbef0 100755
--- wg-quick/freebsd.bash
+++ wg-quick/freebsd.bash
@@ -158,7 +158,7 @@ add_addr() {
 	if [[ $1 == *:* ]]; then
 		cmd ifconfig "$INTERFACE" inet6 "$1" alias
 	else
-		cmd ifconfig "$INTERFACE" inet "$1" 127.0.0.1 alias
+		cmd ifconfig "$INTERFACE" inet "$1" "${1%%/*}" alias
 	fi
 }
 
-- 
cgit v1.2.1-20-gc37e

