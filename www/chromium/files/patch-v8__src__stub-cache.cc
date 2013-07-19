--- v8/src/stub-cache.cc	2013-07-03 23:56:49.000000000 -0400
+++ v8/src/stub-cache.cc	2013-07-19 00:35:10.000000000 -0400
@@ -1476,7 +1476,7 @@
                                             Handle<Name> name) {
   return (FLAG_print_code_stubs && !name.is_null() && name->IsString())
       ? GetCodeWithFlags(flags, *Handle<String>::cast(name)->ToCString())
-      : GetCodeWithFlags(flags, reinterpret_cast<char*>(NULL));
+      : GetCodeWithFlags(flags, static_cast<char*>(0));
 }
 
 
