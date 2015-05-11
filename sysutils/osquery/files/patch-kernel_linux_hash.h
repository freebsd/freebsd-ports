--- kernel/linux/hash.h.orig	2015-05-05 00:16:41 UTC
+++ kernel/linux/hash.h
@@ -1,4 +0,0 @@
-// Copyright 2004-present Facebook. All Rights Reserved.
-
-unsigned char *kernel_text_hash(void);
-unsigned char *hash_data(const void *, size_t);
