This patch mainly ensures that the (optional) documentation is installed to
the "correct" location:

- It removes the hard-coded installation path for documentation.  This allows
  the installation path to be specified at install time with the
  "--install-data" parameter to "setup.py install".

- It removes some redundant documentation.

Note that setup.py is processed further in the port Makefile's post-patch
target.

-- Johann Visagie <wjv@FreeBSD.org>


--- setup.py.orig	Thu Sep 13 20:21:05 2001
+++ setup.py	Fri Sep 14 16:40:29 2001
@@ -228,22 +228,7 @@
 #
 ############################################################
 
-data_files = [Data_Files(copy_to='.',
-                         files=['docs/text/COPYRIGHT',
-                                'docs/text/CREDITS',
-                                'docs/text/PACKAGES',
-                                'docs/text/README',
-                                'docs/text/ReleaseNotes',
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
@@ -330,7 +315,7 @@
                          files=get_files('test_suite/Rdf/Inference/*.*')),
 
 
-              Data_Files(copy_to='profile/Rdf',
+              Data_Files(copy_to='test_suite/profile/Rdf',
                          files=get_files('profile/Rdf/*.*')),
 
 
@@ -353,7 +338,7 @@
               Data_Files(copy_to='test_suite/Ods/borrowed',
                          files=get_files('test_suite/Ods/borrowed/*.*')),
 
-              Data_Files(copy_to='profile/Ods',
+              Data_Files(copy_to='test_suite/profile/Ods',
                          files=get_files('profile/Ods/*.*')),
 
 
@@ -377,9 +362,6 @@
               Data_Files(copy_to='demos/4ODS/tutorial',
                          files=get_files('demos/4ODS/tutorial/*.*')),
               ]
-
-for df in data_files:
-    df.base_dir = '$base/doc/$dist_name-$dist_version'
 
 ############################################################
 #
