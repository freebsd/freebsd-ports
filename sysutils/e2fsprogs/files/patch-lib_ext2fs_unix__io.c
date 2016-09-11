commit d6cad379eb6c86ca58bf5b83a586577de412a2e6
Author: Theodore Ts'o <tytso@mit.edu>
Date:   Sun Sep 11 00:25:48 2016 -0400

    libext2fs: fix unaligned, multiblock writes in the unix_io handler
    
    The read-modify-write code for the unaligned fallback code wasn't
    working for multi-block writes.  This was unmasked by FreeBSD 11-rc2,
    since its malloc() is returning unaligned memory regions for large
    memory regions.
    
    Signed-off-by: Theodore Ts'o <tytso@mit.edu>

--- lib/ext2fs/unix_io.c.orig	2016-09-02 04:17:32 UTC
+++ lib/ext2fs/unix_io.c
@@ -300,6 +300,7 @@ static errcode_t raw_write_blk(io_channe
 			goto short_write;
 		size -= actual;
 		buf += actual;
+		location += actual;
 	}
 	return 0;
 
