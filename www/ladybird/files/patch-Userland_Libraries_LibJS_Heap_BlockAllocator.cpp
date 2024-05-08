mmap() with MAP_ANONYMOUS requires that -1 be passed for the fd argument.
See https://github.com/SerenityOS/serenity/issues/23375.

--- Userland/Libraries/LibJS/Heap/BlockAllocator.cpp.orig	2024-05-05 13:48:53 UTC
+++ Userland/Libraries/LibJS/Heap/BlockAllocator.cpp
@@ -57,7 +57,7 @@ void* BlockAllocator::allocate_block([[maybe_unused]] 
 #ifdef AK_OS_SERENITY
     auto* block = (HeapBlock*)serenity_mmap(nullptr, HeapBlock::block_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_RANDOMIZED | MAP_PRIVATE, 0, 0, HeapBlock::block_size, name);
 #else
-    auto* block = (HeapBlock*)mmap(nullptr, HeapBlock::block_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
+    auto* block = (HeapBlock*)mmap(nullptr, HeapBlock::block_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
 #endif
     VERIFY(block != MAP_FAILED);
     LSAN_REGISTER_ROOT_REGION(block, HeapBlock::block_size);
@@ -74,7 +74,7 @@ void BlockAllocator::deallocate_block(void* block)
         perror("munmap");
         VERIFY_NOT_REACHED();
     }
-    if (mmap(block, HeapBlock::block_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE | MAP_FIXED, 0, 0) != block) {
+    if (mmap(block, HeapBlock::block_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE | MAP_FIXED, -1, 0) != block) {
         perror("mmap");
         VERIFY_NOT_REACHED();
     }
