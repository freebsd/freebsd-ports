Load the FreeBSD @parcel/watcher binding from the installed addon.

The FreeBSD port builds the native kqueue addon itself and installs it at
PREFIX/lib/opencode/watcher.node; load that file instead of a non-existent
@parcel/watcher-freebsd-* package.

--- packages/core/src/filesystem/watcher-binding.ts.orig
+++ packages/core/src/filesystem/watcher-binding.ts
@@ -1,4 +1,5 @@
 import { createRequire } from "node:module"
+import path from "node:path"
 
 declare const OPENCODE_LIBC: string | undefined
 
@@ -9,6 +10,8 @@
   const libc = typeof OPENCODE_LIBC === "undefined" ? undefined : OPENCODE_LIBC
   return require(
     process.env.OPENCODE_PARCEL_WATCHER_PATH ??
-      `@parcel/watcher-${process.platform}-${process.arch}${process.platform === "linux" ? `-${libc || "glibc"}` : ""}`,
+      (process.platform === "freebsd"
+        ? path.join(path.dirname(process.execPath), "..", "lib", "opencode", "watcher.node")
+        : `@parcel/watcher-${process.platform}-${process.arch}${process.platform === "linux" ? `-${libc || "glibc"}` : ""}`),
   )
 }
