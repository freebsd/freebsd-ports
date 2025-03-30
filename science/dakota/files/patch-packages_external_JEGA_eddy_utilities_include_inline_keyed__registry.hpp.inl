- https://github.com/snl-dakota/dakota/issues/178

--- packages/external/JEGA/eddy/utilities/include/inline/keyed_registry.hpp.inl.orig	2025-03-28 21:44:35 UTC
+++ packages/external/JEGA/eddy/utilities/include/inline/keyed_registry.hpp.inl
@@ -153,18 +153,6 @@ template<typename KeyType, typename ValueType>
 }
 
 template<typename KeyType, typename ValueType>
-bool
-keyed_registry<KeyType, ValueType>::unregister(
-    const KeyType& value
-    )
-{
-    typename container::iterator it(this->find(this->key));
-    if(it == this->_registry.end()) return false;
-    this->_registry.erase(it);
-    return true;
-}
-
-template<typename KeyType, typename ValueType>
 typename keyed_registry<KeyType, ValueType>::const_iterator
 keyed_registry<KeyType, ValueType>::find(
     const KeyType& key
