--- src/lib/utils.cpp.orig	2024-05-03 10:03:14 UTC
+++ src/lib/utils.cpp
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 2021, [Ribose Inc](https://www.ribose.com).
+ * Copyright (c) 2021, 2024 [Ribose Inc](https://www.ribose.com).
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without
@@ -53,21 +53,6 @@ id_str_pair::lookup(const id_str_pair pair[], const st
 
 int
 id_str_pair::lookup(const id_str_pair pair[], const std::vector<uint8_t> &bytes, int notfound)
-{
-    while (pair && pair->str) {
-        if ((strlen(pair->str) == bytes.size()) &&
-            !memcmp(pair->str, bytes.data(), bytes.size())) {
-            return pair->id;
-        }
-        pair++;
-    }
-    return notfound;
-}
-
-int
-id_str_pair::lookup(const id_str_pair                 pair[],
-                    const std::basic_string<uint8_t> &bytes,
-                    int                               notfound)
 {
     while (pair && pair->str) {
         if ((strlen(pair->str) == bytes.size()) &&
