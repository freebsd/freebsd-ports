--- auxil/spicy/hilti/toolchain/include/compiler/printer.h.orig	2026-05-12 18:14:47 UTC
+++ auxil/spicy/hilti/toolchain/include/compiler/printer.h
@@ -59,7 +59,7 @@ class Stream { (public)
     Stream(std::ostream& s) : _stream(s) {}
 
     auto& state() const {
-        assert(detail::State::current);
+        assert(detail::State::current.get());
         return *detail::State::current;
     }
 
