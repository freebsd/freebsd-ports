--- src/lib/lib.cpp.orig
+++ src/lib/lib.cpp
@@ -496,9 +496,13 @@
 		entries[i].keystr=p;
 		len=strlen(p);
 		p+=len+1;
-		entries[i].off=g_ntohl(*reinterpret_cast<guint32 *>(p));
+        /*
+         * Can not use typecasting here, because *data does not have
+         * to be alligned and unalligned access fails on some architectures.
+         */
+		entries[i].off=((unsigned char)p[0] << 24) | ((unsigned char)p[1] << 16) | ((unsigned char)p[2] << 8) | (unsigned char)p[3];
 		p+=sizeof(guint32);
-		entries[i].size=g_ntohl(*reinterpret_cast<guint32 *>(p));
+		entries[i].size=((unsigned char)p[0] << 24) | ((unsigned char)p[1] << 16) | ((unsigned char)p[2] << 8) | (unsigned char)p[3];
 		p+=sizeof(guint32);
 	}
 }
@@ -513,7 +517,7 @@
 {
 	fseek(idxfile, wordoffset[page_idx], SEEK_SET);
 	guint32 page_size=wordoffset[page_idx+1]-wordoffset[page_idx];
-	fread(wordentry_buf, std::min(sizeof(wordentry_buf), page_size), 1, idxfile); //TODO: check returned values, deal with word entry that strlen>255.
+	fread(wordentry_buf, std::min(sizeof(wordentry_buf), (size_t)page_size), 1, idxfile); //TODO: check returned values, deal with word entry that strlen>255.
 	return wordentry_buf;
 }
 
