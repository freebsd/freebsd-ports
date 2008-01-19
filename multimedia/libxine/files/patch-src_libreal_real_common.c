--- src/libreal/real_common.c.orig	2008-01-01 22:30:08.000000000 +0900
+++ src/libreal/real_common.c	2008-01-13 04:05:14.000000000 +0900
@@ -97,6 +97,7 @@
     { O | UL,			"codecs" },
     { O | UL | UL64,		"real" },
     { O,			"real/RealPlayer/codecs" },
+    { OL | OL64 | UL | UL64,	"RealPlayer/codecs" },
     { OL | OL64 | UL | UL64,	"RealPlayer10GOLD/codecs" },
     { OL | OL64 | UL | UL64,	"RealPlayer10/codecs" },
     { OL | OL64 | UL | UL64,	"RealPlayer9/users/Real/Codecs" },
