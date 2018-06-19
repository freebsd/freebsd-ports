--- src/stub-cache.cc.orig	2013-05-01 12:56:29 UTC
+++ src/stub-cache.cc
@@ -1474,7 +1474,7 @@ Handle<Code> StubCompiler::GetCodeWithFl
                                             Handle<Name> name) {
   return (FLAG_print_code_stubs && !name.is_null() && name->IsString())
       ? GetCodeWithFlags(flags, *Handle<String>::cast(name)->ToCString())
-      : GetCodeWithFlags(flags, reinterpret_cast<char*>(NULL));
+      : GetCodeWithFlags(flags, static_cast<char*>(NULL));
 }
 
 
