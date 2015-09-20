--- src/objects.h.orig	2013-05-01 12:56:29 UTC
+++ src/objects.h
@@ -5573,7 +5573,7 @@ class Map: public HeapObject {
   static const int kElementsKindBitCount = 5;
 
   // Derived values from bit field 2
-  static const int kElementsKindMask = (-1 << kElementsKindShift) &
+  static const int kElementsKindMask = -(1 << kElementsKindShift) &
       ((1 << (kElementsKindShift + kElementsKindBitCount)) - 1);
   static const int8_t kMaximumBitField2FastElementValue = static_cast<int8_t>(
       (FAST_ELEMENTS + 1) << Map::kElementsKindShift) - 1;
@@ -7580,8 +7580,8 @@ class Name: public HeapObject {
   STATIC_CHECK(IS_POWER_OF_TWO(kMaxCachedArrayIndexLength + 1));
 
   static const int kContainsCachedArrayIndexMask =
-      (~kMaxCachedArrayIndexLength << kArrayIndexHashLengthShift) |
-      kIsNotArrayIndexMask;
+      (~static_cast<unsigned>(kMaxCachedArrayIndexLength) <<
+      kArrayIndexHashLengthShift) | kIsNotArrayIndexMask;
 
   // Value of empty hash field indicating that the hash is not computed.
   static const int kEmptyHashField =
