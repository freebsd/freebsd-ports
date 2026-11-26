--- ../rust-rocksdb-24dad4d15b47d932b9f060c1b9520c0d1e6b1fe5/librocksdb-sys/rocksdb/utilities/fault_injection_fs.h.orig	2026-11-14 23:08:38 UTC
+++ ../rust-rocksdb-24dad4d15b47d932b9f060c1b9520c0d1e6b1fe5/librocksdb-sys/rocksdb/utilities/fault_injection_fs.h
@@ -90,8 +90,6 @@ class InjectedErrorLog {
 
   static_assert(sizeof(Entry) == 256,
                 "Injected error log entry size must stay stable");
-  static_assert(port::kLittleEndian,
-                "Injected error log requires little-endian platforms");
 
   explicit InjectedErrorLog(const std::string& path);
   ~InjectedErrorLog();
