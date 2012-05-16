--- GG/adobe/closed_hash.hpp.orig	2009-04-30 23:51:53.000000000 +0400
+++ GG/adobe/closed_hash.hpp	2012-01-27 19:00:48.000000000 +0300
@@ -448,7 +448,7 @@
     
     template <typename I> // I models ForwardIterator
     void move_insert(I first, I last)
-    { while (first != last) { insert(move(*first)); ++first; } }
+  { while (first != last) { insert(::adobe::move(*first)); ++first; } }
     
     /*
         NOTE (sparent): If there is not enough space for one element we will reserve the space
@@ -480,12 +480,12 @@
             {
             iterator found = find(node, key_function()(x));
             if (found != end()) {
-                *found = move(x);
+              *found = ::adobe::move(x);
                 return std::make_pair(found, false);
             }
             
             iterator free(begin_free());
-            insert_raw(free, move(x), state_misplaced);
+            insert_raw(free, ::adobe::move(x), state_misplaced);
             unsafe::splice_node_range(node, free, free);
             node = free;
             }
@@ -493,7 +493,7 @@
         case state_misplaced:
             {
             iterator free(begin_free());
-            insert_raw(free, move(*node), state_misplaced);
+            insert_raw(free, ::adobe::move(*node), state_misplaced);
             
             unsafe::set_next(boost::prior(node), free);
             unsafe::set_next(free, boost::next(node));
@@ -503,7 +503,7 @@
             // fall through
         default: // state_free
             {
-            insert_raw(node, move(x), state_home);
+            insert_raw(node, ::adobe::move(x), state_home);
             unsafe::splice_node_range(end(), node, node);
             }
         }
