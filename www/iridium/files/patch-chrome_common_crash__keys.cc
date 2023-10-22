--- chrome/common/crash_keys.cc.orig	2023-11-22 14:00:11 UTC
+++ chrome/common/crash_keys.cc
@@ -32,20 +32,10 @@ namespace crash_keys {
 namespace {
 
 // A convenient wrapper around a crash key and its name.
-//
-// The CrashKey contract requires that CrashKeyStrings are never
-// moved, copied, or deleted (see
-// third_party/crashpad/crashpad/client/annotation.h); since this class holds
-// a CrashKeyString, it likewise cannot be moved, copied, or deleted.
 class CrashKeyWithName {
  public:
   explicit CrashKeyWithName(std::string name)
       : name_(std::move(name)), crash_key_(name_.c_str()) {}
-  CrashKeyWithName(const CrashKeyWithName&) = delete;
-  CrashKeyWithName& operator=(const CrashKeyWithName&) = delete;
-  CrashKeyWithName(CrashKeyWithName&&) = delete;
-  CrashKeyWithName& operator=(CrashKeyWithName&&) = delete;
-  ~CrashKeyWithName() = delete;
 
   void Clear() { crash_key_.Clear(); }
   void Set(base::StringPiece value) { crash_key_.Set(value); }
