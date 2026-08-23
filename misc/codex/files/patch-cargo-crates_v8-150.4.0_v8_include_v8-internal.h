--- cargo-crates/v8-150.4.0/v8/include/v8-internal.h.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-150.4.0/v8/include/v8-internal.h
@@ -218,7 +218,7 @@ using SandboxedPointer_t = Address;
 #ifdef V8_ENABLE_SANDBOX
 
 // Size of the sandbox, excluding the guard regions surrounding it.
-#if defined(V8_TARGET_OS_ANDROID)
+#if (defined(V8_TARGET_OS_ANDROID) || defined(V8_TARGET_OS_OPENBSD))
 // On Android, most 64-bit devices seem to be configured with only 39 bits of
 // virtual address space for userspace. As such, limit the sandbox to 128GB (a
 // quarter of the total available address space).
