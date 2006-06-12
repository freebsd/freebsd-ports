diff -r 05c2c6855f62 -r 48c00850eae6 lib/blkid/probe.h
--- a/lib/blkid/probe.h	Tue May 30 05:08:02 2006 +0200
+++ b/lib/blkid/probe.h	Tue May 30 14:42:47 2006 +0200
@@ -414,7 +414,7 @@ _INLINE_ __u64 blkid_swab64(__u64 val)
 
 
 
-#if  __BYTE_ORDER == __BIG_ENDIAN
+#ifdef WORDS_BIGENDIAN
 #define blkid_le16(x) blkid_swab16(x)
 #define blkid_le32(x) blkid_swab32(x)
 #define blkid_le64(x) blkid_swab64(x)
