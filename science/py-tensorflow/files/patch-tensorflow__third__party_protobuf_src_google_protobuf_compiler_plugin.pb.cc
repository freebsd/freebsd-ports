--- tensorflow_third_party/protobuf/src/google/protobuf/compiler/plugin.pb.cc.orig	2017-06-12 12:45:01 UTC
+++ tensorflow_third_party/protobuf/src/google/protobuf/compiler/plugin.pb.cc
@@ -370,12 +370,12 @@ void Version::SerializeWithCachedSizes(
   // @@protoc_insertion_point(serialize_start:google.protobuf.compiler.Version)
   // optional int32 major = 1;
   if (has_major()) {
-    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->major(), output);
+    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->_major(), output);
   }
 
   // optional int32 minor = 2;
   if (has_minor()) {
-    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->minor(), output);
+    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->_minor(), output);
   }
 
   // optional int32 patch = 3;
@@ -406,12 +406,12 @@ void Version::SerializeWithCachedSizes(
   // @@protoc_insertion_point(serialize_to_array_start:google.protobuf.compiler.Version)
   // optional int32 major = 1;
   if (has_major()) {
-    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->major(), target);
+    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->_major(), target);
   }
 
   // optional int32 minor = 2;
   if (has_minor()) {
-    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->minor(), target);
+    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->_minor(), target);
   }
 
   // optional int32 patch = 3;
@@ -459,14 +459,14 @@ size_t Version::ByteSizeLong() const {
     if (has_major()) {
       total_size += 1 +
         ::google::protobuf::internal::WireFormatLite::Int32Size(
-          this->major());
+          this->_major());
     }
 
     // optional int32 minor = 2;
     if (has_minor()) {
       total_size += 1 +
         ::google::protobuf::internal::WireFormatLite::Int32Size(
-          this->minor());
+          this->_minor());
     }
 
     // optional int32 patch = 3;
@@ -509,10 +509,10 @@ void Version::MergeFrom(const Version& f
       suffix_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.suffix_);
     }
     if (from.has_major()) {
-      set_major(from.major());
+      set_major(from._major());
     }
     if (from.has_minor()) {
-      set_minor(from.minor());
+      set_minor(from._minor());
     }
     if (from.has_patch()) {
       set_patch(from.patch());
@@ -574,7 +574,7 @@ void Version::clear_major() {
   major_ = 0;
   clear_has_major();
 }
-::google::protobuf::int32 Version::major() const {
+::google::protobuf::int32 Version::_major() const {
   // @@protoc_insertion_point(field_get:google.protobuf.compiler.Version.major)
   return major_;
 }
@@ -598,7 +598,7 @@ void Version::clear_minor() {
   minor_ = 0;
   clear_has_minor();
 }
-::google::protobuf::int32 Version::minor() const {
+::google::protobuf::int32 Version::_minor() const {
   // @@protoc_insertion_point(field_get:google.protobuf.compiler.Version.minor)
   return minor_;
 }
