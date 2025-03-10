--- src/lib/types.h.orig	2024-05-03 10:03:14 UTC
+++ src/lib/types.h
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 2017-2021, [Ribose Inc](https://www.ribose.com).
+ * Copyright (c) 2017-2024, [Ribose Inc](https://www.ribose.com).
  * Copyright (c) 2009 The NetBSD Foundation, Inc.
  * All rights reserved.
  *
@@ -95,9 +95,6 @@ class id_str_pair {
     static int         lookup(const id_str_pair           pair[],
                               const std::vector<uint8_t> &bytes,
                               int                         notfound = 0);
-    static int         lookup(const id_str_pair                 pair[],
-                              const std::basic_string<uint8_t> &bytes,
-                              int                               notfound = 0);
 };
 
 /** pgp_fingerprint_t */
