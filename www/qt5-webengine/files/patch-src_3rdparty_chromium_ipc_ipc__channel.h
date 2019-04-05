--- src/3rdparty/chromium/ipc/ipc_channel.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ipc/ipc_channel.h
@@ -244,7 +244,7 @@ class COMPONENT_EXPORT(IPC) Channel : public Sender {
   static std::string GenerateUniqueRandomChannelID();
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
