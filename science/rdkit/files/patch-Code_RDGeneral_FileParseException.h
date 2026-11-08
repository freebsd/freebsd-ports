-- Fix cross-DLL Boost.Python exception translation on FreeBSD.
-- Move exported exception-class destructors out-of-line so the Itanium ABI
-- emits a single typeinfo/vtable instance per class in its owning shared
-- library. Without this each shared module has its own local typeinfo copy
-- and catch-by-derived-type in Python exception translators fails.

--- Code/RDGeneral/FileParseException.h.orig	2026-08-28 02:56:41 UTC
+++ Code/RDGeneral/FileParseException.h
@@ -26,7 +26,7 @@ class RDKIT_RDGENERAL_EXPORT FileParseException : publ
       : std::runtime_error("FileParseException"), _msg(msg) {}
   //! get the error message
   const char *what() const noexcept override { return _msg.c_str(); }
-  ~FileParseException() noexcept override = default;
+  ~FileParseException() noexcept override;
 
  private:
   std::string _msg;
