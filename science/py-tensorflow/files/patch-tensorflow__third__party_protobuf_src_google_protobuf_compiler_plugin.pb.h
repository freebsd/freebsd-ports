--- tensorflow_third_party/protobuf/src/google/protobuf/compiler/plugin.pb.h.orig	2017-06-12 12:45:01 UTC
+++ tensorflow_third_party/protobuf/src/google/protobuf/compiler/plugin.pb.h
@@ -235,14 +235,14 @@ class LIBPROTOC_EXPORT Version : public 
   bool has_major() const;
   void clear_major();
   static const int kMajorFieldNumber = 1;
-  ::google::protobuf::int32 major() const;
+  ::google::protobuf::int32 _major() const;
   void set_major(::google::protobuf::int32 value);
 
   // optional int32 minor = 2;
   bool has_minor() const;
   void clear_minor();
   static const int kMinorFieldNumber = 2;
-  ::google::protobuf::int32 minor() const;
+  ::google::protobuf::int32 _minor() const;
   void set_minor(::google::protobuf::int32 value);
 
   // optional int32 patch = 3;
@@ -702,7 +702,7 @@ inline void Version::clear_major() {
   major_ = 0;
   clear_has_major();
 }
-inline ::google::protobuf::int32 Version::major() const {
+inline ::google::protobuf::int32 Version::_major() const {
   // @@protoc_insertion_point(field_get:google.protobuf.compiler.Version.major)
   return major_;
 }
@@ -726,7 +726,7 @@ inline void Version::clear_minor() {
   minor_ = 0;
   clear_has_minor();
 }
-inline ::google::protobuf::int32 Version::minor() const {
+inline ::google::protobuf::int32 Version::_minor() const {
   // @@protoc_insertion_point(field_get:google.protobuf.compiler.Version.minor)
   return minor_;
 }
