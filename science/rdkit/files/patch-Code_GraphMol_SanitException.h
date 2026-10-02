-- Fix cross-DLL Boost.Python exception translation on FreeBSD.
-- Move exported exception-class destructors out-of-line so the Itanium ABI
-- emits a single typeinfo/vtable instance per class in its owning shared
-- library. Without this each shared module has its own local typeinfo copy
-- and catch-by-derived-type in Python exception translators fails.

--- Code/GraphMol/SanitException.h.orig	2026-08-28 02:56:41 UTC
+++ Code/GraphMol/SanitException.h
@@ -32,7 +32,7 @@ class RDKIT_GRAPHMOL_EXPORT MolSanitizeException : pub
   MolSanitizeException(const MolSanitizeException &other)
       : d_msg(other.d_msg) {}
   const char *what() const noexcept override { return d_msg.c_str(); }
-  ~MolSanitizeException() noexcept override {}
+  ~MolSanitizeException() noexcept override;
   virtual MolSanitizeException *copy() const {
     return new MolSanitizeException(*this);
   }
@@ -52,7 +52,7 @@ class RDKIT_GRAPHMOL_EXPORT AtomSanitizeException
   AtomSanitizeException(const AtomSanitizeException &other)
       : MolSanitizeException(other), d_atomIdx(other.d_atomIdx) {}
   unsigned int getAtomIdx() const { return d_atomIdx; }
-  ~AtomSanitizeException() noexcept override {}
+  ~AtomSanitizeException() noexcept override;
   MolSanitizeException *copy() const override {
     return new AtomSanitizeException(*this);
   }
@@ -71,7 +71,7 @@ class RDKIT_GRAPHMOL_EXPORT AtomValenceException
       : AtomSanitizeException(msg, atomIdx) {}
   AtomValenceException(const AtomValenceException &other)
       : AtomSanitizeException(other) {}
-  ~AtomValenceException() noexcept override {}
+  ~AtomValenceException() noexcept override;
   MolSanitizeException *copy() const override {
     return new AtomValenceException(*this);
   }
@@ -87,7 +87,7 @@ class RDKIT_GRAPHMOL_EXPORT AtomKekulizeException
       : AtomSanitizeException(msg, atomIdx) {}
   AtomKekulizeException(const AtomKekulizeException &other)
       : AtomSanitizeException(other) {}
-  ~AtomKekulizeException() noexcept override {}
+  ~AtomKekulizeException() noexcept override;
   MolSanitizeException *copy() const override {
     return new AtomKekulizeException(*this);
   }
@@ -105,7 +105,7 @@ class RDKIT_GRAPHMOL_EXPORT KekulizeException : public
   const std::vector<unsigned int> &getAtomIndices() const {
     return d_atomIndices;
   }
-  ~KekulizeException() noexcept override {}
+  ~KekulizeException() noexcept override;
   MolSanitizeException *copy() const override {
     return new KekulizeException(*this);
   }
