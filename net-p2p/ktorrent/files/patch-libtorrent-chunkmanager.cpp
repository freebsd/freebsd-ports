--- libtorrent/chunkmanager.cpp.orig	Mon Oct 10 20:06:38 2005
+++ libtorrent/chunkmanager.cpp	Mon Oct 10 20:10:53 2005
@@ -315,8 +315,11 @@
 
 	void ChunkManager::prioritise(Uint32 from,Uint32 to)
 	{
-		if (from > to)
-			std::swap(from,to);
+		if (from > to) {
+			Uint32 tmp = from;
+			from = to;
+			to = tmp;
+		}
 
 		Uint32 i = from;
 		while (i <= to && i < chunks.count())
@@ -329,8 +332,11 @@
 
 	void ChunkManager::exclude(Uint32 from,Uint32 to)
 	{
-		if (from > to)
-			std::swap(from,to);
+		if (from > to) {
+			Uint32 tmp = from;
+			from = to;
+			to = tmp;
+		}
 
 		Uint32 i = from;
 		while (i <= to && i < chunks.count())
@@ -347,8 +353,11 @@
 
 	void ChunkManager::include(Uint32 from,Uint32 to)
 	{
-		if (from > to)
-			std::swap(from,to);
+		if (from > to) {
+			Uint32 tmp = from;
+			from = to;
+			to = tmp;
+		}
 
 		Uint32 i = from;
 		while (i <= to && i < chunks.count())
