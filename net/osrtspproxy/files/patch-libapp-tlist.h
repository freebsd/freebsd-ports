--- libapp/tlist.h.orig	Mon Sep 20 15:00:01 2004
+++ libapp/tlist.h	Mon Sep 20 15:00:36 2004
@@ -94,7 +94,7 @@
         T& operator*( void )
         {
             assert( m_pList && m_pNode );
-            return m_pNode->GetData();
+            return this->m_pNode->GetData();
         }
     protected:
         Iterator( TSingleList<T>* pList, TSingleNode* pNode ) :
@@ -114,7 +114,7 @@
         const T& operator*( void ) const
         {
             assert( m_pList && m_pNode );
-            return m_pNode->GetData();
+            return this->m_pNode->GetData();
         }
     protected:
         ConstIterator( const TSingleList<T>* pList, TSingleNode* pNode ) :
@@ -282,7 +282,7 @@
         T& operator*( void )
         {
             assert( m_pList && m_pNode );
-            return m_pNode->GetData();
+            return this->m_pNode->GetData();
         }
     protected:
         Iterator( const TDoubleList<T>* pList, TDoubleNode* pNode ) :
@@ -302,7 +302,7 @@
         const T& operator*( void ) const
         {
             assert( m_pList && m_pNode );
-            return m_pNode->GetData();
+            return this->m_pNode->GetData();
         }
     protected:
         ConstIterator( const TDoubleList<T>* pList, TDoubleNode* pNode ) :
