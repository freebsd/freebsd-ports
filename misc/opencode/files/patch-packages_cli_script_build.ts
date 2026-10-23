Teach OpenCode's CLI build script about FreeBSD.

Upstream's target list only covers linux, darwin and win32, and its per-target
plugins assume a native @parcel/watcher package and bytecode support, neither
of which exists on FreeBSD:

  * add the freebsd arm64/x64 targets so `--target=opencode-freebsd-<arch>`
    resolves and `Bun.build({ compile: { target: "bun-freebsd-<arch>" } })`
    produces a FreeBSD executable;
  * keep the real watcher binding on FreeBSD, since the port builds the native
    kqueue addon and installs it next to the executable;
  * disable bytecode on FreeBSD, where bun does not emit it.

--- packages/cli/script/build.ts.orig
+++ packages/cli/script/build.ts
@@ -52,6 +52,8 @@
   { os: "win32", arch: "arm64" },
   { os: "win32", arch: "x64" },
   { os: "win32", arch: "x64", avx2: false },
+  { os: "freebsd", arch: "arm64" },
+  { os: "freebsd", arch: "x64" },
 ]
 
 const targets =
@@ -143,6 +145,7 @@
   const parcelWatcherPlugin: BunPlugin = {
     name: "parcel-watcher-binding",
     setup(build) {
+      if (item.os === "freebsd") return
       build.onLoad({ filter: /filesystem[/\\]watcher-binding\.ts$/ }, () => ({
         contents: `export default () => require(${JSON.stringify(parcelWatcherPackage)})`,
         loader: "js",
@@ -167,7 +170,7 @@
     external: ["node-gyp"],
     format: "esm",
     minify: true,
-    bytecode: true,
+    bytecode: item.os !== "freebsd",
     sourcemap: Script.channel === "dev" || Script.channel === "local" ? "inline" : "none",
     splitting: true,
     compile: {
