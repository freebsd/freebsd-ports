From 351664ec071daa04161577c6a1c949ed0f2c3206 Mon Sep 17 00:00:00 2001
From: minus <minus@mnus.de>
Date: Sun, 17 Nov 2019 09:36:23 +0100
Subject: [Logging] Fix Python 3.8 compatibility

Deluge's logger class extends Python's `logging.Logger`. Since Python
3.8, it takes an additional argument `stacklevel`.
The implementation in Deluge does not support that. Work around the
problem by ignoring additional arguments.
---
 deluge/log.py | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/deluge/log.py b/deluge/log.py
index 75e8308..0f9877f 100644
--- deluge/log.py
+++ deluge/log.py
@@ -86,7 +86,7 @@ class Logging(LoggingLoggerClass):
     def exception(self, msg, *args, **kwargs):
         yield LoggingLoggerClass.exception(self, msg, *args, **kwargs)
 
-    def findCaller(self, stack_info=False):  # NOQA: N802
+    def findCaller(self, *args, **kwargs):  # NOQA: N802
         f = logging.currentframe().f_back
         rv = '(unknown file)', 0, '(unknown function)'
         while hasattr(f, 'f_code'):
-- 
cgit v1.1

