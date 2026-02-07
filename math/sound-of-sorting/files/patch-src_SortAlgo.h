--- src/SortAlgo.h.orig	2017-12-23 08:39:32 UTC
+++ src/SortAlgo.h
@@ -164,22 +164,22 @@ class MyIterator : public std::iterator<std::random_ac
     reference operator[](const difference_type& n) const
     { return m_array->get_mutable(m_pos + n); }
 
-    bool operator==(const MyIterator& r)
+    bool operator==(const MyIterator& r) const
     { return (m_array == r.m_array) && (m_pos == r.m_pos); }
 
-    bool operator!=(const MyIterator& r)
+    bool operator!=(const MyIterator& r) const
     { return (m_array != r.m_array) || (m_pos != r.m_pos); }
 
-    bool operator<(const MyIterator& r)
+    bool operator<(const MyIterator& r) const
     { return (m_array == r.m_array ? (m_pos < r.m_pos) : (m_array < r.m_array)); }
 
-    bool operator>(const MyIterator& r)
+    bool operator>(const MyIterator& r) const
     { return (m_array == r.m_array ? (m_pos > r.m_pos) : (m_array > r.m_array)); }
 
-    bool operator<=(const MyIterator& r)
+    bool operator<=(const MyIterator& r) const
     { return (m_array == r.m_array ? (m_pos <= r.m_pos) : (m_array <= r.m_array)); }
 
-    bool operator>=(const MyIterator& r)
+    bool operator>=(const MyIterator& r) const
     { return (m_array == r.m_array ? (m_pos >= r.m_pos) : (m_array >= r.m_array)); }
 
     difference_type operator+(const MyIterator& r2) const
