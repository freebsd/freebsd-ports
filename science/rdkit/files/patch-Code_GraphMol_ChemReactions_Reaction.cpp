-- Fix cross-DLL Boost.Python exception translation on FreeBSD.
-- Move exported exception-class destructors out-of-line so the Itanium ABI
-- emits a single typeinfo/vtable instance per class in its owning shared
-- library. Without this each shared module has its own local typeinfo copy
-- and catch-by-derived-type in Python exception translators fails.

--- Code/GraphMol/ChemReactions/Reaction.cpp.orig	2026-08-28 02:56:41 UTC
+++ Code/GraphMol/ChemReactions/Reaction.cpp
@@ -33,6 +33,7 @@
 //
 
 #include <GraphMol/ChemReactions/Reaction.h>
+#include <GraphMol/ChemReactions/ReactionParser.h>
 #include <GraphMol/ChemReactions/ReactionPickler.h>
 #include <GraphMol/Substruct/SubstructMatch.h>
 #include <GraphMol/QueryOps.h>
@@ -45,6 +46,10 @@ namespace RDKit {
 #include "GraphMol/ChemReactions/ReactionRunner.h"
 
 namespace RDKit {
+
+ChemicalReactionException::~ChemicalReactionException() noexcept = default;
+ChemicalReactionParserException::~ChemicalReactionParserException() noexcept =
+    default;
 
 std::vector<MOL_SPTR_VECT> ChemicalReaction::runReactants(
     const MOL_SPTR_VECT reactants, unsigned int maxProducts) const {
