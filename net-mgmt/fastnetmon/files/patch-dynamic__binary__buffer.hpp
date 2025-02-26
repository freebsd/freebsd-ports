--- dynamic_binary_buffer.hpp.orig	2024-12-14 12:46:40 UTC
+++ dynamic_binary_buffer.hpp
@@ -8,9 +8,21 @@ class dynamic_binary_buffer_t {
         // std::cout << "Default constructor called" << std::endl;
     }
 
-    // Explicitly removed it as we need to implement it properly when needed
-    dynamic_binary_buffer_t(dynamic_binary_buffer_t&& that) = delete;
+    dynamic_binary_buffer_t(dynamic_binary_buffer_t&& source) noexcept {
+        // Just copy all field values from source and zeroify it
+        this->internal_data_shift = source.internal_data_shift;
+        source.internal_data_shift = 0;
 
+        this->byte_storage = source.byte_storage;
+        source.byte_storage = nullptr;
+
+        this->maximum_internal_storage_size = source.maximum_internal_storage_size;
+        source.maximum_internal_storage_size = 0;
+
+        this->errors_occured = source.errors_occured;
+        source.errors_occured = false;
+    }
+
     // We should set maximum buffer size here.
     // TODO: add ability to relocate memory of we need more memory
     bool set_maximum_buffer_size_in_bytes(ssize_t size) {
@@ -155,21 +167,21 @@ class dynamic_binary_buffer_t {
     }
 
     // Return full size (with non initialized data region too)
-    uint32_t get_full_size() {
+    uint32_t get_full_size() const {
         return maximum_internal_storage_size;
     }
 
     // Return only used memory region
-    size_t get_used_size() {
+    size_t get_used_size() const {
         return internal_data_shift;
     }
 
-    const uint8_t* get_pointer() {
+    const uint8_t* get_pointer() const {
         return byte_storage;
     }
 
     // If we have any issues with it
-    bool is_failed() {
+    bool is_failed() const {
         return errors_occured;
     }
 
@@ -180,3 +192,6 @@ class dynamic_binary_buffer_t {
     // If any errors occurred in any time when we used this buffer
     bool errors_occured = false;
 };
+
+static_assert(std::is_move_constructible_v<dynamic_binary_buffer_t>);
+static_assert(std::is_nothrow_move_constructible_v<dynamic_binary_buffer_t>);
