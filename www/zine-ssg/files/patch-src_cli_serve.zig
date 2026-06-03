--- src/cli/serve.zig.orig	2026-03-13 17:52:18 UTC
+++ src/cli/serve.zig
@@ -24,6 +24,7 @@ const Watcher = switch (builtin.target.os.tag) {
 const outside_html = @embedFile("serve/outside.html");
 const Watcher = switch (builtin.target.os.tag) {
     .linux => @import("serve/watcher/LinuxWatcher.zig"),
+    .freebsd => @import("serve/watcher/LinuxWatcher.zig"),
     .macos => @import("serve/watcher/MacosWatcher.zig"),
     .windows => @import("serve/watcher/WindowsWatcher.zig"),
     else => @compileError("unsupported platform"),
