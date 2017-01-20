------------------------------------------------------------------------
r165961 | rgabor@webkit.org | 2014-03-20 18:03:43 +0400 (Thu, 20 Mar 2014) | 15 lines

[...]
https://bugs.webkit.org/show_bug.cgi?id=130502
[...]
Delete shouldBlindForSpecificArch(uintptr_t) because on ARM64 uint64_t
and uintptr_t is the same with GCC and Clang as well.

--- Source/JavaScriptCore/assembler/MacroAssemblerARM64.h.orig	2016-04-10 06:48:36 UTC
+++ Source/JavaScriptCore/assembler/MacroAssemblerARM64.h
@@ -130,7 +130,6 @@ public:
     // FIXME: Get reasonable implementations for these
     static bool shouldBlindForSpecificArch(uint32_t value) { return value >= 0x00ffffff; }
     static bool shouldBlindForSpecificArch(uint64_t value) { return value >= 0x00ffffff; }
-    static bool shouldBlindForSpecificArch(uintptr_t value) { return value >= 0x00ffffff; }
 
     // Integer operations:
 
