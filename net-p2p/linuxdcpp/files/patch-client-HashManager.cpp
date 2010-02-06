--- client/HashManager.cpp.orig	2010-02-06 12:57:41.000000000 +0600
+++ client/HashManager.cpp	2010-02-06 12:58:04.000000000 +0600
@@ -636,13 +636,13 @@
 			currentSize = max(static_cast<uint64_t>(currentSize - size_read), static_cast<uint64_t>(0));
 		}
 
-		if(size_left <= 0) {
-			break;
-		}
-
 		munmap(buf, size_read);
 		pos += size_read;
 		size_left -= size_read;
+
+		if(size_left <= 0) {
+			break;
+		}
 	}
 	close(fd);
 	return true;
