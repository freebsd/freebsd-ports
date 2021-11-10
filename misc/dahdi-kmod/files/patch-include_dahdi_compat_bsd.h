--- freebsd/include/dahdi/compat/bsd.h.orig	2010-09-02 09:16:05 UTC
+++ freebsd/include/dahdi/compat/bsd.h
@@ -218,7 +218,7 @@ typedef struct sx rwlock_t;
 #define DEFINE_RWLOCK(name)				\
 	struct sx name;					\
 	SX_SYSINIT(name, &name, #name)
-#define rwlock_init(rwlock)	sx_init_flags(rwlock, "DAHDI rwlock", SX_NOADAPTIVE)
+#define rwlock_init(rwlock)	sx_init(rwlock, "DAHDI rwlock")
 #define read_lock(rwlock)	sx_slock(rwlock)
 #define read_unlock(rwlock)	sx_sunlock(rwlock)
 
