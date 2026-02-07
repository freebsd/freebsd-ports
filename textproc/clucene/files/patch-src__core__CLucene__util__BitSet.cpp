--- src/core/CLucene/util/BitSet.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/util/BitSet.cpp	2013-03-29 17:57:05.000000000 -0400
@@ -32,6 +32,25 @@
     3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
     4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};
 
+const uint8_t BitSet::BYTE_OFFSETS[256] = {
+    8, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
+    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
+    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
+    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
+    6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
+    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 
+    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 
+    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 
+    7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 
+    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 
+    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 
+    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 
+    6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 
+    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 
+    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 
+    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0};
+
+
 BitSet::BitSet( const BitSet& copy ) :
 	_size( copy._size ),
 	_count(-1)
@@ -180,19 +199,32 @@
     return                            factor * (4 + (8+40)*count()) < size();
   }
 
-  int32_t BitSet::nextSetBit(int32_t fromIndex) const {
+  int32_t BitSet::nextSetBit(int32_t fromIndex) const 
+  {
       if (fromIndex < 0)
           _CLTHROWT(CL_ERR_IndexOutOfBounds, _T("fromIndex < 0"));
 
       if (fromIndex >= _size)
           return -1;
 
-      while (true) {
-          if ((bits[fromIndex >> 3] & (1 << (fromIndex & 7))) != 0)
-              return fromIndex;
-          if (++fromIndex == _size)
-              return -1;
+      int _max = ( _size+7 ) >> 3;
+
+      unsigned int i = (int)( fromIndex>>3 );
+      unsigned int subIndex = fromIndex & 0x7; // index within the byte
+      uint8_t byte = bits[i] >> subIndex;  // skip all the bits to the right of index
+
+      if ( byte != 0 ) 
+      {
+          return ( ( i<<3 ) + subIndex + BYTE_OFFSETS[ byte ] );
+      }
+
+      while( ++i < _max ) 
+      {
+          byte = bits[i];
+          if ( byte != 0 ) 
+              return ( ( i<<3 ) + BYTE_OFFSETS[ byte ] );
       }
+      return -1;
   }
 
 CL_NS_END
