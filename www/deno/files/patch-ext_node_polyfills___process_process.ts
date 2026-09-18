--- ext/node/polyfills/_process/process.ts.orig	2026-09-17 22:38:34 UTC
+++ ext/node/polyfills/_process/process.ts
@@ -47,7 +47,7 @@ function arch(): string {
     return "riscv64";
   } else if (build.arch == "loongarch64") {
     return "loong64";
-  } else if (build.arch == "powerpc64le") {
+  } else if (build.arch == "powerpc64le" || build.arch == "powerpc64") {
     return "ppc64";
   } else {
     throw new Error("unreachable");
