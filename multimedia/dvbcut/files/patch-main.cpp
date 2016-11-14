--- src/main.cpp.orig	2016-06-23 12:34:35 UTC
+++ src/main.cpp
@@ -52,7 +52,7 @@ static char *argv0;
 void
 usage_exit(int rv=1) {
   fprintf(stderr,
-    "Usage ("VERSION_STRING"):\n"
+    "Usage (" VERSION_STRING "):\n"
     "  %s -generateidx [-idx <idxfilename>] [<mpgfilename> ...]\n"
     "  %s -batch [ OPTIONS ] <prjfilename> | <mpgfilename> ...\n\n"
     "OPTIONS: -cut 4:3|16:9|TS|TS2|<list>, -exp <expfilename>,\n"
