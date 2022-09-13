--- third_party/cpuinfo/cpuinfo.BUILD.orig	2022-05-22 22:28:22 UTC
+++ third_party/cpuinfo/cpuinfo.BUILD
@@ -100,35 +100,7 @@ EMSCRIPTEN_SRCS = [
 cc_library(
     name = "cpuinfo_impl",
     srcs = select({
-        ":linux_x86_64": COMMON_SRCS + X86_SRCS + LINUX_SRCS + LINUX_X86_SRCS,
-        ":linux_arm": COMMON_SRCS + ARM_SRCS + LINUX_SRCS + LINUX_ARM32_SRCS,
-        ":linux_armhf": COMMON_SRCS + ARM_SRCS + LINUX_SRCS + LINUX_ARM32_SRCS,
-        ":linux_armv7a": COMMON_SRCS + ARM_SRCS + LINUX_SRCS + LINUX_ARM32_SRCS,
-        ":linux_armeabi": COMMON_SRCS + ARM_SRCS + LINUX_SRCS + LINUX_ARM32_SRCS,
-        ":linux_aarch64": COMMON_SRCS + ARM_SRCS + LINUX_SRCS + LINUX_ARM64_SRCS,
-        ":linux_mips64": COMMON_SRCS + LINUX_SRCS,
-        ":linux_riscv64": COMMON_SRCS + LINUX_SRCS,
-        ":linux_s390x": COMMON_SRCS + LINUX_SRCS,
-        ":macos_x86_64": COMMON_SRCS + X86_SRCS + MACH_SRCS + MACH_X86_SRCS,
-        ":macos_arm64": COMMON_SRCS + MACH_SRCS + MACH_ARM_SRCS,
-        ":windows_x86_64": COMMON_SRCS + X86_SRCS + WINDOWS_X86_SRCS,
-        ":android_armv7": COMMON_SRCS + ARM_SRCS + LINUX_SRCS + LINUX_ARM32_SRCS + ANDROID_ARM_SRCS,
-        ":android_arm64": COMMON_SRCS + ARM_SRCS + LINUX_SRCS + LINUX_ARM64_SRCS + ANDROID_ARM_SRCS,
-        ":android_x86": COMMON_SRCS + X86_SRCS + LINUX_SRCS + LINUX_X86_SRCS,
-        ":android_x86_64": COMMON_SRCS + X86_SRCS + LINUX_SRCS + LINUX_X86_SRCS,
-        ":ios_x86_64": COMMON_SRCS + X86_SRCS + MACH_SRCS + MACH_X86_SRCS,
-        ":ios_x86": COMMON_SRCS + X86_SRCS + MACH_SRCS + MACH_X86_SRCS,
-        ":ios_armv7": COMMON_SRCS + MACH_SRCS + MACH_ARM_SRCS,
-        ":ios_arm64": COMMON_SRCS + MACH_SRCS + MACH_ARM_SRCS,
-        ":ios_arm64e": COMMON_SRCS + MACH_SRCS + MACH_ARM_SRCS,
-        ":ios_sim_arm64": COMMON_SRCS + MACH_SRCS + MACH_ARM_SRCS,
-        ":watchos_x86_64": COMMON_SRCS + X86_SRCS + MACH_SRCS + MACH_X86_SRCS,
-        ":watchos_x86": COMMON_SRCS + X86_SRCS + MACH_SRCS + MACH_X86_SRCS,
-        ":watchos_armv7k": COMMON_SRCS + MACH_SRCS + MACH_ARM_SRCS,
-        ":watchos_arm64_32": COMMON_SRCS + MACH_SRCS + MACH_ARM_SRCS,
-        ":tvos_x86_64": COMMON_SRCS + X86_SRCS + MACH_SRCS + MACH_X86_SRCS,
-        ":tvos_arm64": COMMON_SRCS + MACH_SRCS + MACH_ARM_SRCS,
-        ":emscripten_wasm": COMMON_SRCS + EMSCRIPTEN_SRCS,
+        "//conditions:default": COMMON_SRCS + X86_SRCS + MACH_SRCS + MACH_X86_SRCS,
     }),
     copts = select({
         ":windows_x86_64": [],
@@ -187,6 +159,11 @@ cc_library(
 )
 
 ############################# Build configurations #############################
+
+config_setting(
+    name = "default",
+    values = {"cpu": "k8"},
+)
 
 config_setting(
     name = "linux_x86_64",
