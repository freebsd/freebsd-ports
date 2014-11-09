--- setup.py.orig	2014-11-03 12:38:21.000000000 -0700
+++ setup.py        2014-11-04 14:42:58.775471457 -0700
@@ -212,12 +212,12 @@
             self.distribution.package_data.pop('salt.daemons.flo', None)
             self.filelist.files.append(os.path.basename(PACKAGED_FOR_SALT_SSH_FILE))
             self.distribution.metadata.name = 'salt-ssh'
-            self.distribution.data_files = [('share/man/man1',
+            self.distribution.data_files = [('man/man1',
                                              ['doc/man/salt-ssh.1',
                                               'doc/man/salt-run.1',
                                               'doc/man/salt-call.1',
                                               'doc/man/salt-cloud.1']),
-                                            ('share/man/man7', ['doc/man/salt.7'])]
+                                            ('man/man7', ['doc/man/salt.7'])]
 
         sdist.make_release_tree(self, base_dir, files)
 
@@ -666,13 +666,13 @@
                                     '*.flo'
                                     ]
                                 },
-                'data_files': [('share/man/man1',
+                'data_files': [('man/man1',
                                 ['doc/man/salt-cp.1',
                                  'doc/man/salt-call.1',
                                  'doc/man/salt-minion.1',
                                  'doc/man/salt-unity.1',
                                  ]),
-                               ('share/man/man7',
+                               ('man/man7',
                                 ['doc/man/salt.7',
                                  ]),
                                ],
