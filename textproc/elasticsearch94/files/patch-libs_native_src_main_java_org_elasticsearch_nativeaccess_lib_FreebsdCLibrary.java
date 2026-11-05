--- libs/native/src/main/java/org/elasticsearch/nativeaccess/lib/FreebsdCLibrary.java.orig	2026-11-03 20:05:23 UTC
+++ libs/native/src/main/java/org/elasticsearch/nativeaccess/lib/FreebsdCLibrary.java
@@ -0,0 +1,15 @@
+/*
+ * Copyright Elasticsearch B.V. and/or licensed to Elasticsearch B.V. under one
+ * or more contributor license agreements. Licensed under the "Elastic License
+ * 2.0", the "GNU Affero General Public License v3.0 only", and the "Server Side
+ * Public License v 1"; you may not use this file except in compliance with, at
+ * your election, the "Elastic License 2.0", the "GNU Affero General Public
+ * License v3.0 only", or the "Server Side Public License, v 1".
+ */
+
+package org.elasticsearch.nativeaccess.lib;
+
+public non-sealed interface FreebsdCLibrary extends NativeLibrary {
+
+    int posix_fallocate(int fd, long offset, long length);
+}
