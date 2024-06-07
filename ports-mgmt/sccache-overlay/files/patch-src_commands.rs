--- src/commands.rs.orig	2024-06-03 08:36:26 UTC
+++ src/commands.rs
@@ -46,7 +46,7 @@ pub const DEFAULT_PORT: u16 = 4226;
 pub const DEFAULT_PORT: u16 = 4226;
 
 /// The number of milliseconds to wait for server startup.
-const SERVER_STARTUP_TIMEOUT_MS: u32 = 10000;
+const SERVER_STARTUP_TIMEOUT_MS: u32 = 30000;
 
 /// Get the port on which the server should listen.
 fn get_port() -> u16 {
