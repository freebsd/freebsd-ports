diff --git src/common/bit_vector.hpp src/common/bit_vector.hpp
index 832e75fe6a..73ae6d9e07 100644
--- src/common/bit_vector.hpp
+++ src/common/bit_vector.hpp
@@ -224,6 +224,7 @@ public:
   static void generate_test_instances(std::list<BitVector *> &o);
 private:
   struct NoInitAllocator : public std::allocator<__u32> {
+    NoInitAllocator() {};
     NoInitAllocator(const std::allocator<__u32>& alloc)
       : std::allocator<__u32>(alloc) {
     }

