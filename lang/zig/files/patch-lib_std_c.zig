--- lib/std/c.zig.orig	2020-12-13 19:14:58 UTC
+++ lib/std/c.zig
@@ -346,3 +346,20 @@ pub extern "c" fn prctl(option: c_int, ...) c_int;
 
 pub extern "c" fn getrlimit(resource: rlimit_resource, rlim: *rlimit) c_int;
 pub extern "c" fn setrlimit(resource: rlimit_resource, rlim: *const rlimit) c_int;
+
+pub extern "c" fn fmemopen(noalias buf: ?*c_void, size: usize, noalias mode: [*:0]const u8) ?*FILE;
+
+pub extern "c" fn syslog(priority: c_int, message: [*:0]const u8, ...) void;
+pub extern "c" fn openlog(ident: [*:0]const u8, logopt: c_int, facility: c_int) void;
+pub extern "c" fn closelog() void;
+pub extern "c" fn setlogmask(maskpri: c_int) c_int;
+
+pub const max_align_t = if (std.Target.current.abi == .msvc)
+    f64
+else if (std.Target.current.isDarwin())
+    c_longdouble
+else
+    extern struct {
+        a: c_longlong,
+        b: c_longdouble,
+    };
