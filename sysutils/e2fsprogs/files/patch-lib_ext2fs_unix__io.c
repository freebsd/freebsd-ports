--- lib/ext2fs/unix_io.c.orig	2016-09-02 04:17:32 UTC
+++ lib/ext2fs/unix_io.c
@@ -188,16 +188,24 @@ static errcode_t raw_read_blk(io_channel
 	 * The buffer or size which we're trying to read isn't aligned
 	 * to the O_DIRECT rules, so we need to do this the hard way...
 	 */
-	while (size > 0) {
-		actual = read(data->dev, data->bounce, channel->block_size);
-		if (actual != channel->block_size)
-			goto short_read;
-		actual = size;
-		if (size > channel->block_size)
-			actual = channel->block_size;
-		memcpy(buf, data->bounce, actual);
-		size -= actual;
-		buf += actual;
+	{
+		ssize_t really_read = 0;
+		while (size > 0) {
+			actual = read(data->dev, data->bounce, channel->block_size);
+			if (actual != channel->block_size) {
+				actual = really_read;
+				buf -= really_read;
+				size += really_read;
+				goto short_read;
+			}
+			actual = size;
+			if (size > channel->block_size)
+				actual = channel->block_size;
+			memcpy(buf, data->bounce, actual);
+			really_read += actual;
+			size -= actual;
+			buf += actual;
+		}
 	}
 	return 0;
 
@@ -283,8 +291,12 @@ static errcode_t raw_write_blk(io_channe
 			actual = read(data->dev, data->bounce,
 				      channel->block_size);
 			if (actual != channel->block_size) {
-				retval = EXT2_ET_SHORT_READ;
-				goto error_out;
+				if (actual >= 0) {
+					memset(data->bounce + actual, 0, channel->block_size - actual);
+				} else {
+					retval = EXT2_ET_SHORT_READ;
+					goto error_out;
+				}
 			}
 		}
 		actual = size;
@@ -300,6 +312,7 @@ static errcode_t raw_write_blk(io_channe
 			goto short_write;
 		size -= actual;
 		buf += actual;
+		location += actual;
 	}
 	return 0;
 
