--- include/avm_stl.h.orig	Fri Aug  6 12:35:41 2004
+++ include/avm_stl.h	Fri Aug  6 12:41:47 2004
@@ -74,6 +74,10 @@
 	m_Type = new Type[m_uiCapacity];
     }
     ~qring() { delete[] m_Type; }
+    qring<Type>(const qring<Type>& t) : m_Type(0)
+    {
+	operator=(t);
+    }
     qring<Type>& operator=(const qring<Type>& t)
     {
 	if (this != &t)
@@ -149,7 +153,6 @@
 
     // disabled for now
     qring<Type>() {}
-    qring<Type>(const qring<Type>& t) {}
 
     uint_t bpos() const { return (m_uiPos > 0) ? m_uiPos - 1 : m_uiCapacity - 1; }
     uint_t fpos() const { return (m_uiSize > m_uiPos) ? m_uiPos + m_uiCapacity - m_uiSize: m_uiPos - m_uiSize; }
@@ -167,9 +170,21 @@
     static const uint_t invalid=(uint_t)(~0);
     typedef Type* iterator;
     typedef const Type* const_iterator;
-    vector<Type>(int prealloc = 0);
+    vector<Type>()
+	:m_Type(0), m_uiCapacity(0), m_uiSize(0)
+    {
+    }
+
+    vector<Type>(int prealloc)
+	:m_Type(0), m_uiCapacity(prealloc), m_uiSize(prealloc)
+    {
+	if (m_uiCapacity > 0 )
+	    m_Type = new Type[m_uiCapacity];
+	//printf("vector %p   (%d)\n", this, m_uiSize);
+    }
+
     // we will not count references - we have to program with this in mind!
-    vector<Type>(const vector<Type>& t) :m_Type(0), m_uiCapacity(0), m_uiSize(0)
+    vector<Type>(const vector<Type>& t) :m_Type(0)
     {
 	operator=(t);
     }
@@ -270,15 +285,6 @@
     uint_t m_uiSize;
     void copy(const Type* in, uint_t size, uint_t alloc);
 };
-
-template <class Type>
-vector<Type>::vector<Type>(int prealloc)
-    :m_Type(0), m_uiCapacity(prealloc), m_uiSize(prealloc)
-{
-    if (m_uiCapacity > 0 )
-	m_Type = new Type[m_uiCapacity];
-    //printf("vector %p   (%d)\n", this, m_uiSize);
-}
 
 template <class Type>
 void vector<Type>::remove(const Type& t)
