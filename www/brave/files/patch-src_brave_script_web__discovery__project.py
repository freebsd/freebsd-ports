--- src/brave/script/web_discovery_project.py.orig	2026-06-01 00:00:00 UTC
+++ src/brave/script/web_discovery_project.py
@@ -16,16 +16,73 @@
     SOURCE_ROOT, 'vendor', 'web-discovery-project')
 
 
+# The bundles //brave/components/brave_extension declares as the outputs of
+# web_discovery_project_resources.
+BUNDLES = [
+    os.path.join('core', 'content-script.bundle.js'),
+    os.path.join('hpnv2', 'worker.asmjs.bundle.js'),
+    os.path.join('hpnv2', 'worker.wasm.bundle.js'),
+    'star.wasm',
+]
+
+# The extension's background script imports this directory as
+# 'gen/brave/web-discovery-project'.  webpack resolves that to index.js and
+# ts-loader type checks it against index.d.ts, so a build without the project
+# has to leave both behind or the extension bundle does not compile.
+STUB_MODULE = """\
+// The Web Discovery Project builds itself with pnpm out of its own git
+// checkout, which a build from release tarballs does not have.  The feature is
+// off (enable_web_discovery) and the extension only reaches for this once the
+// brave.web_discovery_enabled preference is turned on, so a class that does
+// nothing is enough to keep the bundle building.
+export class App {
+  constructor () {
+    this.isRunning = false
+  }
+
+  start () {}
+
+  stop () {}
+}
+"""
+
+STUB_TYPES = """\
+export declare class App {
+  constructor (options: { version: string })
+  isRunning: boolean
+  start (): void
+  stop (): void
+}
+"""
+
+
+def write_stub_build(output_path):
+    for name in BUNDLES:
+        path = os.path.join(output_path, name)
+        os.makedirs(os.path.dirname(path), exist_ok=True)
+        with open(path, 'w', encoding='utf-8'):
+            pass
+    for name, text in (('index.js', STUB_MODULE), ('index.d.ts', STUB_TYPES)):
+        with open(os.path.join(output_path, name), 'w',
+                  encoding='utf-8') as out:
+            out.write(text)
+
+
 def main():
     args = parse_args()
 
-    pnpm = shutil.which('pnpm')
-    if not pnpm:
-        raise RuntimeError('Unable to find pnpm in PATH')
-
     with scoped_cwd(WEB_DISCOVERY_DIR):
         if args.verbose:
             enable_verbose_mode()
+        # Without node_modules there is nothing to build from, and pnpm is not
+        # in PATH either: the port drives it through corepack, and only for
+        # brave-core itself.  Leave the stubs behind instead.
+        if args.build and not os.path.isdir('node_modules'):
+            write_stub_build(args.output_path)
+            return
+        pnpm = shutil.which('pnpm')
+        if not pnpm:
+            raise RuntimeError('Unable to find pnpm in PATH')
         if args.install:
             execute_stdout([pnpm, 'install', '--frozen-lockfile', '--yes'])
         if args.build:
