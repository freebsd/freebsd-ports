--- client/hostinfo_unix.cpp.orig	2025-11-24 08:44:26 UTC
+++ client/hostinfo_unix.cpp
@@ -178,7 +178,7 @@ int podman_init_pid = 0;
 // The following is intended to be true both on Linux
 // and Debian GNU/kFreeBSD (see trac #521)
 //
-#if (defined(__linux__) || defined(__GNU__) || defined(__GLIBC__))  && !defined(__HAIKU__)
+#if (defined(__linux__) || defined(__GNU__) || defined(__GLIBC__) || defined(__freebsd__))  && !defined(__HAIKU__)
 #define LINUX_LIKE_SYSTEM 1
 #endif
 
@@ -748,48 +748,211 @@ static void parse_cpuinfo_linux(HOST_INFO& host) {
 #include <machine/cpufunc.h>
 #include <machine/specialreg.h>
 
+// XGETBV isn't reliably exposed to userland via <machine/cpufunc.h> across
+// all supported FreeBSD releases, so emit the opcode directly.
+//
+static __inline uint64_t bsd_xgetbv(u_int index) {
+    uint32_t eax, edx;
+    __asm__ __volatile__(".byte 0x0f, 0x01, 0xd0"
+        : "=a" (eax), "=d" (edx) : "c" (index));
+    return ((uint64_t)edx << 32) | eax;
+}
+
+// do_cpuid() only constrains EAX as input; ECX is left unspecified,
+// which is fine for leaves without sub-leaves but wrong for leaf 7,
+// whose sub-leaf is selected by ECX on input. Query it explicitly
+// rather than relying on ECX happening to be zero -- and rather than
+// relying on cpuid_count(), which isn't available on all FreeBSD
+// releases this code targets.
+static __inline void bsd_cpuid_count(u_int leaf, u_int subleaf, u_int *p) {
+    __asm__ __volatile__("cpuid"
+        : "=a" (p[0]), "=b" (p[1]), "=c" (p[2]), "=d" (p[3])
+        : "0" (leaf), "c" (subleaf));
+}
+
 void use_cpuid(HOST_INFO& host) {
     u_int p[4];
-    u_int cpu_id;
+    u_int cpu_id = 0;
+    u_int max_std_leaf = 0, max_ext_leaf = 0;
+    u_int std_ecx = 0, std_edx = 0;
+    u_int ext_ecx = 0, ext_edx = 0;
+    u_int ext7_ebx = 0;
     char vendor[13];
-    int hasMMX, hasSSE, hasSSE2, hasSSE3, has3DNow, has3DNowExt, hasAVX;
+    int intel_vendor = 0, amd_vendor = 0, hygon_vendor = 0;
     char capabilities[P_FEATURES_SIZE];
 
-    hasMMX = hasSSE = hasSSE2 = hasSSE3 = has3DNow = has3DNowExt = hasAVX = 0;
+    capabilities[0] = '\0';
+    vendor[0] = '\0';
+ 
+    // Leaf 0: highest standard leaf + vendor string. Copy the vendor
+    // bytes out of EBX/EDX/ECX immediately -- p[] gets overwritten by
+    // the very next do_cpuid() call, so extracting "vendor" after
+    // calling leaf 1 reads stale data.
+    //
     do_cpuid(0x0, p);
+    max_std_leaf = p[0];
+    memcpy(vendor, &p[1], 4); // copy EBX
+    memcpy(vendor+4, &p[3], 4); // copy EDX
+    memcpy(vendor+8, &p[2], 4); // copy ECX
+    vendor[12] = '\0';
 
-    if (p[0] >= 0x1) {
+    if (!strcmp(vendor, "GenuineIntel")) intel_vendor = 1;
+    if (!strcmp(vendor, "AuthenticAMD")) amd_vendor = 1;
+    if (!strcmp(vendor, "HygonGenuine")) hygon_vendor = 1;
 
+    // Leaf 1: standard feature flags + family/model/stepping.
+    if (max_std_leaf >= 0x1) {
         do_cpuid(0x1, p);
-
         cpu_id = p[0];
-        memcpy(vendor, &p[1], 4);   // copy EBX
-        memcpy(vendor+4, &p[3], 4); // copy EDX
-        memcpy(vendor+8, &p[2], 4); // copy ECX
-        vendor[12] = '\0';
-        hasMMX  = (p[3] & (1 << 23 )) >> 23; // 0x0800000
-        hasSSE  = (p[3] & (1 << 25 )) >> 25; // 0x2000000
-        hasSSE2 = (p[3] & (1 << 26 )) >> 26; // 0x4000000
-        hasAVX  = (p[2] & (1 << 28 )) >> 28;
-        hasSSE3 = (p[2] & (1 << 0 )) >> 0;
+        std_ecx = p[2];
+        std_edx = p[3];
     }
+    // Leaf 7, sub-leaf 0: structured extended feature flags.
+    if (max_std_leaf >= 0x7) {
+        bsd_cpuid_count(0x7, 0, p);
+        ext7_ebx = p[1];
+    }
 
+    // Leaf 0x80000000: highest extended leaf.
     do_cpuid(0x80000000, p);
-    if (p[0]>=0x80000001) {
+    max_ext_leaf = p[0];
+
+    // Leaf 0x80000001: extended feature flags.
+    if (max_ext_leaf >= 0x80000001) {
         do_cpuid(0x80000001, p);
-        hasMMX  |= (p[3] & (1 << 23 )) >> 23; // 0x0800000
-        has3DNow    = (p[3] & (1 << 31 )) >> 31; //0x80000000
-        has3DNowExt = (p[3] & (1 << 30 )) >> 30;
+        ext_ecx = p[2];
+        ext_edx = p[3];
     }
 
-    capabilities[0] = '\0';
-    if (hasSSE) safe_strcat(capabilities, "sse ");
-    if (hasSSE2) safe_strcat(capabilities, "sse2 ");
-    if (hasSSE3) safe_strcat(capabilities, "pni ");
-    if (has3DNow) safe_strcat(capabilities, "3dnow ");
-    if (has3DNowExt) safe_strcat(capabilities, "3dnowext ");
-    if (hasMMX) safe_strcat(capabilities, "mmx ");
-    if (hasAVX) safe_strcat(capabilities, "avx ");
+    // --- Standard EDX features (leaf 1) ---
+    if (std_edx & (1 << 0 )) safe_strcat(capabilities, "fpu ");
+    if (std_edx & (1 << 1 )) safe_strcat(capabilities, "vme ");
+    if (std_edx & (1 << 2 )) safe_strcat(capabilities, "de ");
+    if (std_edx & (1 << 3 )) safe_strcat(capabilities, "pse ");
+    if (std_edx & (1 << 4 )) safe_strcat(capabilities, "tsc ");
+    if (std_edx & (1 << 5 )) safe_strcat(capabilities, "msr ");
+    if (std_edx & (1 << 6 )) safe_strcat(capabilities, "pae ");
+    if (std_edx & (1 << 7 )) safe_strcat(capabilities, "mce ");
+    if (std_edx & (1 << 8 )) safe_strcat(capabilities, "cx8 ");
+    if (std_edx & (1 << 9 )) safe_strcat(capabilities, "apic ");
+    if (std_edx & (1 << 11)) safe_strcat(capabilities, "sep ");
+    if (std_edx & (1 << 12)) safe_strcat(capabilities, "mtrr ");
+    if (std_edx & (1 << 13)) safe_strcat(capabilities, "pge ");
+    if (std_edx & (1 << 14)) safe_strcat(capabilities, "mca ");
+    if (std_edx & (1 << 15)) safe_strcat(capabilities, "cmov ");
+    if (std_edx & (1 << 16)) safe_strcat(capabilities, "pat ");
+    if (std_edx & (1 << 17)) safe_strcat(capabilities, "pse36 ");
+    if (std_edx & (1 << 18)) safe_strcat(capabilities, "psn ");
+    if (std_edx & (1 << 19)) safe_strcat(capabilities, "clflush ");
+    if (std_edx & (1 << 21)) safe_strcat(capabilities, "dts ");
+    if (std_edx & (1 << 22)) safe_strcat(capabilities, "acpi ");
+    if (std_edx & (1 << 23)) safe_strcat(capabilities, "mmx ");
+    if (std_edx & (1 << 24)) safe_strcat(capabilities, "fxsr ");
+    if (std_edx & (1 << 25)) safe_strcat(capabilities, "sse ");
+    if (std_edx & (1 << 26)) safe_strcat(capabilities, "sse2 ");
+    if (std_edx & (1 << 27)) safe_strcat(capabilities, "ss ");
+    if (std_edx & (1 << 28)) safe_strcat(capabilities, "htt ");
+    if (std_edx & (1 << 29)) safe_strcat(capabilities, "tm ");
+
+    // --- Standard ECX features (leaf 1) ---
+    if (std_ecx & (1 << 0 )) safe_strcat(capabilities, "pni "); // SSE3
+    if (std_ecx & (1 << 1 )) safe_strcat(capabilities, "pclmulqdq ");
+    if (std_ecx & (1 << 2 )) safe_strcat(capabilities, "dtes64 ");
+    if (std_ecx & (1 << 3 )) safe_strcat(capabilities, "monitor ");
+    if (std_ecx & (1 << 4 )) safe_strcat(capabilities, "ds_cpl ");
+    if (std_ecx & (1 << 9 )) safe_strcat(capabilities, "ssse3 ");
+    if (std_ecx & (1 << 12)) safe_strcat(capabilities, "fma ");
+    if (std_ecx & (1 << 13)) safe_strcat(capabilities, "cx16 ");
+    if (std_ecx & (1 << 17)) safe_strcat(capabilities, "pcid ");
+    if (std_ecx & (1 << 19)) safe_strcat(capabilities, "sse4_1 ");
+    if (std_ecx & (1 << 20)) safe_strcat(capabilities, "sse4_2 ");
+    if (std_ecx & (1 << 21)) safe_strcat(capabilities, "x2apic ");
+    if (std_ecx & (1 << 22)) safe_strcat(capabilities, "movbe ");
+    if (std_ecx & (1 << 23)) safe_strcat(capabilities, "popcnt ");
+    if (std_ecx & (1 << 25)) safe_strcat(capabilities, "aes ");
+    if (std_ecx & (1 << 26)) safe_strcat(capabilities, "xsave ");
+    if (std_ecx & (1 << 29)) safe_strcat(capabilities, "f16c ");
+    if (std_ecx & (1 << 30)) safe_strcat(capabilities, "rdrand ");
+    if (std_ecx & (1u << 31)) safe_strcat(capabilities, "hypervisor ");
+
+    // AVX/AVX2 require the raw CPUID bit *and* OS support: OSXSAVE
+    // (leaf 1 ECX bit 27) and XSAVE (bit 26) must both be set before
+    // XGETBV's output can be trusted at all, and XGETBV(0) must then
+    // confirm the OS actually saves YMM state (XCR0 bits 1:2).
+    // Trusting the raw AVX bit alone gives false positives if the OS
+    // hasn't opted in; checking OSXSAVE without XSAVE is not
+    // architecturally sufficient.
+    //
+    {
+        int has_avx_bit = (std_ecx & (1 << 28)) ? 1 : 0;
+        int has_osxsave = (std_ecx & (1 << 27)) ? 1 : 0;
+        int has_xsave   = (std_ecx & (1 << 26)) ? 1 : 0;
+        int os_avx_ok = 0;
+        if (has_avx_bit && has_osxsave && has_xsave) {
+            uint64_t xcr0 = bsd_xgetbv(0);
+            if ((xcr0 & 0x6) == 0x6) {
+                os_avx_ok = 1;
+                safe_strcat(capabilities, "avx ");
+            }
+        }
+        if (os_avx_ok && (ext7_ebx & (1 << 5))) {
+            safe_strcat(capabilities, "avx2 ");
+        }
+    }
+
+    // --- Extended EDX features (leaf 0x80000001) ---
+    if (ext_edx & (1 << 11)) safe_strcat(capabilities, "syscall ");
+    if (ext_edx & (1 << 20)) safe_strcat(capabilities, "nx ");
+    if (ext_edx & (1 << 26)) safe_strcat(capabilities, "pdpe1gb ");
+    if (ext_edx & (1 << 27)) safe_strcat(capabilities, "rdtscp ");
+    if (ext_edx & (1 << 29)) safe_strcat(capabilities, "lm ");
+    if (ext_edx & (1 << 30)) safe_strcat(capabilities, "3dnowext ");
+    if (ext_edx & (1 << 31)) safe_strcat(capabilities, "3dnow ");
+
+    // --- Vendor-specific features ---
+    if (intel_vendor) {
+        if (std_ecx & (1 << 5 )) safe_strcat(capabilities, "vmx ");
+        if (std_ecx & (1 << 6 )) safe_strcat(capabilities, "smx ");
+        if (std_ecx & (1 << 8 )) safe_strcat(capabilities, "tm2 ");
+        if (std_ecx & (1 << 7 )) safe_strcat(capabilities, "est ");
+        if (std_ecx & (1 << 14)) safe_strcat(capabilities, "xtpr ");
+        if (std_ecx & (1 << 15)) safe_strcat(capabilities, "pdcm ");
+        if (std_ecx & (1 << 24)) safe_strcat(capabilities, "tsc_deadline_timer ");
+        if (std_ecx & (1 << 18)) safe_strcat(capabilities, "dca ");
+        if (std_edx & (1 << 31)) safe_strcat(capabilities, "pbe ");
+    }
+
+    if (ext_ecx & (1 << 0 )) safe_strcat(capabilities, "lahf_lm ");
+    if (ext_ecx & (1 << 8 )) safe_strcat(capabilities, "3dnowprefetch ");
+    if (amd_vendor || hygon_vendor) {
+        if (ext_ecx & (1 << 2 )) safe_strcat(capabilities, "svm ");
+        if (ext_ecx & (1 << 5 )) safe_strcat(capabilities, "abm ");
+        if (ext_ecx & (1 << 6 )) safe_strcat(capabilities, "sse4a ");
+        if (ext_ecx & (1 << 9 )) safe_strcat(capabilities, "osvw ");
+        if (ext_ecx & (1 << 10)) safe_strcat(capabilities, "ibs ");
+        if (ext_ecx & (1 << 11)) safe_strcat(capabilities, "xop ");
+        if (ext_ecx & (1 << 12)) safe_strcat(capabilities, "skinit ");
+        if (ext_ecx & (1 << 13)) safe_strcat(capabilities, "wdt ");
+        if (ext_ecx & (1 << 15)) safe_strcat(capabilities, "lwp ");
+        if (ext_ecx & (1 << 16)) safe_strcat(capabilities, "fma4 ");
+        if (ext_ecx & (1 << 17)) safe_strcat(capabilities, "tce ");
+        if (ext_ecx & (1 << 18)) safe_strcat(capabilities, "cvt16 ");
+        if (ext_ecx & (1 << 21)) safe_strcat(capabilities, "tbm ");
+        if (ext_ecx & (1 << 22)) safe_strcat(capabilities, "topoext "); // NOT "topx"
+    }
+
+    // --- Structured extended features (leaf 7, sub-leaf 0 EBX) ---
+    if (ext7_ebx & (1 << 0 )) safe_strcat(capabilities, "fsgsbase ");
+    if (ext7_ebx & (1 << 1 )) safe_strcat(capabilities, "tsc_adjust ");
+    if (ext7_ebx & (1 << 3 )) safe_strcat(capabilities, "bmi1 ");
+    if (ext7_ebx & (1 << 4 )) safe_strcat(capabilities, "hle ");
+    if (ext7_ebx & (1 << 7 )) safe_strcat(capabilities, "smep ");
+    if (ext7_ebx & (1 << 8 )) safe_strcat(capabilities, "bmi2 ");
+    if (ext7_ebx & (1 << 9 )) safe_strcat(capabilities, "erms ");
+    if (ext7_ebx & (1 << 10)) safe_strcat(capabilities, "invpcid ");
+    if (ext7_ebx & (1 << 18)) safe_strcat(capabilities, "rdseed ");
+    if (ext7_ebx & (1 << 19)) safe_strcat(capabilities, "adx ");
+
     strip_whitespace(capabilities);
     char buf[1024];
     snprintf(buf, sizeof(buf), " [Family %u Model %u Stepping %u]",
