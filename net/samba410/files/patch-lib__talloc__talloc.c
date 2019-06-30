--- lib/talloc/talloc.c.orig	2018-01-13 09:07:51 UTC
+++ lib/talloc/talloc.c
@@ -387,6 +387,9 @@ void talloc_lib_init(void) __attribute__
 void talloc_lib_init(void)
 {
 	uint32_t random_value;
+#if defined(HAVE_ARC4RANDOM)
+	random_value = arc4random();
+#else
 #if defined(HAVE_GETAUXVAL) && defined(AT_RANDOM)
 	uint8_t *p;
 	/*
@@ -420,6 +423,7 @@ void talloc_lib_init(void)
 		 */
 		random_value = ((uintptr_t)talloc_lib_init & 0xFFFFFFFF);
 	}
+#endif /* HAVE_ARC4RANDOM */
 	talloc_magic = random_value & ~TALLOC_FLAG_MASK;
 }
 #else
