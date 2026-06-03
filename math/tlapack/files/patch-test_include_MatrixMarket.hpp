--- test/include/MatrixMarket.hpp.orig
+++ test/include/MatrixMarket.hpp
@@ -43,6 +43,8 @@
         state += s;
         operator()();
     }
+
+    using result_type = uint32_t;
 
     static constexpr uint32_t min() noexcept { return 0; }
     static constexpr uint32_t max() noexcept { return UINT32_MAX; }
