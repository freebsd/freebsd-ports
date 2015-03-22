From 85dd63b32a0b77c57cbae224f7862a5fb9c069a8 Mon Sep 17 00:00:00 2001
From: Yawning Angel <yawning@torproject.org>
Date: Sat, 14 Jun 2014 22:42:35 +0000
Subject: Fix build on GCC 4.9.0.

Just potentially uninitialized warnings in the 3rd party command line
option parsing code, probably spurious and should be ignored but,
initialize them for now.
---
 src/ext/optionparser.h | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git a/src/ext/optionparser.h b/src/ext/optionparser.h
index 17bf6ad..64e2dfc 100644
--- src/ext/optionparser.h
+++ src/ext/optionparser.h
@@ -1554,9 +1554,9 @@ inline bool Parser::workhorse(bool gnu, const Descriptor usage[], int numargs, c
 
     do // loop over short options in group, for long options the body is executed only once
     {
-      int idx;
+      int idx = 0;
 
-      const char* optarg;
+      const char* optarg = 0;
 
       /******************** long option **********************/
       if (handle_short_options == false || try_single_minus_longopt)
-- 
2.3.0

