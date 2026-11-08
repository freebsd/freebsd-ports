--- third_party/federated_compute/third_party/protodatastore-cpp/src/protostore/file-storage.cc.orig	2026-08-13 16:48:13 UTC
+++ third_party/federated_compute/third_party/protodatastore-cpp/src/protostore/file-storage.cc
@@ -130,7 +130,7 @@ absl::Status IOError(absl::string_view context) {
     case ENETUNREACH:   // Network unreachable
     case ENOLCK:        // No locks available
     case ENOLINK:       // Link has been severed
-#if !(defined(__APPLE__) || defined(__FreeBSD__) || defined(_WIN32))
+#if !(defined(__APPLE__) || defined(__FreeBSD__) || defined(_WIN32) || defined(__OpenBSD__))
     case ENONET:  // Machine is not on the network
 #endif
       return absl::UnavailableError(message);
