--- lib/talloc/talloc.c.orig	2026-01-20 15:42:54 UTC
+++ lib/talloc/talloc.c
@@ -397,6 +397,9 @@ void talloc_lib_init(void)
 void talloc_lib_init(void)
 {
 	uint32_t random_value;
+#if defined(HAVE_ARC4RANDOM)
+	random_value = arc4random();
+#else
 #if defined(HAVE_GETAUXVAL) && defined(AT_RANDOM)
 	uint8_t *p;
 	/*
@@ -430,6 +433,7 @@ void talloc_lib_init(void)
 		 */
 		random_value = ((uintptr_t)talloc_lib_init & 0xFFFFFFFF);
 	}
+#endif /* HAVE_ARC4RANDOM */
 	talloc_magic = random_value & ~TALLOC_FLAG_MASK;
 }
 #else
