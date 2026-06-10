--- auxil/spicy/hilti/toolchain/src/compiler/driver.cc.orig	2026-05-12 18:14:47 UTC
+++ auxil/spicy/hilti/toolchain/src/compiler/driver.cc
@@ -683,7 +683,7 @@ Result<Nothing> Driver::compileUnits() {
 }
 
 Result<Nothing> Driver::compileUnits() {
-    assert(_builder);
+    assert(_builder.get());
 
     if ( auto rc = context()->astContext()->processAST(_builder.get(), this); ! rc ) {
         // hilti::detail::printer::print(std::cerr, context()->astContext()->root());
@@ -723,7 +723,7 @@ Result<Nothing> Driver::run() {
 Result<Nothing> Driver::run() {
     assert(! _builder);
     initialize();
-    assert(_builder);
+    assert(_builder.get());
 
     for ( const auto& i : _driver_options.inputs ) {
         if ( auto rc = addInput(i); ! rc )
