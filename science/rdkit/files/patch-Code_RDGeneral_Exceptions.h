-- Fix cross-DLL Boost.Python exception translation on FreeBSD.
-- Move exported exception-class destructors out-of-line so the Itanium ABI
-- emits a single typeinfo/vtable instance per class in its owning shared
-- library. Without this each shared module has its own local typeinfo copy
-- and catch-by-derived-type in Python exception translators fails.

--- Code/RDGeneral/Exceptions.h.orig	2026-08-28 02:56:41 UTC
+++ Code/RDGeneral/Exceptions.h
@@ -28,7 +28,7 @@ class RDKIT_RDGENERAL_EXPORT IndexErrorException : pub
 
   const char *what() const noexcept override { return _msg.c_str(); }
 
-  ~IndexErrorException() noexcept override = default;
+  ~IndexErrorException() noexcept override;
 
  private:
   int _idx;
@@ -45,7 +45,7 @@ class RDKIT_RDGENERAL_EXPORT ValueErrorException : pub
   ValueErrorException(const char *msg)
       : std::runtime_error("ValueErrorException"), _value(msg) {}
   const char *what() const noexcept override { return _value.c_str(); }
-  ~ValueErrorException() noexcept override = default;
+  ~ValueErrorException() noexcept override;
 
  private:
   std::string _value;
@@ -68,7 +68,7 @@ class RDKIT_RDGENERAL_EXPORT KeyErrorException : publi
 
   const char *what() const noexcept override { return _msg.c_str(); }
 
-  ~KeyErrorException() noexcept override = default;
+  ~KeyErrorException() noexcept override;
 
  private:
   std::string _key;
