--- egg/tests/test-secmem.c.orig	Wed Sep 26 10:28:35 2012
+++ egg/tests/test-secmem.c	Sat Oct 27 14:46:28 2012
@@ -39,7 +39,7 @@ extern int egg_secure_warnings;
 
 EGG_SECURE_DECLARE (tests);
 
-/* 
+/*
  * Each test looks like (on one line):
  *     void unit_test_xxxxx (CuTest* cu)
  *
@@ -93,10 +93,12 @@ test_realloc_across (void)
 	g_assert (p != NULL);
 	g_assert_cmpint (G_MAXSIZE, ==, find_non_zero (p, 1088));
 
-	/* Reallocate to a large one, will have to have changed blocks */	
+	/* Reallocate to a large one, will have to have changed blocks */
 	p2 = egg_secure_realloc_full ("tests", p, 16200, 0);
 	g_assert (p2 != NULL);
 	g_assert_cmpint (G_MAXSIZE, ==, find_non_zero (p2, 16200));
+
+	egg_secure_free (p2);
 }
 
 static void
@@ -180,26 +182,25 @@ test_multialloc (void)
 		case 0: /* Allocate some memory */
 			size = g_random_int_range (1, 16384);
 			data = egg_secure_alloc (size);
-			g_assert (data);
+			g_assert (data != NULL);
 			memset (data, 0xCAFEBABE, size);
 			g_ptr_array_add (memory, data);
 			break;
 		case 1: /* Reallocate some memory */
 			index = g_random_int_range (0, memory->len);
 			data = g_ptr_array_index (memory, index);
-			g_assert (data);
+			g_assert (data != NULL);
 			size = g_random_int_range (1, 16384);
 			data = egg_secure_realloc (data, size);
-			g_assert (data);
+			g_assert (data != NULL);
 			memset (data, 0xCAFEBABE, size);
 			g_ptr_array_index (memory, index) = data;
 			break;
 		case 2: /* Free some memory */
 			index = g_random_int_range (0, memory->len);
-			data = g_ptr_array_index (memory, index);
-			g_assert (data);
+			data = g_ptr_array_remove_index_fast (memory, index);
+			g_assert (data != NULL);
 			egg_secure_free (data);
-			g_ptr_array_remove_index_fast (memory, index);
 			break;
 		default:
 			g_assert_not_reached ();
@@ -212,6 +213,8 @@ test_multialloc (void)
 	}
 
 	g_assert (memory->len == 0);
+	for (i = 0; i < memory->len; i++)
+		egg_secure_free (memory->pdata[i]);
 	g_ptr_array_free (memory, TRUE);
 
 	egg_secure_warnings = 1;
