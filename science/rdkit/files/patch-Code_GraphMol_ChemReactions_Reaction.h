-- Fix cross-DLL Boost.Python exception translation on FreeBSD.
-- Move exported exception-class destructors out-of-line so the Itanium ABI
-- emits a single typeinfo/vtable instance per class in its owning shared
-- library. Without this each shared module has its own local typeinfo copy
-- and catch-by-derived-type in Python exception translators fails.

--- Code/GraphMol/ChemReactions/Reaction.h.orig	2026-08-28 02:56:41 UTC
+++ Code/GraphMol/ChemReactions/Reaction.h
@@ -55,7 +55,7 @@ class RDKIT_CHEMREACTIONS_EXPORT ChemicalReactionExcep
   explicit ChemicalReactionException(const std::string msg) : _msg(msg) {}
   //! get the error message
   const char *what() const noexcept override { return _msg.c_str(); }
-  ~ChemicalReactionException() noexcept override = default;
+  ~ChemicalReactionException() noexcept override;
 
  private:
   std::string _msg;
