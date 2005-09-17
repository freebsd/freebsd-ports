--- python/PETSc/packages/X11.py.orig	Thu Aug 11 01:08:41 2005
+++ python/PETSc/packages/X11.py	Sun Aug 21 23:06:02 2005
@@ -26,7 +26,7 @@
     import nargs
     help.addArgument('X11', '-with-x=<bool>',                nargs.ArgBool(None, 1,   'Activate X11'))
     help.addArgument('X11', '-with-x-include=<include dir>', nargs.ArgDir(None, None, 'Specify an include directory for X11'))
-    help.addArgument('X11', '-with-x-lib=<X11 lib>',         nargs.Arg(None, None,    'Specify X11 library file'))
+    help.addArgument('X11', '-with-x-library=<X11 lib>',         nargs.Arg(None, None,    'Specify X11 library file'))
     return
 
   def setupDependencies(self, framework):
