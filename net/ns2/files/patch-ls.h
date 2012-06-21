--- linkstate/ls.h.org	2012-06-04 21:45:22.000000000 +0900
+++ linkstate/ls.h	2012-06-04 21:45:44.000000000 +0900
@@ -134,7 +134,7 @@
 		return ib.second ? ib.first : baseMap::end();
 	}
 
-	void eraseAll() { erase(baseMap::begin(), baseMap::end()); }
+	void eraseAll() { baseMap::erase(baseMap::begin(), baseMap::end()); }
 	T* findPtr(Key key) {
 		iterator it = baseMap::find(key);
 		return (it == baseMap::end()) ? (T *)NULL : &((*it).second);
