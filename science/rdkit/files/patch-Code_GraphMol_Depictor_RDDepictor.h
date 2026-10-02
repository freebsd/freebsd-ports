-- Fix cross-DLL Boost.Python exception translation on FreeBSD.
-- Move exported exception-class destructors out-of-line so the Itanium ABI
-- emits a single typeinfo/vtable instance per class in its owning shared
-- library. Without this each shared module has its own local typeinfo copy
-- and catch-by-derived-type in Python exception translators fails.

--- Code/GraphMol/Depictor/RDDepictor.h.orig	2026-08-28 02:56:41 UTC
+++ Code/GraphMol/Depictor/RDDepictor.h
@@ -33,7 +33,7 @@ class RDKIT_DEPICTOR_EXPORT DepictException : public s
   DepictException(const char *msg) : _msg(msg) {}
   DepictException(const std::string msg) : _msg(msg) {}
   const char *what() const noexcept override { return _msg.c_str(); }
-  ~DepictException() noexcept override = default;
+  ~DepictException() noexcept override;
 
  private:
   std::string _msg;
