Obtained from:	https://chromium-review.googlesource.com/c/chromiumos/third_party/tlsdate/+/549533

--- src/openssl_compat.h.orig	2018-10-16 13:25:06 UTC
+++ src/openssl_compat.h
@@ -0,0 +1,31 @@
+/*
+ * openssl_compat.h - OpenSSL 1.1 Compatability Layer
+ * Copyright 2017 The Chromium OS Authors. All rights reserved.
+ * Use of this source code is governed by a BSD-style license that can be
+ * found in the LICENSE file.
+ */
+#ifndef SRC_OPENSSL_COMPAT_H_
+#define SRC_OPENSSL_COMPAT_H_
+
+#include <openssl/bio.h>
+
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+
+static inline void BIO_set_data(BIO *a, void *ptr)
+{
+  a->ptr = ptr;
+}
+
+static inline void *BIO_get_data(BIO *a)
+{
+  return a ? a->ptr : NULL;
+}
+
+static inline void BIO_set_init(BIO *a, int init)
+{
+  a->init = init;
+}
+
+#endif
+
+#endif /* SRC_OPENSSL_COMPAT_H_ */
