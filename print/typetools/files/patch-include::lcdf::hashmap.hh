--- include/lcdf/hashmap.hh.orig	Fri Aug 15 08:11:23 2003
+++ include/lcdf/hashmap.hh	Sun Aug 22 21:10:02 2004
@@ -109,6 +109,8 @@
     V &value() const			{ return _hm->_e[_pos].value; }
 
   private:
+    const HashMap<K, V> *_hm;
+    int _pos;
     _HashMap_iterator(const HashMap<K, V> *hm, int pos) : _HashMap_const_iterator<K, V>(hm, pos) { }
     friend class HashMap<K, V>;
 };
