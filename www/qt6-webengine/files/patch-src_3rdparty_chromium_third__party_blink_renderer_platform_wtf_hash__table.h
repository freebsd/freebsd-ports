--- src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/hash_table.h.orig	2024-06-10 11:34:19 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/hash_table.h
@@ -1646,7 +1646,7 @@ HashTable<Key, Value, Extractor, Traits, KeyTraits, Al
     }
   }
   table_ = temporary_table;
-  Allocator::template BackingWriteBarrier(&table_);
+  Allocator::template BackingWriteBarrier<>(&table_);
 
   HashTableBucketInitializer<Traits, Allocator, Value>::InitializeTable(
       original_table, new_table_size);
@@ -1700,7 +1700,7 @@ Value* HashTable<Key, Value, Extractor, Traits, KeyTra
   // This swaps the newly allocated buffer with the current one. The store to
   // the current table has to be atomic to prevent races with concurrent marker.
   AsAtomicPtr(&table_)->store(new_hash_table.table_, std::memory_order_relaxed);
-  Allocator::template BackingWriteBarrier(&table_);
+  Allocator::template BackingWriteBarrier<>(&table_);
   table_size_ = new_table_size;
 
   new_hash_table.table_ = old_table;
@@ -1852,8 +1852,8 @@ void HashTable<Key, Value, Extractor, Traits, KeyTrait
   // on the mutator thread, which is also the only one that writes to them, so
   // there is *no* risk of data races when reading.
   AtomicWriteSwap(table_, other.table_);
-  Allocator::template BackingWriteBarrier(&table_);
-  Allocator::template BackingWriteBarrier(&other.table_);
+  Allocator::template BackingWriteBarrier<>(&table_);
+  Allocator::template BackingWriteBarrier<>(&other.table_);
   if (IsWeak<ValueType>::value) {
     // Weak processing is omitted when no backing store is present. In case such
     // an empty table is later on used it needs to be strongified.
