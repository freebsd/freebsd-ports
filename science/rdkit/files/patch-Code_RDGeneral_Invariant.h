-- Fix cross-DLL Boost.Python exception translation on FreeBSD.
-- Move exported exception-class destructors out-of-line so the Itanium ABI
-- emits a single typeinfo/vtable instance per class in its owning shared
-- library. Without this each shared module has its own local typeinfo copy
-- and catch-by-derived-type in Python exception translators fails.

--- Code/RDGeneral/Invariant.h.orig	2026-08-28 02:56:41 UTC
+++ Code/RDGeneral/Invariant.h
@@ -65,7 +65,7 @@ class RDKIT_RDGENERAL_EXPORT Invariant : public std::r
         prefix_d(prefix),
         file_dp(file),
         line_d(line) {}
-  ~Invariant() noexcept override = default;
+  ~Invariant() noexcept override;
 
   const char *what() const noexcept override { return mess_d.c_str(); }
 
