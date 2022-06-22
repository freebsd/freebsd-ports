Fixes https://github.com/openssl/openssl/issues/18619

Revert the test of 01fc9b6bce82f0534d6673659a0e59a71f57ee82

--- test/v3ext.c.orig	2022-06-21 13:39:39 UTC
+++ test/v3ext.c
@@ -37,89 +37,11 @@ end:
     return ret;
 }
 
-static int test_asid(void)
-{
-    ASN1_INTEGER *val1 = NULL, *val2 = NULL;
-    ASIdentifiers *asid1 = ASIdentifiers_new(), *asid2 = ASIdentifiers_new(),
-                  *asid3 = ASIdentifiers_new(), *asid4 = ASIdentifiers_new();
-    int testresult = 0;
-
-    if (!TEST_ptr(asid1)
-            || !TEST_ptr(asid2)
-            || !TEST_ptr(asid3))
-        goto err;
-
-    if (!TEST_ptr(val1 = ASN1_INTEGER_new())
-            || !TEST_true(ASN1_INTEGER_set_int64(val1, 64496)))
-        goto err;
-
-    if (!TEST_true(X509v3_asid_add_id_or_range(asid1, V3_ASID_ASNUM, val1, NULL)))
-        goto err;
-
-    val1 = NULL;
-    if (!TEST_ptr(val2 = ASN1_INTEGER_new())
-            || !TEST_true(ASN1_INTEGER_set_int64(val2, 64497)))
-        goto err;
-
-    if (!TEST_true(X509v3_asid_add_id_or_range(asid2, V3_ASID_ASNUM, val2, NULL)))
-        goto err;
-
-    val2 = NULL;
-    if (!TEST_ptr(val1 = ASN1_INTEGER_new())
-            || !TEST_true(ASN1_INTEGER_set_int64(val1, 64496))
-            || !TEST_ptr(val2 = ASN1_INTEGER_new())
-            || !TEST_true(ASN1_INTEGER_set_int64(val2, 64497)))
-        goto err;
-
-    /*
-     * Just tests V3_ASID_ASNUM for now. Could be extended at some point to also
-     * test V3_ASID_RDI if we think it is worth it.
-     */
-    if (!TEST_true(X509v3_asid_add_id_or_range(asid3, V3_ASID_ASNUM, val1, val2)))
-        goto err;
-    val1 = val2 = NULL;
-
-    /* Actual subsets */
-    if (!TEST_true(X509v3_asid_subset(NULL, NULL))
-            || !TEST_true(X509v3_asid_subset(NULL, asid1))
-            || !TEST_true(X509v3_asid_subset(asid1, asid1))
-            || !TEST_true(X509v3_asid_subset(asid2, asid2))
-            || !TEST_true(X509v3_asid_subset(asid1, asid3))
-            || !TEST_true(X509v3_asid_subset(asid2, asid3))
-            || !TEST_true(X509v3_asid_subset(asid3, asid3))
-            || !TEST_true(X509v3_asid_subset(asid4, asid1))
-            || !TEST_true(X509v3_asid_subset(asid4, asid2))
-            || !TEST_true(X509v3_asid_subset(asid4, asid3)))
-        goto err;
-
-    /* Not subsets */
-    if (!TEST_false(X509v3_asid_subset(asid1, NULL))
-            || !TEST_false(X509v3_asid_subset(asid1, asid2))
-            || !TEST_false(X509v3_asid_subset(asid2, asid1))
-            || !TEST_false(X509v3_asid_subset(asid3, asid1))
-            || !TEST_false(X509v3_asid_subset(asid3, asid2))
-            || !TEST_false(X509v3_asid_subset(asid1, asid4))
-            || !TEST_false(X509v3_asid_subset(asid2, asid4))
-            || !TEST_false(X509v3_asid_subset(asid3, asid4)))
-        goto err;
-
-    testresult = 1;
- err:
-    ASN1_INTEGER_free(val1);
-    ASN1_INTEGER_free(val2);
-    ASIdentifiers_free(asid1);
-    ASIdentifiers_free(asid2);
-    ASIdentifiers_free(asid3);
-    ASIdentifiers_free(asid4);
-    return testresult;
-}
-
 int setup_tests(void)
 {
     if (!TEST_ptr(infile = test_get_argument(0)))
         return 0;
 
     ADD_TEST(test_pathlen);
-    ADD_TEST(test_asid);
     return 1;
 }
