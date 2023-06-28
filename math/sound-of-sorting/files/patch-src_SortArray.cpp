--- src/SortArray.cpp.orig	2017-12-23 08:39:32 UTC
+++ src/SortArray.cpp
@@ -25,6 +25,7 @@
 #include "SortAlgo.h"
 
 #include <algorithm>
+#include <random>
 
 extern void SoundAccess(size_t i);
 
@@ -123,7 +124,9 @@ void SortArray::FillData(unsigned int schema, size_t a
         for (size_t i = 0; i < m_array.size(); ++i)
             m_array[i] = ArrayItem(i+1);
 
-        std::random_shuffle(m_array.begin(), m_array.end());
+        std::random_device rng;
+        std::mt19937 urng(rng());
+        std::shuffle(m_array.begin(), m_array.end(), urng);
     }
     else if (schema == 1) // Ascending [1,n]
     {
@@ -150,7 +153,9 @@ void SortArray::FillData(unsigned int schema, size_t a
             m_array[i] = ArrayItem(w + 1);
         }
 
-        std::random_shuffle(m_array.begin(), m_array.end());
+        std::random_device rng;
+        std::mt19937 urng(rng());
+        std::shuffle(m_array.begin(), m_array.end(), urng);
     }
     else if (schema == 4) // Quintic skew of [1,n]
     {
@@ -167,7 +172,9 @@ void SortArray::FillData(unsigned int schema, size_t a
             m_array[i] = ArrayItem(w + 1);
         }
 
-        std::random_shuffle(m_array.begin(), m_array.end());
+        std::random_device rng;
+        std::mt19937 urng(rng());
+        std::shuffle(m_array.begin(), m_array.end(), urng);
     }
     else if (schema == 5) // shuffled n-2 equal values in [1,n]
     {
@@ -178,7 +185,9 @@ void SortArray::FillData(unsigned int schema, size_t a
         }
         m_array[m_array.size()-1] = ArrayItem(arraysize);
 
-        std::random_shuffle(m_array.begin(), m_array.end());
+        std::random_device rng;
+        std::mt19937 urng(rng());
+        std::shuffle(m_array.begin(), m_array.end(), urng);
     }
     else // fallback
     {
