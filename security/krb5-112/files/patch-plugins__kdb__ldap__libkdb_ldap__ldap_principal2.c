From 46a2d16a5006d61e98a971a8148d2a9574a35bc0 Mon Sep 17 00:00:00 2001
From: Ben Kaduk <kaduk@mit.edu>
Date: Wed, 19 Nov 2014 12:04:46 -0500
Subject: [PATCH] Support keyless principals in LDAP [CVE-2014-5354]

Operations like "kadmin -q 'addprinc -nokey foo'" or
"kadmin -q 'purgekeys -all foo'" result in principal entries with
no keys present, so krb5_encode_krbsecretkey() would just return
NULL, which then got unconditionally dereferenced in
krb5_add_ber_mem_ldap_mod().

Apply some fixes to krb5_encode_krbsecretkey() to handle zero-key
principals better, correct the test for an allocation failure, and
slightly restructure the cleanup handler to be shorter and more
appropriate for the usage.  Once it no longer short-circuits when
n_key_data is zero, it will produce an array of length two with both
entries NULL, which is treated as an empty list by the LDAP library,
the correct behavior for a keyless principal.

However, attributes with empty values are only handled by the LDAP
library for Modify operations, not Add operations (which only get
a sequence of Attribute, with no operation field).  Therefore, only
add an empty krbprincipalkey to the modlist when we will be performing a
Modify, and not when we will be performing an Add, which is conditional
on the (misspelled) create_standalone_prinicipal boolean.

CVE-2014-5354:

In MIT krb5, when kadmind is configured to use LDAP for the KDC
database, an authenticated remote attacker can cause a NULL
dereference by inserting into the database a principal entry which
contains no long-term keys.

In order for the LDAP KDC backend to translate a principal entry
from the database abstraction layer into the form expected by the
LDAP schema, the principal's keys are encoded into a
NULL-terminated array of length-value entries to be stored in the
LDAP database.  However, the subroutine which produced this array
did not correctly handle the case where no keys were present,
returning NULL instead of an empty array, and the array was
unconditionally dereferenced while adding to the list of LDAP
operations to perform.

Versions of MIT krb5 prior to 1.12 did not expose a way for
principal entries to have no long-term key material, and
therefore are not vulnerable.

    CVSSv2 Vector: AV:N/AC:M/Au:S/C:N/I:N/A:P/E:H/RL:OF/RC:C

(cherry picked from commit 04038bf3633c4b909b5ded3072dc88c8c419bf16)

ticket: 8138 (new)
version_fixed: 1.12.3
subject: kadmind with ldap backend crashes when putting keyless entries [CVE-2014-5354]
status: resolved
---
 src/plugins/kdb/ldap/libkdb_ldap/ldap_principal2.c | 25 +++++++++++++++-------
 1 file changed, 17 insertions(+), 8 deletions(-)

diff --git a/src/plugins/kdb/ldap/libkdb_ldap/ldap_principal2.c b/src/plugins/kdb/ldap/libkdb_ldap/ldap_principal2.c
index 111b554..b51bebc 100644
--- plugins/kdb/ldap/libkdb_ldap/ldap_principal2.c
+++ plugins/kdb/ldap/libkdb_ldap/ldap_principal2.c
@@ -413,14 +413,14 @@ krb5_encode_krbsecretkey(krb5_key_data *key_data_in, int n_key_data,
     int num_versions = 1;
     int i, j, last;
     krb5_error_code err = 0;
-    krb5_key_data *key_data;
+    krb5_key_data *key_data = NULL;
 
-    if (n_key_data <= 0)
+    if (n_key_data < 0)
         return NULL;
 
     /* Make a shallow copy of the key data so we can alter it. */
     key_data = k5calloc(n_key_data, sizeof(*key_data), &err);
-    if (key_data_in == NULL)
+    if (key_data == NULL)
         goto cleanup;
     memcpy(key_data, key_data_in, n_key_data * sizeof(*key_data));
 
@@ -474,9 +474,8 @@ krb5_encode_krbsecretkey(krb5_key_data *key_data_in, int n_key_data,
     free(key_data);
     if (err != 0) {
         if (ret != NULL) {
-            for (i = 0; i <= num_versions; i++)
-                if (ret[i] != NULL)
-                    free (ret[i]);
+            for (i = 0; ret[i] != NULL; i++)
+                free (ret[i]);
             free (ret);
             ret = NULL;
         }
@@ -1046,9 +1045,19 @@ krb5_ldap_put_principal(krb5_context context, krb5_db_entry *entry,
         bersecretkey = krb5_encode_krbsecretkey (entry->key_data,
                                                  entry->n_key_data, mkvno);
 
-        if ((st=krb5_add_ber_mem_ldap_mod(&mods, "krbprincipalkey",
-                                          LDAP_MOD_REPLACE | LDAP_MOD_BVALUES, bersecretkey)) != 0)
+        if (bersecretkey == NULL) {
+            st = ENOMEM;
             goto cleanup;
+        }
+        /* An empty list of bervals is only accepted for modify operations,
+         * not add operations. */
+        if (bersecretkey[0] != NULL || !create_standalone_prinicipal) {
+            st = krb5_add_ber_mem_ldap_mod(&mods, "krbprincipalkey",
+                                           LDAP_MOD_REPLACE | LDAP_MOD_BVALUES,
+                                           bersecretkey);
+            if (st != 0)
+                goto cleanup;
+        }
 
         if (!(entry->mask & KADM5_PRINCIPAL)) {
             memset(strval, 0, sizeof(strval));
