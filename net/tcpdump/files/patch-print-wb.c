From 8aa5edea1b8846740514dee4158b6c707d38fc13 Mon Sep 17 00:00:00 2001
From: Denis Ovsienko <denis@ovsienko.info>
Date: Wed, 25 Mar 2015 22:35:12 +0000
Subject: [PATCH] whiteboard: fixup a few reversed tests (GH #446)

This is a follow-up to commit 3a3ec26.
---
 print-wb.c | 6 +++---
 1 file changed, 3 insertions(+), 3 deletions(-)

diff --git a/print-wb.c b/print-wb.c
index 38c2a67..e10d532 100644
--- a/print-wb.c
+++ print-wb.c
@@ -202,7 +202,7 @@ wb_id(netdissect_options *ndo,
 	len -= sizeof(*io) * nid;
 	io = (struct id_off *)(id + 1);
 	cp = (char *)(io + nid);
-	if (!ND_TTEST2(cp, len)) {
+	if (ND_TTEST2(cp, len)) {
 		ND_PRINT((ndo, "\""));
 		fn_print(ndo, (u_char *)cp, (u_char *)cp + len);
 		ND_PRINT((ndo, "\""));
@@ -267,7 +267,7 @@ wb_prep(netdissect_options *ndo,
 	}
 	n = EXTRACT_32BITS(&prep->pp_n);
 	ps = (const struct pgstate *)(prep + 1);
-	while (--n >= 0 && !ND_TTEST(*ps)) {
+	while (--n >= 0 && ND_TTEST(*ps)) {
 		const struct id_off *io, *ie;
 		char c = '<';
 
@@ -276,7 +276,7 @@ wb_prep(netdissect_options *ndo,
 		    ipaddr_string(ndo, &ps->page.p_sid),
 		    EXTRACT_32BITS(&ps->page.p_uid)));
 		io = (struct id_off *)(ps + 1);
-		for (ie = io + ps->nid; io < ie && !ND_TTEST(*io); ++io) {
+		for (ie = io + ps->nid; io < ie && ND_TTEST(*io); ++io) {
 			ND_PRINT((ndo, "%c%s:%u", c, ipaddr_string(ndo, &io->id),
 			    EXTRACT_32BITS(&io->off)));
 			c = ',';
