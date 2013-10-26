From a6a31d9de9d15c1e4627f2a7cfb8cb83a6d3e99a Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 17:08:09 +0200
Subject: [PATCH 28/34] patch-src__util__util.c

---
 src/util/util.c | 1 +
 1 file changed, 1 insertion(+)

diff --git src/util/util.c src/util/util.c
index ab98077..e279a2e 100644
--- src/util/util.c
+++ src/util/util.c
@@ -18,6 +18,7 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <sys/socket.h>
 #include <ctype.h>
 #include <netdb.h>
 #include <poll.h>
-- 
1.8.0

