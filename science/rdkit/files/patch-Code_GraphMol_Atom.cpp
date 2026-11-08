-- Fix cross-DLL Boost.Python exception translation on FreeBSD.
-- Move exported exception-class destructors out-of-line so the Itanium ABI
-- emits a single typeinfo/vtable instance per class in its owning shared
-- library. Without this each shared module has its own local typeinfo copy
-- and catch-by-derived-type in Python exception translators fails.

--- Code/GraphMol/Atom.cpp.orig	2026-08-28 02:56:41 UTC
+++ Code/GraphMol/Atom.cpp
@@ -23,6 +23,12 @@ namespace RDKit {
 
 namespace RDKit {
 
+MolSanitizeException::~MolSanitizeException() noexcept = default;
+AtomSanitizeException::~AtomSanitizeException() noexcept = default;
+AtomValenceException::~AtomValenceException() noexcept = default;
+AtomKekulizeException::~AtomKekulizeException() noexcept = default;
+KekulizeException::~KekulizeException() noexcept = default;
+
 bool isAromaticAtom(const Atom &atom) {
   if (atom.getIsAromatic()) {
     return true;
