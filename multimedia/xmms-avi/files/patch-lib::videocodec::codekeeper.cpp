--- lib/videocodec/codeckeeper.cpp.orig	Sun Feb  4 14:37:51 2001
+++ lib/videocodec/codeckeeper.cpp	Sun Dec  7 02:30:26 2003
@@ -253,20 +253,19 @@
     }	    
 }
 
-const CodecInfo* CodecInfo::match(int codec, const CodecInfo* start=0)
+const CodecInfo* CodecInfo::match(int codec, const CodecInfo* start)
 {
-    vector<CodecInfo>::const_iterator it;
-    if(start==0)
-	it=video_codecs.begin();
-    else
-	it=start;
-    vector<int>::const_iterator iv;
+    std::vector<CodecInfo>::const_iterator it = video_codecs.begin();
+    if (start)
+	it = std::vector<CodecInfo>::const_iterator(start);
+  
+    std::vector<int>::const_iterator iv;
     for(; it!=video_codecs.end(); it++)
     {
-	if(start && (it==start))continue;	
+	if(start && (&(*it)==start))continue;	
 	for(iv=it->fourcc_array.begin(); iv!=it->fourcc_array.end(); iv++)
 	    if(codec==(*iv))
-		return (const CodecInfo*)it;
+		return &(*it);
     }
     return 0;
 }
