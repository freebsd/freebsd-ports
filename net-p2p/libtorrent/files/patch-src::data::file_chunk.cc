--- src/data/file_chunk.cc.orig	Mon Jan 17 21:31:30 2005
+++ src/data/file_chunk.cc	Mon Jan 17 21:32:21 2005
@@ -6,6 +6,7 @@
 #include <sstream>
 #include <unistd.h>
 #include <sys/mman.h>
+#include <sys/types.h>
 
 namespace torrent {
 
@@ -32,7 +33,7 @@
     std::stringstream s;
 
     s << "Tried to check incore status in FileChunk with out of range parameters or a NULL buffer ("
-      << std::hex << '(' << (unsigned int)m_begin << ',' << (unsigned int)m_end << ')';
+      << std::hex << '(' << m_begin << ',' << m_end << ')';
 
     throw internal_error(s.str());
   }
@@ -63,7 +64,7 @@
     std::stringstream s;
 
     s << "Tried to advise FileChunk with out of range parameters"
-      << std::hex << '(' << (unsigned int)m_begin << ',' << (unsigned int)m_end << ',' << offset << ',' << len << ')';
+      << std::hex << '(' << m_begin << ',' << m_end << ',' << offset << ',' << len << ')';
 
     throw internal_error(s.str());
   }
