--- cli.py.orig	2010-07-07 20:46:08.000000000 +0200
+++ cli.py	2010-08-22 13:35:53.000000000 +0200
@@ -1412,10 +1412,10 @@
         if opts.installroot:
             if os.access(opts.installroot+'/'+opts.conffile, os.R_OK):
                 opts.conffile = opts.installroot+'/'+opts.conffile
-            elif opts.conffile == '/etc/yum/yum.conf':
-                # check if /installroot/etc/yum.conf exists.
-                if os.access(opts.installroot+'/etc/yum.conf', os.R_OK):
-                    opts.conffile = opts.installroot+'/etc/yum.conf'         
+            elif opts.conffile == '@PREFIX@/etc/yum/yum.conf':
+                # check if /installroot@PREFIX@/etc/yum.conf exists.
+                if os.access(opts.installroot+'@PREFIX@/etc/yum.conf', os.R_OK):
+                    opts.conffile = opts.installroot+'@PREFIX@/etc/yum.conf'         
             root=opts.installroot
         else:
             root = '/'
@@ -1456,7 +1456,7 @@
                 action="store_true",
                 help=_("run entirely from system cache, don't update cache"))
         group.add_option("-c", "--config", dest="conffile",
-                default='/etc/yum/yum.conf',
+                default='@PREFIX@/etc/yum/yum.conf',
                 help=_("config file location"), metavar='[config file]')
         group.add_option("-R", "--randomwait", dest="sleeptime", type='int',
                 default=None,
