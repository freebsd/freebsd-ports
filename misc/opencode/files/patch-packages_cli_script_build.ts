Teach OpenCode's CLI build script about FreeBSD.

Upstream's target list only covers linux, darwin and win32, and its per-target
plugins assume native @parcel/watcher, Iroh and bytecode support, none of which
exists on FreeBSD:

  * add the freebsd arm64/x64 targets so `OPENCODE_TARGET=freebsd-<arch>`
    resolves and `Bun.build({ compile: { target: "bun-freebsd-<arch>" } })`
    produces a FreeBSD executable;
  * keep the real watcher binding on FreeBSD, since the port builds the native
    kqueue addon and installs it next to the executable;
  * leave the Iroh binding unavailable on FreeBSD, where upstream ships no
    native package (the server treats it as unavailable, like Intel Macs);
  * disable bytecode on FreeBSD, where bun does not emit it.

--- packages/cli/script/build.ts.orig
+++ packages/cli/script/build.ts
@@ -55,6 +55,8 @@
   { os: "win32", arch: "arm64" },
   { os: "win32", arch: "x64" },
   { os: "win32", arch: "x64", avx2: false },
+  { os: "freebsd", arch: "arm64" },
+  { os: "freebsd", arch: "x64" },
 ]
 
 const targets =
@@ -159,6 +161,7 @@
   const parcelWatcherPlugin: BunPlugin = {
     name: "parcel-watcher-binding",
     setup(build) {
+      if (item.os === "freebsd") return
       build.onLoad({ filter: /filesystem[/\\]watcher-binding\.ts$/ }, () => ({
         contents: `export default () => require(${JSON.stringify(parcelWatcherPackage)})`,
         loader: "js",
@@ -168,7 +171,7 @@
   // The machine link's Iroh binding: this target's native package is embedded, and a target with none (Intel Macs)
   // gets `undefined`, which the server takes as Iroh being unavailable.
   const irohPackage =
-    item.os === "darwin" && item.arch === "x64"
+    item.os === "freebsd" || (item.os === "darwin" && item.arch === "x64")
       ? undefined
       : `@number0/iroh-${item.os}-${item.arch}${item.os === "linux" ? `-${item.abi === "musl" ? "musl" : "gnu"}` : item.os === "win32" ? "-msvc" : ""}`
   const irohBindingPlugin: BunPlugin = {
@@ -201,7 +204,7 @@
     external: ["node-gyp"],
     format: "esm",
     minify: true,
-    bytecode: true,
+    bytecode: item.os !== "freebsd",
     sourcemap: Script.channel === "dev" || Script.channel === "local" ? "inline" : "none",
     splitting: true,
     compile: {
