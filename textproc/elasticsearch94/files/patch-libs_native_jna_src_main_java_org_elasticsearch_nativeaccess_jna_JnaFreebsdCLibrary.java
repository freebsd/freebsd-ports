--- libs/native/jna/src/main/java/org/elasticsearch/nativeaccess/jna/JnaFreebsdCLibrary.java.orig	2026-11-03 20:05:23 UTC
+++ libs/native/jna/src/main/java/org/elasticsearch/nativeaccess/jna/JnaFreebsdCLibrary.java
@@ -0,0 +1,41 @@
+/*
+ * Copyright Elasticsearch B.V. and/or licensed to Elasticsearch B.V. under one
+ * or more contributor license agreements. Licensed under the "Elastic License
+ * 2.0", the "GNU Affero General Public License v3.0 only", and the "Server Side
+ * Public License v 1"; you may not use this file except in compliance with, at
+ * your election, the "Elastic License 2.0", the "GNU Affero General Public
+ * License v3.0 only", or the "Server Side Public License, v 1".
+ */
+
+package org.elasticsearch.nativeaccess.jna;
+
+import com.sun.jna.Library;
+
+import com.sun.jna.Native;
+
+import org.elasticsearch.nativeaccess.lib.FreebsdCLibrary;
+
+class JnaFreebsdCLibrary implements FreebsdCLibrary {
+
+    JnaFreebsdCLibrary() {
+        try {
+            this.functions = Native.load("c", NativeFunctions.class);
+        } catch (UnsatisfiedLinkError e) {
+            throw new UnsupportedOperationException(
+                "Unable to link to libc.so"
+            );
+        }
+    }
+
+    private interface NativeFunctions extends Library {
+
+        int posix_fallocate(int fd, long offset, long length);
+    }
+
+    private final NativeFunctions functions;
+
+    @Override
+    public int posix_fallocate(int fd, long offset, long length) {
+        return functions.posix_fallocate(fd, offset, length);
+    }
+}
