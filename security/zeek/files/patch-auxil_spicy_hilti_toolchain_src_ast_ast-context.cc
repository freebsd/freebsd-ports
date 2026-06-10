--- auxil/spicy/hilti/toolchain/src/ast/ast-context.cc.orig	2026-05-12 18:14:47 UTC
+++ auxil/spicy/hilti/toolchain/src/ast/ast-context.cc
@@ -328,7 +328,7 @@ void ASTContext::garbageCollect() {
         changed = false;
 
         for ( auto& n : _nodes ) {
-            assert(n);
+            assert(n.get());
 
             if ( n->isRetained() ) {
                 ++retained;
