--- src/coroutine_ucontext.c.orig	2007-12-16 13:59:13.000000000 -0500
+++ src/coroutine_ucontext.c	2007-12-16 13:59:21.000000000 -0500
@@ -48,7 +48,7 @@ int coroutine_init(struct coroutine *co)
 	co->cc.stack_size = co->stack_size;
 	co->cc.stack = mmap(0, co->stack_size,
 			    PROT_READ | PROT_WRITE,
-			    MAP_PRIVATE | MAP_ANONYMOUS,
+			    MAP_PRIVATE | MAP_ANON,
 			    -1, 0);
 	if (co->cc.stack == MAP_FAILED)
 		return -1;
