-- Fix cross-DLL Boost.Python exception translation on FreeBSD.
-- Move exported exception-class destructors out-of-line so the Itanium ABI
-- emits a single typeinfo/vtable instance per class in its owning shared
-- library. Without this each shared module has its own local typeinfo copy
-- and catch-by-derived-type in Python exception translators fails.

--- Code/RDGeneral/Invariant.cpp.orig	2026-08-28 02:56:41 UTC
+++ Code/RDGeneral/Invariant.cpp
@@ -72,4 +72,6 @@ std::string Invariant::toUserString() const {
   return stringRep;
 }
 
+Invariant::~Invariant() noexcept = default;
+
 };  // namespace Invar
