Index: third_party/protobuf/src/google/protobuf/compiler/parser.cc
===================================================================
--- third_party/protobuf/src/google/protobuf/compiler/parser.cc	(revision 90205)
+++ third_party/protobuf/src/google/protobuf/compiler/parser.cc	(working copy)
@@ -82,8 +82,15 @@
   return result;
 }
 
-const TypeNameMap kTypeNames = MakeTypeNameTable();
+TypeNameMap type_names;
 
+const TypeNameMap& kTypeNames() {
+  if (type_names.empty()) {
+    type_names = MakeTypeNameTable();
+  }
+  return type_names;
+}
+
 }  // anonymous namespace
 
 // Makes code slightly more readable.  The meaning of "DO(foo)" is
@@ -1336,8 +1343,8 @@
 
 bool Parser::ParseType(FieldDescriptorProto::Type* type,
                        string* type_name) {
-  TypeNameMap::const_iterator iter = kTypeNames.find(input_->current().text);
-  if (iter != kTypeNames.end()) {
+  TypeNameMap::const_iterator iter = kTypeNames().find(input_->current().text);
+  if (iter != kTypeNames().end()) {
     *type = iter->second;
     input_->Next();
   } else {
@@ -1349,8 +1356,8 @@
 bool Parser::ParseUserDefinedType(string* type_name) {
   type_name->clear();
 
-  TypeNameMap::const_iterator iter = kTypeNames.find(input_->current().text);
-  if (iter != kTypeNames.end()) {
+  TypeNameMap::const_iterator iter = kTypeNames().find(input_->current().text);
+  if (iter != kTypeNames().end()) {
     // Note:  The only place enum types are allowed is for field types, but
     //   if we are parsing a field type then we would not get here because
     //   primitives are allowed there as well.  So this error message doesn't
