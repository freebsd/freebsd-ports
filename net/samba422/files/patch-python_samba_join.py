--- python/samba/join.py.orig	2025-02-06 10:31:54 UTC
+++ python/samba/join.py
@@ -917,7 +917,7 @@ class DCJoinContext(object):
         secrets_ldb = Ldb(ctx.paths.secrets, session_info=system_session(), lp=ctx.lp)
 
         provision_fill(ctx.local_samdb, secrets_ldb,
-                       ctx.logger, ctx.names, ctx.paths,
+                       ctx.logger, ctx.names, ctx.targetdir, ctx.paths,
                        dom_for_fun_level=ctx.behavior_version,
                        samdb_fill=FILL_SUBDOMAIN,
                        machinepass=ctx.acct_pass, serverrole="active directory domain controller",
