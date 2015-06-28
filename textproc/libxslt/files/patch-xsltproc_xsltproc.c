From 5af7ad745323004984287e48b42712e7305de35c Mon Sep 17 00:00:00 2001
From: Per Hedeland <per@hedeland.org>
Date: Fri, 13 Dec 2013 14:43:06 +0100
Subject: Make --maxvars option work


diff --git a/xsltproc/xsltproc.c b/xsltproc/xsltproc.c
index b22df37..66d8cbb 100644
--- xsltproc/xsltproc.c
+++ xsltproc/xsltproc.c
@@ -803,6 +803,10 @@ main(int argc, char **argv)
             (!strcmp(argv[i], "--maxdepth"))) {
             i++;
             continue;
+        } else if ((!strcmp(argv[i], "-maxvars")) ||
+            (!strcmp(argv[i], "--maxvars"))) {
+            i++;
+            continue;
         } else if ((!strcmp(argv[i], "-maxparserdepth")) ||
             (!strcmp(argv[i], "--maxparserdepth"))) {
             i++;
-- 
cgit v0.10.2

