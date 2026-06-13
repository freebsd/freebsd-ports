--- test/gtest/ucs/test_algorithm.cc.orig	2026-05-10 22:50:36 UTC
+++ test/gtest/ucs/test_algorithm.cc
@@ -41,9 +41,9 @@ UCS_TEST_F(test_algorithm, qsort_r) {
         }
 
         std::vector<int> vec2 = vec;
-        qsort(&vec2[0], nmemb, sizeof(int), compare_func);
+        qsort(vec2.data(), nmemb, sizeof(int), compare_func);
 
-        ucs_qsort_r(&vec[0], nmemb, sizeof(int), compare_func_r, MAGIC);
+        ucs_qsort_r(vec.data(), nmemb, sizeof(int), compare_func_r, MAGIC);
         ASSERT_EQ(vec2, vec);
     }
 }
