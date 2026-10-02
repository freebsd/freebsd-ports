-- Fix cross-DLL Boost.Python exception translation on FreeBSD.
-- Move exported exception-class destructors out-of-line so the Itanium ABI
-- emits a single typeinfo/vtable instance per class in its owning shared
-- library. Without this each shared module has its own local typeinfo copy
-- and catch-by-derived-type in Python exception translators fails.

--- Code/RDGeneral/BadFileException.h.orig	2026-08-28 02:56:41 UTC
+++ Code/RDGeneral/BadFileException.h
@@ -29,7 +29,7 @@ class RDKIT_RDGENERAL_EXPORT BadFileException : public
       : std::runtime_error("BadFileException"), _msg(std::move(msg)) {}
   //! get the error message
   const char *what() const noexcept override { return _msg.c_str(); }
-  ~BadFileException() noexcept override = default;
+  ~BadFileException() noexcept override;
 
  private:
   std::string _msg;
