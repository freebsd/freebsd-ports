From f127fb779a1a405446804235fce223cc8abc44ea Mon Sep 17 00:00:00 2001
From: Bryan Drewery <bryan@shatow.net>
Date: Wed, 26 Jun 2013 06:48:17 -0500
Subject: [PATCH] Revert pkg-query %a and %k back to an integer

Scripts such as portmaster and portupgrade expect an integer
here. This is also the advertised result in the manpage.
---
 pkg/query.c | 8 ++++++--
 1 file changed, 6 insertions(+), 2 deletions(-)

diff --git a/pkg/query.c b/pkg/query.c
index bdca068..5cb00e0 100644
--- pkg/query.c
+++ pkg/query.c
@@ -77,6 +77,8 @@
 static void
 format_str(struct pkg *pkg, struct sbuf *dest, const char *qstr, void *data)
 {
+	bool automatic;
+	bool locked;
 
 	sbuf_clear(dest);
 
@@ -109,10 +111,12 @@
 				pkg_sbuf_printf(dest, "%w", pkg);
 				break;
 			case 'a':
-				pkg_sbuf_printf(dest, "%a", pkg);
+				pkg_get(pkg, PKG_AUTOMATIC, &automatic);
+				sbuf_printf(dest, "%d", automatic);
 				break;
 			case 'k':
-				pkg_sbuf_printf(dest, "%k", pkg);
+				pkg_get(pkg, PKG_LOCKED, &locked);
+				sbuf_printf(dest, "%d", locked);
 				break;
 			case 't':
 				pkg_sbuf_printf(dest, "%t", pkg);
-- 
1.8.1.6

