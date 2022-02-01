--- third_party/abseil-cpp/absl/debugging/internal/vdso_support.cc.orig	2021-12-31 00:57:39 UTC
+++ third_party/abseil-cpp/absl/debugging/internal/vdso_support.cc
@@ -101,7 +101,11 @@ const void *VDSOSupport::Init() {
       getcpu_fn_.store(&GetCPUViaSyscall, std::memory_order_relaxed);
       return nullptr;
     }
+#if defined(__FreeBSD__)
+    __ElfN(Auxinfo) aux;
+#else
     ElfW(auxv_t) aux;
+#endif
     while (read(fd, &aux, sizeof(aux)) == sizeof(aux)) {
       if (aux.a_type == AT_SYSINFO_EHDR) {
         vdso_base_.store(reinterpret_cast<void *>(aux.a_un.a_val),
