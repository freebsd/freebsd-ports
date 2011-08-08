--- setup.py.orig	2011-06-27 13:38:56.000000000 +0200
+++ setup.py	2011-08-06 18:16:54.000000000 +0200
@@ -22,6 +22,16 @@
     print ('system using your package manager.')
     sys.exit(1)
 
+def rename_scripts(files):
+    import shutil
+
+    if files:
+        dirname = os.path.abspath(os.path.join('tools', '_scripts'))
+        if not os.path.exists(dirname):
+            os.makedirs(dirname)
+            for file in files:
+                shutil.copyfile(file, os.path.join(dirname, os.path.basename(file[:-3])))
+
 
 if sys.version_info >= (3,):
     # copy-convert auxiliary python sources
@@ -92,6 +102,8 @@
     if extras:
         kwargs['py_modules'] = extras
     kwargs['classifiers'] = classifiers
+    # Rename scripts files (without .py)
+    rename_scripts(glob.glob('tools/rst*.py'))
     # Install data files properly.
     kwargs['cmdclass'] = {'build_data': build_data,
                           'install_data': smart_install_data}
@@ -166,18 +178,7 @@
                      ['docutils/writers/odf_odt/styles.odt']),
                      ]
                    + s5_theme_files),
-    'scripts' : ['tools/rst2html.py',
-                 'tools/rst2s5.py',
-                 'tools/rst2latex.py',
-                 # 'tools/rst2newlatex.py',
-                 'tools/rst2xetex.py',
-                 'tools/rst2man.py',
-                 'tools/rst2xml.py',
-                 'tools/rst2pseudoxml.py',
-                 'tools/rstpep2html.py',
-                 'tools/rst2odt.py',
-                 'tools/rst2odt_prepstyles.py',
-                 ],}
+    'scripts' : glob.glob('tools/_scripts/*'),}
 """Distutils setup parameters."""
 
 classifiers = [
