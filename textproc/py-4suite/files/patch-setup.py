This patch mainly ensures that the (optional) documentation is installed to
the "correct" location:

- It removes the hard-coded installation path for documentation.  This allows
  the installation path to be specified at install time with the
  "--install-data" parameter to "setup.py install".

- It removes some redundant documentation.

- It splits data_files into two parts, one which contains only documentation,
  and one which contains all other files (currently, juse one!)

Note that setup.py is processed further in the port Makefile's post-patch
target.

-- Johann Visagie <johann@egenetics.com>


--- setup.py.orig	Tue May  1 00:38:56 2001
+++ setup.py	Fri May  4 17:23:15 2001
@@ -304,21 +304,7 @@
 #
 ############################################################
 
-data_files = [Data_Files(copy_to='.',
-                         files=['docs/text/COPYRIGHT',
-                                'docs/text/CREDITS',
-                                'docs/text/PACKAGES',
-                                'docs/text/README',
-                                'docs/text/REBUILDING',
-                                'docs/text/TODO',
-                                'docs/ChangeLog',
-                                'docs/README.cDomlette',
-                                'docs/README.Cyclops',
-                                ]),
-              Data_Files(copy_to='docs',
-                         files=['docs/ChangeLog',
-                                ]),
-              Data_Files(copy_to='docs/text',
+data_files = [Data_Files(copy_to='docs/text',
                          files=['docs/text/COPYRIGHT',
                                 'docs/text/CREDITS',
                                 'docs/text/PACKAGES',
@@ -435,9 +421,6 @@
               Data_Files(copy_to='test_suite/4ODS/Tools',
                          files=glob.glob('Ods/Tools/test_suite/*.*')),
 
-              Data_Files(use_install_cmd='install_lib',
-                         copy_to='Ft/DbDom',
-                         files=['DbDom/dom.odl']),
               Data_Files(copy_to='test_suite/DbDom',
                          files=['Lib/TestSuite.py']),
               Data_Files(copy_to='test_suite/DbDom',
@@ -457,8 +440,10 @@
               Data_Files(copy_to='demo/4ODS/book_mark_manager',
                          files=glob.glob('Ods/demo/book_mark_manager/*.*')),
               ]
-for df in data_files:
-    df.base_dir = '$base/doc/$dist_name-$dist_version'
+data_files2 = [Data_Files(use_install_cmd='install_lib',
+                         copy_to='Ft/DbDom',
+                         files=['DbDom/dom.odl'])
+              ]
 
 ############################################################
 #
@@ -545,7 +530,7 @@
     py_files=py_files,
     l10n=l10n,
     
-    data_files=data_files,
+    data_files=data_files + data_files2,
     ext_modules=ext_modules,
     scripts=DistExt.EnsureScripts('Xslt/bin/4xslt',
                                   'Rdf/exec/4rdf',
