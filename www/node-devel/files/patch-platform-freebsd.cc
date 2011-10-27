--- deps/v8/src/platform-freebsd.cc.orig	2011-10-25 19:44:21.000000000 +0800
+++ deps/v8/src/platform-freebsd.cc	2011-10-25 20:08:08.000000000 +0800
@@ -333,32 +333,96 @@ int OS::StackWalk(Vector<OS::StackFrame>
 static const int kMmapFd = -1;
 static const int kMmapFdOffset = 0;
 
+VirtualMemory::VirtualMemory() : address_(NULL), size_(0) { }
+
+
+VirtualMemory::VirtualMemory(size_t size)
+    : address_(ReserveRegion(size)), size_(size) { }
 
-VirtualMemory::VirtualMemory(size_t size) {
-  address_ = mmap(NULL, size, PROT_NONE,
-                  MAP_PRIVATE | MAP_ANON | MAP_NORESERVE,
-                  kMmapFd, kMmapFdOffset);
-  size_ = size;
-}
 
+VirtualMemory::VirtualMemory(size_t size, size_t alignment)
+    : address_(NULL), size_(0) {
+  ASSERT(IsAligned(alignment, static_cast<intptr_t>(OS::AllocateAlignment())));
+  size_t request_size = RoundUp(size + alignment,
+                                static_cast<intptr_t>(OS::AllocateAlignment()));
+  void* reservation = mmap(OS::GetRandomMmapAddr(),
+                           request_size,
+                           PROT_NONE,
+                           MAP_PRIVATE | MAP_ANON | MAP_NORESERVE,
+                           kMmapFd,
+                           kMmapFdOffset);
+  if (reservation == MAP_FAILED) return;
+
+  Address base = static_cast<Address>(reservation);
+  Address aligned_base = RoundUp(base, alignment);
+  ASSERT_LE(base, aligned_base);
+
+  // Unmap extra memory reserved before and after the desired block.
+  if (aligned_base != base) {
+    size_t prefix_size = static_cast<size_t>(aligned_base - base);
+    OS::Free(base, prefix_size);
+    request_size -= prefix_size;
+  }
+
+  size_t aligned_size = RoundUp(size, OS::AllocateAlignment());
+  ASSERT_LE(aligned_size, request_size);
+
+  if (aligned_size != request_size) {
+    size_t suffix_size = request_size - aligned_size;
+    OS::Free(aligned_base + aligned_size, suffix_size);
+    request_size -= suffix_size;
+  }
+
+  ASSERT(aligned_size == request_size);
+
+  address_ = static_cast<void*>(aligned_base);
+  size_ = aligned_size;
+}
 
 VirtualMemory::~VirtualMemory() {
   if (IsReserved()) {
-    if (0 == munmap(address(), size())) address_ = MAP_FAILED;
+    bool result = ReleaseRegion(address(), size());
+    ASSERT(result);
+    USE(result);
   }
 }
 
+void VirtualMemory::Reset() {
+  address_ = NULL;
+  size_ = 0;
+}
+
+void* VirtualMemory::ReserveRegion(size_t size) {
+  void* result = mmap(OS::GetRandomMmapAddr(),
+                      size,
+                      PROT_NONE,
+                      MAP_PRIVATE | MAP_ANON | MAP_NORESERVE,
+                      kMmapFd,
+                      kMmapFdOffset);
+
+  if (result == MAP_FAILED) return NULL;
+
+  return result;
+}
 
 bool VirtualMemory::IsReserved() {
   return address_ != MAP_FAILED;
 }
 
+bool VirtualMemory::Commit(void* address, size_t size, bool is_executable) {
+  return CommitRegion(address, size, is_executable);
+}
 
-bool VirtualMemory::Commit(void* address, size_t size, bool executable) {
-  int prot = PROT_READ | PROT_WRITE | (executable ? PROT_EXEC : 0);
-  if (MAP_FAILED == mmap(address, size, prot,
+bool VirtualMemory::CommitRegion(void* address,
+                                 size_t size,
+                                 bool is_executable) {
+  int prot = PROT_READ | PROT_WRITE | (is_executable ? PROT_EXEC : 0);
+  if (MAP_FAILED == mmap(address,
+                         size,
+                         prot,
                          MAP_PRIVATE | MAP_ANON | MAP_FIXED,
-                         kMmapFd, kMmapFdOffset)) {
+                         kMmapFd,
+                         kMmapFdOffset)) {
     return false;
   }
 
@@ -366,13 +430,22 @@ bool VirtualMemory::Commit(void* address
   return true;
 }
 
-
 bool VirtualMemory::Uncommit(void* address, size_t size) {
-  return mmap(address, size, PROT_NONE,
+  return UncommitRegion(address, size);
+}
+
+bool VirtualMemory::UncommitRegion(void* address, size_t size) {
+  return mmap(address,
+              size,
+              PROT_NONE,
               MAP_PRIVATE | MAP_ANON | MAP_NORESERVE | MAP_FIXED,
-              kMmapFd, kMmapFdOffset) != MAP_FAILED;
+              kMmapFd,
+              kMmapFdOffset) != MAP_FAILED;
 }
 
+bool VirtualMemory::ReleaseRegion(void* address, size_t size) {
+  return munmap(address, size) == 0;
+}
 
 class Thread::PlatformData : public Malloced {
  public:
