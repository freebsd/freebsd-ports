--- python/samba/provision/__init__.py.orig	2025-02-06 10:31:54 UTC
+++ python/samba/provision/__init__.py
@@ -1671,19 +1671,25 @@ def setsysvolacl(samdb, sysvol, uid, gid, domainsid, d
         s3conf = s3param.get_context()
         s3conf.load(lp.configfile)
 
-        file = tempfile.NamedTemporaryFile(dir=os.path.abspath(sysvol))
+        sysvol_dir = os.path.abspath(sysvol)
+
+        set_simple_acl = smbd.set_simple_acl
+        if smbd.has_nfsv4_acls(sysvol_dir):
+            set_simple_acl = smbd.set_simple_nfsv4_acl
+
+        file = tempfile.NamedTemporaryFile(dir=sysvol_dir)
         try:
             try:
-                smbd.set_simple_acl(file.name, 0o755, system_session_unix(), gid)
+                set_simple_acl(file.name, 0o755, system_session_unix(), gid)
             except OSError:
-                if not smbd.have_posix_acls():
+                if not smbd.have_posix_acls() and not smbd.have_nfsv4_acls():
                     # This clue is only strictly correct for RPM and
                     # Debian-like Linux systems, but hopefully other users
                     # will get enough clue from it.
-                    raise ProvisioningError("Samba was compiled without the posix ACL support that s3fs requires.  "
+                    raise ProvisioningError("Samba was compiled without the ACL support that s3fs requires.  "
                                             "Try installing libacl1-dev or libacl-devel, then re-run configure and make.")
 
-                raise ProvisioningError("Your filesystem or build does not support posix ACLs, which s3fs requires.  "
+                raise ProvisioningError("Your filesystem or build does not support ACLs, which s3fs requires.  "
                                         "Try the mounting the filesystem with the 'acl' option.")
             try:
                 smbd.chown(file.name, uid, gid, system_session_unix())
@@ -1906,7 +1912,7 @@ def interface_ips_v6(lp):
     return ret
 
 
-def provision_fill(samdb, secrets_ldb, logger, names, paths,
+def provision_fill(samdb, secrets_ldb, logger, names, paths, targetdir,
                    schema=None,
                    samdb_fill=FILL_FULL,
                    hostip=None, hostip6=None,
@@ -1965,6 +1971,9 @@ def provision_fill(samdb, secrets_ldb, logger, names, 
         samdb.transaction_commit()
 
     if serverrole == "active directory domain controller":
+        if targetdir and smbd.have_nfsv4_acls() and smbd.has_nfsv4_acls(targetdir):
+            smbd.set_nfsv4_defaults()
+
         # Continue setting up sysvol for GPO. This appears to require being
         # outside a transaction.
         if not skip_sysvolacl:
@@ -2341,6 +2350,9 @@ def provision(logger, session_info, smbconf=None,
             if not os.path.isdir(paths.netlogon):
                 os.makedirs(paths.netlogon, 0o755)
 
+            if smbd.have_nfsv4_acls() and smbd.has_nfsv4_acls(paths.sysvol):
+                smbd.set_nfsv4_defaults()
+
         if adminpass is None:
             adminpass = samba.generate_random_password(12, 32)
             adminpass_generated = True
@@ -2350,7 +2362,7 @@ def provision(logger, session_info, smbconf=None,
             adminpass_generated = False
 
         if samdb_fill == FILL_FULL:
-            provision_fill(samdb, secrets_ldb, logger, names, paths,
+            provision_fill(samdb, secrets_ldb, logger, names, paths, targetdir,
                            schema=schema, samdb_fill=samdb_fill,
                            hostip=hostip, hostip6=hostip6,
                            next_rid=next_rid, dc_rid=dc_rid, adminpass=adminpass,
