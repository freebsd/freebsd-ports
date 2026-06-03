--- core/src/system_monitor_service.rs.orig	2026-04-14 19:53:57 UTC
+++ core/src/system_monitor_service.rs
@@ -726,8 +726,7 @@ impl SystemMonitorService {
         const CPUID_MANUFACTURER_EDX_AMD: u32 = 0x69746e65;
         const CPUID_MANUFACTURER_ECX_AMD: u32 = 0x444d4163;
 
-        unsafe {
-            let cpuid_mfr = __cpuid(0);
+        let cpuid_mfr = __cpuid(0);
             let cpuid_empty = CpuidResult {
                 eax: 0,
                 ebx: 0,
@@ -807,7 +806,6 @@ impl SystemMonitorService {
                 ("cpuid_extended_0_edx", i64::from(cpuid_extended_0.edx), i64),
                 ("cpuid_extended_1_eax", i64::from(cpuid_extended_1.eax), i64),
             );
-        };
     }
 
     fn report_cpu_stats() {
