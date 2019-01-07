--- tools/gn/bootstrap/bootstrap.py.orig	2018-12-12 22:56:27.000000000 +0100
+++ tools/gn/bootstrap/bootstrap.py	2018-12-16 00:01:37.174054000 +0100
@@ -76,8 +76,6 @@
       '--no-last-commit-position',
       '--out-path=' + gn_build_dir,
   ]
-  if not options.with_sysroot:
-    cmd.append('--no-sysroot')
   if options.debug:
     cmd.append('--debug')
   subprocess.check_call(cmd)
@@ -86,6 +84,8 @@
       os.path.join(BOOTSTRAP_DIR, 'last_commit_position.h'), gn_build_dir)
   subprocess.check_call(
       ['ninja', '-C', gn_build_dir, 'gn', '-w', 'dupbuild=err'])
+  subprocess.check_call(
+    ['ninja', '-C', gn_build_dir, 'gn_unittests', '-w', 'dupbuild=err'])
   shutil.copy2(os.path.join(gn_build_dir, 'gn'), gn_path)
 
   if not options.skip_generate_buildfiles:
