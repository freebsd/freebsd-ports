--- python/PETSc/packages/X11.py.orig	Wed Sep 22 02:45:51 2004
+++ python/PETSc/packages/X11.py	Sat Oct  2 00:27:14 2004
@@ -26,7 +26,7 @@
     import nargs
     help.addArgument('X11', '-with-x=<bool>',                nargs.ArgBool(None, 1,   'Activate X11'))
     help.addArgument('X11', '-with-x-include=<include dir>', nargs.ArgDir(None, None, 'Specify an include directory for X11'))
-    help.addArgument('X11', '-with-x-lib=<X11 lib>',         nargs.Arg(None, None,    'Specify X11 library file'))
+    help.addArgument('X11', '-with-x-library=<X11 lib>',         nargs.Arg(None, None,    'Specify X11 library file'))
     return
 
   def generateGuesses(self):
@@ -123,6 +123,7 @@
       if not os.path.isdir(self.framework.argDB['with-x-include']):
         raise RuntimeError('Invalid X include directory specified by --with-x-include='+os.path.abspath(self.framework.argDB['with-x-include']))
       includeDir = self.framework.argDB['with-x-include']
+      foundInclude = 1
     else:
       testInclude  = 'X11/Intrinsic.h'
 
@@ -144,6 +145,7 @@
       if not os.path.isfile(self.framework.argDB['with-x-library']):
         raise RuntimeError('Invalid X library specified by --with-x-library='+os.path.abspath(self.framework.argDB['with-x-library']))
       libraryDir = os.path.dirname(self.framework.argDB['with-x-library'])
+      foundLibrary = 1
     else:
       testLibrary  = 'Xt'
       testFunction = 'XtMalloc'
