--- test/unit/filters/DelaunayFilterTest.cpp.orig	2019-05-10 22:11:49 UTC
+++ test/unit/filters/DelaunayFilterTest.cpp
@@ -92,7 +92,7 @@ TEST(DelaunayFilterTest, test1)
         
         // Build a vector so we can compare to an expected triangle with
         // the == operator.
-        std::vector<size_t> triangleVector = {triangle.m_a, triangle.m_b, triangle.m_c};
+        std::vector<size_t> triangleVector = {static_cast<unsigned int>(triangle.m_a), static_cast<unsigned int>(triangle.m_b), static_cast<unsigned int>(triangle.m_c)};
         
         // Go through all of the expected triangles to check for a
         // match.
