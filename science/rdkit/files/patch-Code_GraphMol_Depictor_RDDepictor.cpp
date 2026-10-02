-- Fix cross-DLL Boost.Python exception translation on FreeBSD.
-- Move exported exception-class destructors out-of-line so the Itanium ABI
-- emits a single typeinfo/vtable instance per class in its owning shared
-- library. Without this each shared module has its own local typeinfo copy
-- and catch-by-derived-type in Python exception translators fails.

--- Code/GraphMol/Depictor/RDDepictor.cpp.orig	2026-08-28 02:56:41 UTC
+++ Code/GraphMol/Depictor/RDDepictor.cpp
@@ -38,6 +38,8 @@ bool preferCoordGen = false;
 
 bool preferCoordGen = false;
 
+DepictException::~DepictException() noexcept = default;
+
 namespace DepictorLocal {
 
 constexpr auto ISQRT2 = 0.707107;
