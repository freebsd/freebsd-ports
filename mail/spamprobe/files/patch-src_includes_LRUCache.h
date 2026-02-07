--- src/includes/LRUCache.h.orig	2018-08-14 08:00:27 UTC
+++ src/includes/LRUCache.h
@@ -60,7 +60,7 @@ template<class KeyType, class ValueType> class LRUCach
   {
   public:
     bool operator()(const NodeType *a,
-                    const NodeType *b)
+                    const NodeType *b) const
     {
       return a->key < b->key;
     }
