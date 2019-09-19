This patch can most likely be removed when updating to iocage 1.2,
See
https://github.com/iocage/iocage/pull/1027 and
https://github.com/iocage/iocage/commit/f66d9f0724daa03dc08cebc3f30b04abc7e97f82
--- iocage_lib/ioc_upgrade.py.orig	2019-01-25 21:32:55 UTC
+++ iocage_lib/ioc_upgrade.py
@@ -24,6 +24,7 @@
 """iocage upgrade module"""
 import datetime
 import fileinput
+import hashlib
 import os
 import pathlib
 import subprocess as su
@@ -80,9 +81,12 @@ class IOCUpgrade(iocage_lib.ioc_json.IOCZFS):
         }
 
         self.callback = callback
-        # Work around for https://github.com/freebsd/freebsd/commit/bffa924f
-        os.environ['UNAME_r'] = self.jail_release
 
+        # symbolic link created on fetch by freebsd-update
+        bd_hash = hashlib.sha256((self.path + '\n').encode('utf-8')).hexdigest()
+        self.freebsd_install_link = os.path.join(self.path,
+            'var/db/freebsd-update', bd_hash + '-install')
+
     def upgrade_jail(self):
         tmp_dataset = self.zfs_get_dataset_name('/tmp')
         tmp_val = self.zfs_get_property(tmp_dataset, 'exec')
@@ -142,44 +146,26 @@ class IOCUpgrade(iocage_lib.ioc_json.IOCZFS):
                         callback=self.callback
                     )
             else:
-                try:
-                    iocage_lib.ioc_exec.InteractiveExec(
-                        fetch_cmd,
-                        self.path.replace('/root', ''),
-                        uuid=self.uuid,
-                        unjailed=True
-                    )
-                except iocage_lib.ioc_exceptions.CommandFailed:
-                    self.__rollback_jail__()
-                    msg = f'Upgrade failed! Rolling back jail'
+                iocage_lib.ioc_exec.InteractiveExec(
+                    fetch_cmd,
+                    self.path.replace('/root', ''),
+                    uuid=self.uuid,
+                    unjailed=True
+                )
+
+            if not os.path.islink(self.freebsd_install_link):
+                    msg = f'Upgrade failed, nothing to install after fetch!'
                     iocage_lib.ioc_common.logit(
                         {
-                            "level": "EXCEPTION",
-                            "message": msg
+                            'level': 'EXCEPTION',
+                            'message': msg
                         },
                         _callback=self.callback,
                         silent=self.silent
                     )
 
-            if not self.interactive:
-                while not self.__upgrade_install__(tmp.name):
-                    pass
-            else:
-                # FreeBSD update loops 3 times
-                for _ in range(3):
-                    try:
-                        self.__upgrade_install__(tmp.name)
-                    except iocage_lib.ioc_exceptions.CommandFailed:
-                        self.__rollback_jail__()
-                        msg = f'Upgrade failed! Rolling back jail'
-                        iocage_lib.ioc_common.logit(
-                            {
-                                'level': 'EXCEPTION',
-                                'message': msg
-                            },
-                            _callback=self.callback,
-                            silent=self.silent
-                        )
+            while os.path.islink(self.freebsd_install_link):
+                self.__upgrade_install__(tmp.name)
 
             new_release = iocage_lib.ioc_common.get_jail_freebsd_version(
                 self.path,
@@ -353,16 +339,10 @@ class IOCUpgrade(iocage_lib.ioc_json.IOCZFS):
                 unjailed=True,
                 callback=self.callback,
             ) as _exec:
-                update_output = iocage_lib.ioc_common.consume_and_log(
+                iocage_lib.ioc_common.consume_and_log(
                     _exec,
                     callback=self.callback
                 )
-
-            for i in update_output:
-                if i == 'No updates are available to install.':
-                    return True
-
-            return False
         else:
             iocage_lib.ioc_exec.InteractiveExec(
                 install_cmd,
