From d910e99c322a0895955038c700471e9b1fd91fa6 Mon Sep 17 00:00:00 2001
From: Patrick Welche <prlw1@cam.ac.uk>
Date: Mon, 6 Nov 2017 16:20:25 +0000
Subject: [PATCH] python: remove single use of _PyVerify_fd

_PyVerify_fd disappeared from python with:

  https://hg.python.org/cpython/rev/e88e2049b793

https://bugzilla.gnome.org/show_bug.cgi?id=776815
---
 python/types.c | 2 --
 1 file changed, 2 deletions(-)

diff --git a/python/types.c b/python/types.c
index f2376776..124af565 100644
--- python/types.c
+++ python/types.c
@@ -31,8 +31,6 @@ libxml_PyFileGet(PyObject *f) {
     const char *mode;
 
     fd = PyObject_AsFileDescriptor(f);
-    if (!_PyVerify_fd(fd))
-        return(NULL);
     /*
      * Get the flags on the fd to understand how it was opened
      */
-- 
2.18.1

