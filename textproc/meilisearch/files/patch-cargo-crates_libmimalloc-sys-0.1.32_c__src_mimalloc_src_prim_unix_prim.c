--- cargo-crates/libmimalloc-sys-0.1.32/c_src/mimalloc/src/prim/unix/prim.c.orig	2023-06-07 23:03:09 UTC
+++ cargo-crates/libmimalloc-sys-0.1.32/c_src/mimalloc/src/prim/unix/prim.c
@@ -169,7 +169,7 @@ static void* unix_mmap_prim(void* addr, size_t size, s
       p = mmap(addr, size, protect_flags, flags | MAP_ALIGNED(n), fd, 0);
       if (p==MAP_FAILED || !_mi_is_aligned(p,try_alignment)) { 
         int err = errno;
-        _mi_warning_message("unable to directly request aligned OS memory (error: %d (0x%x), size: 0x%zx bytes, alignment: 0x%zx, hint address: %p)\n", err, err, size, try_alignment, hint);
+        _mi_warning_message("unable to directly request aligned OS memory (error: %d (0x%x), size: 0x%zx bytes, alignment: 0x%zx, hint address: %p)\n", err, err, size, try_alignment, addr);
       }
       if (p!=MAP_FAILED) return p;
       // fall back to regular mmap      
