From 5fbb56c4624df9e6b0d0a80f46e5ad37eb79c6c0 Mon Sep 17 00:00:00 2001
From: Greg Hudson <ghudson@mit.edu>
Date: Fri, 5 Dec 2014 14:01:39 -0500
Subject: [PATCH] Fix LDAP misused policy name crash [CVE-2014-5353]

In krb5_ldap_get_password_policy_from_dn, if LDAP_SEARCH returns
successfully with no results, return KRB5_KDB_NOENTRY instead of
returning success with a zeroed-out policy object.  This fixes a null
dereference when an admin attempts to use an LDAP ticket policy name
as a password policy name.

CVE-2014-5353:

In MIT krb5, when kadmind is configured to use LDAP for the KDC
database, an authenticated remote attacker can cause a NULL dereference
by attempting to use a named ticket policy object as a password policy
for a principal.  The attacker needs to be authenticated as a user who
has the elevated privilege for setting password policy by adding or
modifying principals.

Queries to LDAP scoped to the krbPwdPolicy object class will correctly
not return entries of other classes, such as ticket policy objects, but
may return success with no returned elements if an object with the
requested DN exists in a different object class.  In this case, the
routine to retrieve a password policy returned success with a password
policy object that consisted entirely of zeroed memory.  In particular,
accesses to the policy name will dereference a NULL pointer.  KDC
operation does not access the policy name field, but most kadmin
operations involving the principal with incorrect password policy
will trigger the crash.

Thanks to Patrik Kis for reporting this problem.

CVSSv2 Vector: AV:N/AC:M/Au:S/C:N/I:N/A:C/E:H/RL:OF/RC:C

[kaduk@mit.edu: CVE description and CVSS score]

(cherry picked from commit d1f707024f1d0af6e54a18885322d70fa15ec4d3)
(cherry picked from commit 0a97ce4411b34e871ae503b78eedf61db27180ea)

ticket: 8142 (new)
version_fixed: 1.11.6
status: resolved
---
 src/plugins/kdb/ldap/libkdb_ldap/ldap_pwd_policy.c | 7 ++++---
 1 file changed, 4 insertions(+), 3 deletions(-)

diff --git a/src/plugins/kdb/ldap/libkdb_ldap/ldap_pwd_policy.c b/src/plugins/kdb/ldap/libkdb_ldap/ldap_pwd_policy.c
index 09cfb8c..dd1fab8 100644
--- plugins/kdb/ldap/libkdb_ldap/ldap_pwd_policy.c
+++ plugins/kdb/ldap/libkdb_ldap/ldap_pwd_policy.c
@@ -320,10 +320,11 @@ krb5_ldap_get_password_policy_from_dn(krb5_context context, char *pol_name,
     LDAP_SEARCH(pol_dn, LDAP_SCOPE_BASE, "(objectclass=krbPwdPolicy)", password_policy_attributes);
 
     ent=ldap_first_entry(ld, result);
-    if (ent != NULL) {
-        if ((st = populate_policy(context, ld, ent, pol_name, *policy)) != 0)
-            goto cleanup;
+    if (ent == NULL) {
+        st = KRB5_KDB_NOENTRY;
+        goto cleanup;
     }
+    st = populate_policy(context, ld, ent, pol_name, *policy);
 
 cleanup:
     ldap_msgfree(result);
