--- src/objects.h.orig	2014-06-03 08:52:11 UTC
+++ src/objects.h
@@ -8824,8 +8824,8 @@ class Name: public HeapObject {
   STATIC_ASSERT(IS_POWER_OF_TWO(kMaxCachedArrayIndexLength + 1));
 
   static const unsigned int kContainsCachedArrayIndexMask =
-      (~kMaxCachedArrayIndexLength << ArrayIndexLengthBits::kShift) |
-      kIsNotArrayIndexMask;
+      (~static_cast<unsigned>(kMaxCachedArrayIndexLength)
+      << ArrayIndexLengthBits::kShift) | kIsNotArrayIndexMask;
 
   // Value of empty hash field indicating that the hash is not computed.
   static const int kEmptyHashField =
