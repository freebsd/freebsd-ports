--- libraries/libmbutil/parser.h.orig	2021-11-08 01:16:41 UTC
+++ libraries/libmbutil/parser.h
@@ -272,7 +272,7 @@ class HighParser { (public)
 		UNKNOWN = -1,
 		
 		DESCRIPTION,
-		FIRSTARG,
+		MBDYN_FIRSTARG,
 		ARG,
 		LASTARG,
 		NOARGS,
