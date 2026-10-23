Fix the FreeBSD watcher without triggering Bun's N-API crash.

Bun 1.4.x segfaults or hangs when @parcel/watcher's kqueue subscription
delivers events from its callback thread through an N-API thread-safe
function, and its fs.watch does not report missing entries on FreeBSD.  Use
the addon's native snapshot API for directory watches and a small JS poller
for immediate file/entry watches instead.  Await the initial snapshot before
reporting the subscription ready so config reloads cannot miss the first write.

--- packages/core/src/filesystem/watcher.ts.orig
+++ packages/core/src/filesystem/watcher.ts
@@ -7,7 +7,8 @@
 import { FSUtil } from "@opencode/util/fs-util"
 import { Cause, Context, Effect, Layer, PubSub, RcMap, Stream } from "effect"
 import { lazy } from "../util/lazy.js"
-import { watch } from "node:fs"
+import { readdirSync, rmSync, statSync, watch } from "node:fs"
+import { tmpdir } from "node:os"
 import path from "path"
 import loadBinding from "./watcher-binding.js"
 
@@ -198,14 +199,126 @@
   }),
 )
 
+function poll(directory: string, names: ReadonlySet<string>, publish: (update: Update) => void): Subscription {
+  const scan = () => {
+    const next = new Map<string, string>()
+    let entries
+    try {
+      entries = readdirSync(directory, { withFileTypes: true })
+    } catch {
+      return next
+    }
+    for (const entry of entries) {
+      if (!names.has(entry.name)) continue
+      const file = path.join(directory, entry.name)
+      if (entry.isDirectory()) {
+        next.set(file, "directory")
+        continue
+      }
+      try {
+        const stat = statSync(file)
+        next.set(file, `${stat.mtimeMs}:${stat.size}`)
+      } catch {
+        next.set(file, "file")
+      }
+    }
+    return next
+  }
+  let previous = scan()
+  const timer = setInterval(() => {
+    const next = scan()
+    for (const [file, signature] of next) {
+      const prior = previous.get(file)
+      if (prior === undefined) publish({ path: file, type: "create" })
+      else if (prior !== signature) publish({ path: file, type: "update" })
+    }
+    for (const file of previous.keys()) if (!next.has(file)) publish({ path: file, type: "delete" })
+    previous = next
+  }, 100)
+  return {
+    unsubscribe: () => {
+      clearInterval(timer)
+      return Promise.resolve()
+    },
+    backend: "poll",
+  }
+}
+
+function snapshotPoller(
+  native: typeof ParcelWatcher,
+  directory: string,
+  ignore: readonly string[],
+  publish: (update: Update) => void,
+): Effect.Effect<Subscription> {
+  return Effect.promise(async () => {
+    const snapshot = path.join(tmpdir(), `opencode-watch-${process.pid}-${Math.random().toString(36).slice(2)}`)
+    const options = { backend: "brute-force" as ParcelWatcher.BackendType, ignore: [...ignore] }
+    let active = true
+    let ready = false
+    let running = false
+    const tick = async () => {
+      if (!active || running) return
+      running = true
+      try {
+        if (!ready) {
+          await native.writeSnapshot(directory, snapshot, options)
+          ready = true
+          return
+        }
+        const updates = await native.getEventsSince(directory, snapshot, options)
+        await native.writeSnapshot(directory, snapshot, options)
+        for (const update of updates) publish(update)
+      } catch {
+        ready = false
+      } finally {
+        running = false
+      }
+    }
+    // Establish the baseline before reporting the subscription as ready, so
+    // files created by the consumer right after subscribe are observed.
+    try {
+      await native.writeSnapshot(directory, snapshot, options)
+      ready = true
+    } catch {}
+    const timer = setInterval(tick, 250)
+    return {
+      unsubscribe: () => {
+        active = false
+        clearInterval(timer)
+        rmSync(snapshot, { force: true })
+        return Promise.resolve()
+      },
+      backend: "brute-force",
+    }
+  })
+}
+
 export const nativeLayer = Layer.succeed(
   Native,
   Native.of({
     subscribe: (input) => {
+      // Bun's parcel subscription path crashes on FreeBSD (N-API thread-safe
+      // functions). Use the native snapshot API instead, which does not spawn
+      // a callback thread, and poll the immediate entries from JS.
+      if (process.platform === "freebsd" && input.type === "directory") {
+        const native = watcher()
+        if (!native) {
+          return Effect.logError("watcher backend not supported", {
+            directory: input.target,
+            platform: process.platform,
+          }).pipe(Effect.as(undefined))
+        }
+        return snapshotPoller(native, input.target, input.ignore, input.publish)
+      }
       if (input.type === "file" || input.type === "entries") {
+        const directory = input.type === "file" ? path.dirname(input.target) : input.target
+        const names = new Set(input.type === "file" ? [path.basename(input.target)] : input.names)
+        // Bun's fs.watch does not deliver events for missing entries on FreeBSD.
+        // Poll the containing directory instead of using a native addon.
+        if (process.platform === "freebsd") {
+          return Effect.sync(() => poll(directory, names, input.publish))
+        }
         return Effect.sync(() => {
-          const directory = input.type === "file" ? path.dirname(input.target) : input.target
-          const names = new Set(input.type === "file" ? [path.basename(input.target)] : input.names)
           const subscription = watch(directory, { recursive: false }, (_event, file) => {
             if (file && !names.has(file)) return
             for (const name of file ? [file] : names) {
