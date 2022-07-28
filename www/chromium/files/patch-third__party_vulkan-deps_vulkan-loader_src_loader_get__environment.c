--- third_party/vulkan-deps/vulkan-loader/src/loader/get_environment.c.orig	2022-07-22 17:30:31 UTC
+++ third_party/vulkan-deps/vulkan-loader/src/loader/get_environment.c
@@ -32,7 +32,7 @@
 #include "log.h"
 
 // Environment variables
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 
 bool is_high_integrity() { return geteuid() != getuid() || getegid() != getgid(); }
 
@@ -44,7 +44,7 @@ char *loader_getenv(const char *name, const struct loa
 }
 
 char *loader_secure_getenv(const char *name, const struct loader_instance *inst) {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
     // Apple does not appear to have a secure getenv implementation.
     // The main difference between secure getenv and getenv is that secure getenv
     // returns NULL if the process is being run with elevated privileges by a normal user.
