From 94fc846b7b7001bb9fecd22b7f698b6753915f0a Mon Sep 17 00:00:00 2001
From: Adam Weinberger <adamw@adamw.org>
Date: Wed, 1 Mar 2023 16:44:09 -0500
Subject: [PATCH] Fix null pointer exception on FreeBSD (fixes #2476)

---
 src/parser.c | 4 +++-
 1 file changed, 3 insertions(+), 1 deletion(-)

diff --git a/src/parser.c b/src/parser.c
index c5ca3ae43..8670e0e70 100644
--- src/parser.c
+++ src/parser.c
@@ -134,7 +134,7 @@ set_glog (Logs * logs, const char *filename) {
   GLog *tmp = NULL, *glog = NULL;
   int newlen = 0;
   char const *err;
-  char *fvh = NULL, *fn = (char *) filename;
+  char *fvh = NULL, *fn = NULL;
 
   if (logs->size - 1 < logs->idx) {
     newlen = logs->size + 1;
@@ -147,6 +147,7 @@ set_glog (Logs * logs, const char *filename) {
     logs->size = newlen;
   }
 
+  fn = xstrdup (filename);  /* ensure fn is a string */
   glog = logs->glog;
   glog[logs->idx].errors = xcalloc (MAX_LOG_ERRORS, sizeof (char *));
   glog[logs->idx].filename = xstrdup (fn);
@@ -161,6 +162,7 @@ set_glog (Logs * logs, const char *filename) {
   logs->processed = &(glog[logs->idx].processed);
   logs->filename = glog[logs->idx].filename;
   logs->idx++;
+  free (fn);
 
   return 0;
 }
