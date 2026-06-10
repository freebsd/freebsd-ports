--- auxil/spicy/spicy/toolchain/include/compiler/detail/codegen/productions/while.h.orig	2026-05-12 18:14:47 UTC
+++ auxil/spicy/spicy/toolchain/include/compiler/detail/codegen/productions/while.h
@@ -55,7 +55,7 @@ class While : public Production { (public)
      * loop body. This method must be called only after `preprocessLookAhead()`.
      */
     const production::LookAhead* lookAheadProduction() const {
-        assert(_body_for_grammar); // set by preprocessLookAhead() return
+        assert(_body_for_grammar.get()); // set by preprocessLookAhead() return
         return _body_for_grammar->as<production::LookAhead>();
     }
 
