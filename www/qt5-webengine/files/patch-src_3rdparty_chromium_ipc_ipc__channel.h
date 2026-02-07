--- src/3rdparty/chromium/ipc/ipc_channel.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ipc/ipc_channel.h
@@ -245,7 +245,7 @@ class COMPONENT_EXPORT(IPC) Channel : public Sender {
   static std::string GenerateUniqueRandomChannelID();
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
