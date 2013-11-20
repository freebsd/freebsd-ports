--- egg/tests/test-secmem.c.orig	Mon Sep  5 07:16:09 2011
+++ egg/tests/test-secmem.c	Sat Oct 27 14:36:16 2012
@@ -23,7 +23,7 @@
 
 #include "config.h"
 
-#include "egg-secure-memory.h"
+#include "egg/egg-secure-memory.h"
 
 #include <glib.h>
 
@@ -31,11 +31,14 @@
 #include <stdio.h>
 #include <string.h>
 
-EGG_SECURE_GLIB_DEFINITIONS ();
 
+EGG_SECURE_DEFINE_GLIB_GLOBALS ();
+
 /* Declared in egg-secure-memory.c */
 extern int egg_secure_warnings;
 
+EGG_SECURE_DECLARE (tests);
+
 /*
  * Each test looks like (on one line):
  *     void unit_test_xxxxx (CuTest* cu)
@@ -68,7 +71,7 @@ test_alloc_free (void)
 	gpointer p;
 	gboolean ret;
 
-	p = egg_secure_alloc_full (512, 0);
+	p = egg_secure_alloc_full ("tests", 512, 0);
 	g_assert (p != NULL);
 	g_assert_cmpint (G_MAXSIZE, ==, find_non_zero (p, 512));
 
@@ -86,14 +89,16 @@ test_realloc_across (void)
 	gpointer p, p2;
 
 	/* Tiny allocation */
-	p = egg_secure_realloc_full (NULL, 1088, 0);
+	p = egg_secure_realloc_full ("tests", NULL, 1088, 0);
 	g_assert (p != NULL);
 	g_assert_cmpint (G_MAXSIZE, ==, find_non_zero (p, 1088));
 
 	/* Reallocate to a large one, will have to have changed blocks */
-	p2 = egg_secure_realloc_full (p, 16200, 0);
+	p2 = egg_secure_realloc_full ("tests", p, 16200, 0);
 	g_assert (p2 != NULL);
 	g_assert_cmpint (G_MAXSIZE, ==, find_non_zero (p2, 16200));
+
+	egg_secure_free (p2);
 }
 
 static void
@@ -102,13 +107,13 @@ test_alloc_two (void)
 	gpointer p, p2;
 	gboolean ret;
 
-	p2 = egg_secure_alloc_full (4, 0);
+	p2 = egg_secure_alloc_full ("tests", 4, 0);
 	g_assert (p2 != NULL);
 	g_assert_cmpint (G_MAXSIZE, ==, find_non_zero (p2, 4));
 
 	memset (p2, 0x67, 4);
 
-	p = egg_secure_alloc_full (16200, 0);
+	p = egg_secure_alloc_full ("tests", 16200, 0);
 	g_assert (p != NULL);
 	g_assert_cmpint (G_MAXSIZE, ==, find_non_zero (p, 16200));
 
@@ -130,19 +135,19 @@ test_realloc (void)
 
 	len = strlen (str) + 1;
 
-	p = egg_secure_realloc_full (NULL, len, 0);
+	p = egg_secure_realloc_full ("tests", NULL, len, 0);
 	g_assert (p != NULL);
 	g_assert_cmpint (G_MAXSIZE, ==, find_non_zero (p, len));
 
 	strcpy ((gchar*)p, str);
 
-	p2 = egg_secure_realloc_full (p, 512, 0);
+	p2 = egg_secure_realloc_full ("tests", p, 512, 0);
 	g_assert (p2 != NULL);
 	g_assert_cmpint (G_MAXSIZE, ==, find_non_zero (((gchar*)p2) + len, 512 - len));
 
 	g_assert (strcmp (p2, str) == 0);
 
-	p = egg_secure_realloc_full (p2, 0, 0);
+	p = egg_secure_realloc_full ("tests", p2, 0, 0);
 	g_assert (p == NULL);
 }
 
@@ -154,9 +159,6 @@ test_multialloc (void)
 	gsize size;
 	int i, action, index;
 
-	if (g_test_quick ())
-		return;
-
 	/* A predetermined seed to get a predetermined pattern */
 	g_random_set_seed (15);
 	memory = g_ptr_array_new ();
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
@@ -222,7 +225,7 @@ test_clear (void)
 {
 	gpointer p;
 
-	p = egg_secure_alloc_full (188, 0);
+	p = egg_secure_alloc_full ("tests", 188, 0);
 	g_assert (p != NULL);
 	memset (p, 0x89, 188);
 	g_assert (memchr (p, 0x89, 188) == p);
@@ -255,9 +258,9 @@ main (int argc, char **argv)
 {
 	g_test_init (&argc, &argv, NULL);
 
-	g_test_add_func ("/secmem/alloc-free", test_alloc_free);
-	g_test_add_func ("/secmem/realloc-across", test_realloc_across);
-	g_test_add_func ("/secmem/alloc-two", test_alloc_two);
+	g_test_add_func ("/secmem/alloc_free", test_alloc_free);
+	g_test_add_func ("/secmem/realloc_across", test_realloc_across);
+	g_test_add_func ("/secmem/alloc_two", test_alloc_two);
 	g_test_add_func ("/secmem/realloc", test_realloc);
 	g_test_add_func ("/secmem/multialloc", test_multialloc);
 	g_test_add_func ("/secmem/clear", test_clear);
