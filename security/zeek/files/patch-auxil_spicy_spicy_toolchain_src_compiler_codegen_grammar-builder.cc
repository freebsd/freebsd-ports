--- auxil/spicy/spicy/toolchain/src/compiler/codegen/grammar-builder.cc.orig	2026-05-12 18:14:47 UTC
+++ auxil/spicy/spicy/toolchain/src/compiler/codegen/grammar-builder.cc
@@ -354,7 +354,7 @@ hilti::Result<hilti::Nothing> GrammarBuilder::run(type
     Grammar g(id.str(), unit->location());
     auto pf = ProductionFactory(cg(), this, &g);
     auto root = pf.createProduction(unit);
-    assert(root);
+    assert(root.get());
 
     if ( auto rc = g.setRoot(std::move(root)); ! rc )
         return rc.error();
