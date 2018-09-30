From 30334c28794ef85d8973f4ed0779b5ceed6594f2 Mon Sep 17 00:00:00 2001
From: Colin Walters <walters@verbum.org>
Date: Mon, 7 Aug 2017 13:15:26 -0400
Subject: [PATCH] gnome-scores.h: Convert to UTF-8

The new Python `glib-mkenums` barfs on ISO-8859-1 input.
---
 libgnomeui/gnome-scores.h | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/libgnomeui/gnome-scores.h b/libgnomeui/gnome-scores.h
index 911b12d1..4e641d22 100644
--- libgnomeui/gnome-scores.h
+++ libgnomeui/gnome-scores.h
@@ -27,7 +27,7 @@
  * "High Scores" Widget 
  *
  * AUTHOR: 
- * Horacio J. Peña <horape@compendium.com.ar>
+ * Horacio J. PeÃ±a <horape@compendium.com.ar>
  *
  * This is free software (under the terms of the GNU LGPL)
  *
-- 
2.17.1

