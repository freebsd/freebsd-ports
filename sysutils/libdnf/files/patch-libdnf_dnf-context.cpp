-- recognize "arm64", which is what rpm reports as the target architecture on FreeBSD/aarch64

--- libdnf/dnf-context.cpp.orig	2025-10-20 13:41:49 UTC
+++ libdnf/dnf-context.cpp
@@ -94,7 +94,7 @@ static const struct {
     const gchar    *base;
     const gchar    *native[MAX_NATIVE_ARCHES];
 } arch_map[] =  {
-    { "aarch64",    { "aarch64", NULL } },
+    { "aarch64",    { "aarch64", "arm64", NULL } },
     { "alpha",      { "alpha", "alphaev4", "alphaev45", "alphaev5",
                       "alphaev56", "alphaev6", "alphaev67",
                       "alphaev68", "alphaev7", "alphapca56", NULL } },
