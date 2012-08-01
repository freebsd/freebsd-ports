From 49c67ccf88c688e0e0e9e3b04f651b12c7d7f7f3 Mon Sep 17 00:00:00 2001
From: Erik Hovland <erik@hovland.org>
Date: Mon, 16 Apr 2012 14:56:43 -0700
Subject: [PATCH] Check cell new row before using it to index into
 cell_playback

cellnr is used to index into cell_playback after subtracting
one from it. If cellnr is 0, then it will index -1 in cell_playback
which will seek out of boundary of cell_playback. This manifested into a
segfault for some users as reported by this launchpad bug:
https://bugs.launchpad.net/ubuntu/+source/libdvdnav/+bug/934471

By checking cellnr and skipping the indexing if cellnr is equal to zero
then we avoid the segfault. There might be a bigger issue w/ regard to
retrieving a value of zero for cell new row, but this fix works for the
reporter.

Thanks goes to Sylvain Henry (hsyl20 AT gmail DOT com for both
reporting the bug to launchpad and submitting a potential patch (even
though we went w/ a different fix).
---
 src/searching.c |    6 +++++-
 1 file changed, 5 insertions(+), 1 deletion(-)

diff --git a/src/searching.c b/src/searching.c
index 3649e9d..0b5f22a 100644
--- src/searching.c
+++ src/searching.c
@@ -640,7 +640,11 @@ uint32_t dvdnav_describe_title_chapters(dvdnav_t *this, int32_t title, uint64_t
       goto fail;
     }
 
-    cellnr = pgc->program_map[ptt[i].pgn-1];
+    if ((cellnr = pgc->program_map[ptt[i].pgn-1]) == 0) {
+      printerr("Cell new row cannot be 0");
+      continue;
+    }
+
     if(ptt[i].pgn < pgc->nr_of_programs)
       endcellnr = pgc->program_map[ptt[i].pgn];
     else
-- 
1.7.10.3
