--- src/core/CLucene/util/BitSet.h.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/util/BitSet.h	2013-03-29 17:57:05.000000000 -0400
@@ -39,6 +39,7 @@
   /** Indicates if the bit vector is sparse and should be saved as a d-gaps list, or dense, and should be saved as a bit set. */
   bool isSparse();
   static const uint8_t BYTE_COUNTS[256];
+  static const uint8_t BYTE_OFFSETS[256];
 protected:
 	BitSet( const BitSet& copy );
 
