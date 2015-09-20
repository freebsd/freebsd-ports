--- src/heap-snapshot-generator.cc.orig	2014-06-03 08:52:11 UTC
+++ src/heap-snapshot-generator.cc
@@ -410,8 +410,8 @@ bool HeapObjectsMap::MoveObject(Address 
     // object is migrated.
     if (FLAG_heap_profiler_trace_objects) {
       PrintF("Move object from %p to %p old size %6d new size %6d\n",
-             from,
-             to,
+             reinterpret_cast<void*>(from),
+             reinterpret_cast<void*>(to),
              entries_.at(from_entry_info_index).size,
              object_size);
     }
@@ -451,7 +451,7 @@ SnapshotObjectId HeapObjectsMap::FindOrA
     entry_info.accessed = accessed;
     if (FLAG_heap_profiler_trace_objects) {
       PrintF("Update object size : %p with old size %d and new size %d\n",
-             addr,
+             reinterpret_cast<void*>(addr),
              entry_info.size,
              size);
     }
@@ -486,9 +486,9 @@ void HeapObjectsMap::UpdateHeapObjectsMa
     FindOrAddEntry(obj->address(), obj->Size());
     if (FLAG_heap_profiler_trace_objects) {
       PrintF("Update object      : %p %6d. Next address is %p\n",
-             obj->address(),
+             reinterpret_cast<void*>(obj->address()),
              obj->Size(),
-             obj->address() + obj->Size());
+             reinterpret_cast<void*>(obj->address() + obj->Size()));
     }
   }
   RemoveDeadEntries();
@@ -516,20 +516,20 @@ struct HeapObjectInfo {
   void Print() const {
     if (expected_size == 0) {
       PrintF("Untracked object   : %p %6d. Next address is %p\n",
-             obj->address(),
+             reinterpret_cast<void*>(obj->address()),
              obj->Size(),
-             obj->address() + obj->Size());
+             reinterpret_cast<void*>(obj->address() + obj->Size()));
     } else if (obj->Size() != expected_size) {
       PrintF("Wrong size %6d: %p %6d. Next address is %p\n",
              expected_size,
-             obj->address(),
+             reinterpret_cast<void*>(obj->address()),
              obj->Size(),
-             obj->address() + obj->Size());
+             reinterpret_cast<void*>(obj->address() + obj->Size()));
     } else {
       PrintF("Good object      : %p %6d. Next address is %p\n",
-             obj->address(),
+             reinterpret_cast<void*>(obj->address()),
              expected_size,
-             obj->address() + obj->Size());
+             reinterpret_cast<void*>(obj->address() + obj->Size()));
     }
   }
 };
