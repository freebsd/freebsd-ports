-- Fix cross-DLL Boost.Python exception translation on FreeBSD.
-- Move exported exception-class destructors out-of-line so the Itanium ABI
-- emits a single typeinfo/vtable instance per class in its owning shared
-- library. Without this each shared module has its own local typeinfo copy
-- and catch-by-derived-type in Python exception translators fails.

--- Code/GraphMol/Conformer.cpp.orig	2026-08-28 02:56:41 UTC
+++ Code/GraphMol/Conformer.cpp
@@ -12,6 +12,8 @@ namespace RDKit {
 
 namespace RDKit {
 
+ConformerException::~ConformerException() noexcept = default;
+
 void Conformer::setOwningMol(ROMol *mol) {
   PRECONDITION(mol, "");
   dp_mol = mol;
