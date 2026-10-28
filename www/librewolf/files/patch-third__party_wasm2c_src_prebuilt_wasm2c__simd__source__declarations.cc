--- third_party/wasm2c/src/prebuilt/wasm2c_simd_source_declarations.cc.orig	2026-10-19 22:04:14 UTC
+++ third_party/wasm2c/src/prebuilt/wasm2c_simd_source_declarations.cc
@@ -24,6 +24,10 @@
 )w2c_template"
 R"w2c_template(#define SIMD_FORCE_READ(var) __asm__("" ::"d"(var));
 )w2c_template"
+R"w2c_template(#elif defined(__powerpc64__) || defined(__ppc64__)
+)w2c_template"
+R"w2c_template(#define SIMD_FORCE_READ(var) __asm__("" ::"v"(var));
+)w2c_template"
 R"w2c_template(#else
 )w2c_template"
 R"w2c_template(#define SIMD_FORCE_READ(var) __asm__("" ::"f"(var));
