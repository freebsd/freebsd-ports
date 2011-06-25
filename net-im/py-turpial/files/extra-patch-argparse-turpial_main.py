--- turpial/main.py.orig	2011-03-23 17:50:07.000000000 +0100
+++ turpial/main.py	2011-03-27 16:33:05.000000000 +0200
@@ -12,7 +12,7 @@
 import base64
 import logging
 import getpass
-from optparse import OptionParser
+import argparse
 
 from turpial.api.servicesapi import HTTPServices
 from turpial.api.turpialapi import TurpialAPI
@@ -21,8 +21,8 @@
 
 try:
     import ctypes
-    libc = ctypes.CDLL('libc.so.6')
-    libc.prctl(15, 'turpial', 0, 0)
+    libc = ctypes.CDLL(os.path.join('/usr/lib', 'libc.so'))
+    libc.setproctitle('turpial')
 except ImportError:
     pass
 
@@ -44,34 +44,34 @@
         ui_avail = ui_avail[:-1] + ')'
         default_ui = INTERFACES[1] if len(INTERFACES) > 1 else ''
         
-        parser = OptionParser()
-        parser.add_option('-d', '--debug', dest='debug', action='store_true',
+        parser = argparse.ArgumentParser() 
+        parser.add_argument('-d', '--debug', dest='debug', action='store_true',
             help='show debug info in shell during execution', default=False)
-        parser.add_option('-i', '--interface', dest='interface',
+        parser.add_argument('-i', '--interface', dest='interface',
             help='select interface to use %s' % ui_avail, default=default_ui)
-        parser.add_option('-c', '--clean', dest='clean', action='store_true',
+        parser.add_argument('-c', '--clean', dest='clean', action='store_true',
             help='clean all bytecodes', default=False)
-        parser.add_option('-s', '--save-credentials', dest='save', action='store_true',
+        parser.add_argument('-s', '--save-credentials', dest='save', action='store_true',
             help='save user credentials', default=False)
-        parser.add_option('--version', dest='version', action='store_true',
+        parser.add_argument('--version', dest='version', action='store_true',
             help='show the version of Turpial and exit', default=False)
-        parser.add_option('--test', dest='test', action='store_true',
+        parser.add_argument('--test', dest='test', action='store_true',
             help='only load timeline and friends', default=False)
-        parser.add_option('--no-sound', dest='no_sound', action='store_true',
+        parser.add_argument('--no-sound', dest='no_sound', action='store_true',
             help='disable the sounds module', default=False)
-        parser.add_option('--no-notif', dest='no_notif', action='store_true',
+        parser.add_argument('--no-notif', dest='no_notif', action='store_true',
             help='disable the notifications module', default=False)
         
-        (options, args) = parser.parse_args()
+        args = parser.parse_args()
         
         self.config = None
         self.global_cfg = ConfigApp()
         self.protocol_cfg = {}
         self.profile = None
-        self.testmode = options.test
-        self.interface = options.interface
-        self.no_sound = options.no_sound
-        self.no_notif = options.no_notif
+        self.testmode = args.test
+        self.interface = args.interface
+        self.no_sound = args.no_sound
+        self.no_notif = args.no_notif
         self.httpserv = None
         self.api = None
         self.version = self.global_cfg.read('App', 'version')
@@ -79,34 +79,34 @@
         for p in PROTOCOLS:
             self.protocol_cfg[p] = ConfigProtocol(p)
         
-        if options.debug or options.clean: 
+        if args.debug or args.clean: 
             logging.basicConfig(level=logging.DEBUG)
         else:
             logging.basicConfig(level=logging.INFO)
         self.log = logging.getLogger('Controller')
         
-        if options.clean:
+        if args.clean:
             self.__clean()
             sys.exit(0)
             
-        if options.version:
+        if args.version:
             print "Turpial v%s" % self.version
             print "Python v%X" % sys.hexversion
             sys.exit(0)
             
-        if options.save:
+        if args.save:
             try:
                 self.__save_credentials()
             except KeyboardInterrupt:
                 self.log.debug('Interceptado Keyboard Interrupt')
             sys.exit(0)
             
-        self.interface = options.interface
-        if options.interface == 'gtk+' and ('gtk+' in INTERFACES):
+        self.interface = args.interface
+        if args.interface == 'gtk+' and ('gtk+' in INTERFACES):
             self.ui = _GTK(self, extend=True)
-        elif options.interface == 'gtk' and ('gtk' in INTERFACES):
+        elif args.interface == 'gtk' and ('gtk' in INTERFACES):
             self.ui = _GTK(self)
-        elif options.interface == 'cmd' and ('cmd' in INTERFACES):
+        elif args.interface == 'cmd' and ('cmd' in INTERFACES):
             self.ui = _CMD(self, args)
         else:
             print 'No existe una interfaz válida. Las interfaces válidas son: %s' % INTERFACES
