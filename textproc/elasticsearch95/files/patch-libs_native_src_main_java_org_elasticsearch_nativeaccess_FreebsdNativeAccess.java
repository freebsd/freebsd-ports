--- libs/native/src/main/java/org/elasticsearch/nativeaccess/FreebsdNativeAccess.java.orig	2026-11-05 15:10:31 UTC
+++ libs/native/src/main/java/org/elasticsearch/nativeaccess/FreebsdNativeAccess.java
@@ -0,0 +1,70 @@
+/*
+ * Copyright Elasticsearch B.V. and/or licensed to Elasticsearch B.V. under one
+ * or more contributor license agreements. Licensed under the "Elastic License
+ * 2.0", the "GNU Affero General Public License v3.0 only", and the "Server Side
+ * Public License v 1"; you may not use this file except in compliance with, at
+ * your election, the "Elastic License 2.0", the "GNU Affero General Public
+ * License v3.0 only", or the "Server Side Public License, v 1".
+ */
+
+package org.elasticsearch.nativeaccess;
+
+import org.elasticsearch.nativeaccess.lib.FreebsdCLibrary;
+import org.elasticsearch.nativeaccess.lib.NativeLibraryProvider;
+import org.elasticsearch.nativeaccess.lib.PosixCLibrary;
+
+public class FreebsdNativeAccess extends PosixNativeAccess {
+
+    private final FreebsdCLibrary bsdLibc;
+    static final int RLIMIT_NPROC = 7;
+
+    // https://man.freebsd.org/cgi/man.cgi?stat(2)
+    // sys/sys/resource.h and sys/sys/stat.h
+    // Offset of st_size: 112 bytes
+    // Offset of st_blocks: 120 bytes
+    FreebsdNativeAccess(NativeLibraryProvider libraryProvider) {
+        super("FreeBSD", libraryProvider, new PosixConstants(-1L, 10, 1, 6, 512, 224, 112, 120));
+        this.bsdLibc = libraryProvider.getLibrary(FreebsdCLibrary.class);
+    }
+
+    // sys/sys/resource.h
+    @Override
+    protected long getMaxThreads() {
+        return getRLimit(RLIMIT_NPROC, "max number of threads");
+    }
+
+    @Override
+    protected void logMemoryLimitInstructions() {
+        logger.warn("You can allow Elasticsearch to lock large amounts of RAM by setting the following in /etc/sysctl.conf:");
+        logger.warn("security.bsd.unprivileged_mlock=1\n");
+        logger.warn("You can also run the following command to modify the value immediately:");
+        logger.warn("sysctl security.bsd.unprivileged_mlock=1\n");
+        logger.warn("When running within a Jail, it's highly advisable to set:");
+        logger.warn("enforce_statfs = 1");
+    }
+
+    @Override
+    protected boolean nativePreallocate(int fd, long currentSize, long newSize) {
+        final int rc = bsdLibc.posix_fallocate(fd, currentSize, newSize - currentSize);
+        if (rc != 0) {
+            logger.warn("posix_fallocate failed: " + libc.strerror(libc.errno()));
+            return false;
+        }
+        return true;
+    }
+
+    // https://github.com/elastic/elasticsearch/blob/v8.15.5/server/src/main/java/org/elasticsearch/bootstrap/SystemCallFilter.java#L556
+    @Override
+    public void tryInstallExecSandbox() {
+        PosixCLibrary.RLimit limit = libc.newRLimit();
+        limit.rlim_cur(0);
+        limit.rlim_max(0);
+        if (libc.setrlimit(RLIMIT_NPROC, limit) != 0) {
+            throw new UnsupportedOperationException("RLIMIT_NPROC unavailable: " + libc.strerror(libc.errno()));
+        }
+
+        logger.debug("FreeBSD RLIMIT_NPROC initialization successful");
+
+        execSandboxState = ExecSandboxState.ALL_THREADS;
+    }
+}
