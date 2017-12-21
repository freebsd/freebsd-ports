--- src/LDHT/TableChunkLocator.h.orig	2017-03-07 01:06:04 UTC
+++ src/LDHT/TableChunkLocator.h
@@ -21,7 +21,7 @@ public:
                          int num_cells,
                          int num_chunks) = 0;
     virtual int locateTableChunkForKey(uint64_t key) = 0;
-
+	virtual ~TableChunkLocator(){};
 };
 
 }  // namespace LDHT.
