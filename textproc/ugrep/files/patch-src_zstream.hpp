--- src/zstream.hpp.orig	2024-11-29 20:51:51 UTC
+++ src/zstream.hpp
@@ -2626,7 +2626,7 @@ class zstreambuf : public std::streambuf {
         if (block_size > bz3file_->max ||
             bz3file_->len > bz3file_->max ||
             fread(bz3file_->buf, 1, block_size, file_) < block_size ||
-            bz3_decode_block(bz3file_->strm, bz3file_->buf, block_size, bz3file_->len) < 0)
+            bz3_decode_block(bz3file_->strm, bz3file_->buf, bz3file_->max, block_size, bz3file_->len) < 0)
         {
           if (ferror(file_))
             warning("cannot read", pathname_);
