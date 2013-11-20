--- src/coroutine_ucontext.c.orig	2011-02-18 16:29:10.000000000 +0000
+++ src/coroutine_ucontext.c	2011-02-20 17:51:14.000000000 +0000
@@ -60,7 +60,7 @@ int coroutine_init(struct coroutine *co)
 	co->cc.stack_size = co->stack_size;
 	co->cc.stack = mmap(0, co->stack_size,
 			    PROT_READ | PROT_WRITE,
-			    MAP_PRIVATE | MAP_ANONYMOUS,
+			    MAP_PRIVATE | MAP_ANON,
 			    -1, 0);
 	if (co->cc.stack == MAP_FAILED)
 		return -1;
