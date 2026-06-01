-- Replace deprecated std::allocator::construct/destroy (removed in C++20) with
-- placement new and explicit destructor calls. These are compatible with C++11
-- through C++26 and fix compilation of C++20 consumers of LEMON (e.g. OpenROAD).

--- lemon/bits/array_map.h.orig
+++ lemon/bits/array_map.h
@@ -88,7 +88,7 @@
       Item it;
       for (nf->first(it); it != INVALID; nf->next(it)) {
         int id = nf->id(it);;
-        allocator.construct(&(values[id]), Value());
+        ::new(static_cast<void*>(&(values[id]))) Value();
       }
     }
 
@@ -102,7 +102,7 @@
       Item it;
       for (nf->first(it); it != INVALID; nf->next(it)) {
         int id = nf->id(it);;
-        allocator.construct(&(values[id]), value);
+        ::new(static_cast<void*>(&(values[id]))) Value(value);
       }
     }
 
@@ -121,7 +121,7 @@
       Item it;
       for (nf->first(it); it != INVALID; nf->next(it)) {
         int id = nf->id(it);;
-        allocator.construct(&(values[id]), copy.values[id]);
+        ::new(static_cast<void*>(&(values[id]))) Value(copy.values[id]);
       }
     }
 
@@ -218,15 +218,15 @@
         for (nf->first(it); it != INVALID; nf->next(it)) {
           int jd = nf->id(it);;
           if (id != jd) {
-            allocator.construct(&(new_values[jd]), values[jd]);
-            allocator.destroy(&(values[jd]));
+            ::new(static_cast<void*>(&(new_values[jd]))) Value(values[jd]);
+            values[jd].~Value();
           }
         }
         if (capacity != 0) allocator.deallocate(values, capacity);
         values = new_values;
         capacity = new_capacity;
       }
-      allocator.construct(&(values[id]), Value());
+      ::new(static_cast<void*>(&(values[id]))) Value();
     }
 
     // \brief Adds more new keys to the map.
@@ -260,8 +260,8 @@
             }
           }
           if (found) continue;
-          allocator.construct(&(new_values[id]), values[id]);
-          allocator.destroy(&(values[id]));
+          ::new(static_cast<void*>(&(new_values[id]))) Value(values[id]);
+          values[id].~Value();
         }
         if (capacity != 0) allocator.deallocate(values, capacity);
         values = new_values;
@@ -269,7 +269,7 @@
       }
       for (int i = 0; i < int(keys.size()); ++i) {
         int id = nf->id(keys[i]);
-        allocator.construct(&(values[id]), Value());
+        ::new(static_cast<void*>(&(values[id]))) Value();
       }
     }
 
@@ -279,7 +279,7 @@
     // and it overrides the erase() member function of the observer base.
     virtual void erase(const Key& key) {
       int id = Parent::notifier()->id(key);
-      allocator.destroy(&(values[id]));
+      values[id].~Value();
     }
 
     // \brief Erase more keys from the map.
@@ -289,7 +289,7 @@
     virtual void erase(const std::vector<Key>& keys) {
       for (int i = 0; i < int(keys.size()); ++i) {
         int id = Parent::notifier()->id(keys[i]);
-        allocator.destroy(&(values[id]));
+        values[id].~Value();
       }
     }
 
@@ -303,7 +303,7 @@
       Item it;
       for (nf->first(it); it != INVALID; nf->next(it)) {
         int id = nf->id(it);;
-        allocator.construct(&(values[id]), Value());
+        ::new(static_cast<void*>(&(values[id]))) Value();
       }
     }
 
@@ -317,7 +317,7 @@
         Item it;
         for (nf->first(it); it != INVALID; nf->next(it)) {
           int id = nf->id(it);
-          allocator.destroy(&(values[id]));
+          values[id].~Value();
         }
         allocator.deallocate(values, capacity);
         capacity = 0;
