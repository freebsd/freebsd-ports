From: Willy Tarreau <w@1wt.eu>
Date: Mon, 20 Jul 2020 19:40:14 +0000 (+0200)
Subject: BUILD: ebtree: fix build on libmusl after recent introduction of eb_memcmp()
X-Git-Url: http://git.haproxy.org/?p=haproxy-2.0.git;a=commitdiff_plain;h=5df32b51bb0c3c89b503d04cd7d31bdd77932370;hp=8e020e77ed8b30dad6dc0d0be2d287737823d856

BUILD: ebtree: fix build on libmusl after recent introduction of eb_memcmp()

In order to address a corner case with memory compares, commit 853926a
("BUG/MEDIUM: ebtree: use a byte-per-byte memcmp() to compare memory
blocks") introduced a new eb_memcmp() function, which uses ssize_t for
an offset. However this one is not known by default in ebtree for versions
prior to 2.2, and it depends on the libs. Musl requires unistd to be included
to have it.

This patch just adds this harmless include, which was verified to address
issue #760. There is no mainline commit ID as 2.2 and above already include
unistd.h as part of haproxy/api.h. It must be backported to older versions
(2.0 already has the commit above).

(cherry picked from commit c926085c7e01a93e326e8081f466d23304767a36)
Signed-off-by: Willy Tarreau <w@1wt.eu>
---

diff --git a/ebtree/ebtree.c b/ebtree/ebtree.c
index e82ed59..10cc2ff 100644
--- ebtree/ebtree.c
+++ ebtree/ebtree.c
@@ -18,6 +18,7 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
+#include <unistd.h>
 #include "ebtree.h"
 
 void eb_delete(struct eb_node *node)
