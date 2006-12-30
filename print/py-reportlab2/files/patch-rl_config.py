--- rl_config.py.orig	Sat Dec 30 16:43:40 2006
+++ rl_config.py	Sat Dec 30 16:43:45 2006
@@ -25,25 +25,18 @@
 
 # places to look for T1Font information
 T1SearchPath =  (
-                'c:/Program Files/Adobe/Acrobat 9.0/Resource/Font', 
-                'c:/Program Files/Adobe/Acrobat 8.0/Resource/Font', 
-                'c:/Program Files/Adobe/Acrobat 7.0/Resource/Font', 
-                'c:/Program Files/Adobe/Acrobat 6.0/Resource/Font', #Win32, Acrobat 6
-                'c:/Program Files/Adobe/Acrobat 5.0/Resource/Font',     #Win32, Acrobat 5
-                'c:/Program Files/Adobe/Acrobat 4.0/Resource/Font', #Win32, Acrobat 4
-                '%(disk)s/Applications/Python %(sys_version)s/reportlab/fonts', #Mac?
-                '/usr/lib/Acrobat9/Resource/Font',      #Linux, Acrobat 5?
-                '/usr/lib/Acrobat8/Resource/Font',      #Linux, Acrobat 5?
-                '/usr/lib/Acrobat7/Resource/Font',      #Linux, Acrobat 5?
-                '/usr/lib/Acrobat6/Resource/Font',      #Linux, Acrobat 5?
-                '/usr/lib/Acrobat5/Resource/Font',      #Linux, Acrobat 5?
-                '/usr/lib/Acrobat4/Resource/Font',      #Linux, Acrobat 4
-                '/usr/local/Acrobat9/Resource/Font',    #Linux, Acrobat 5?
-                '/usr/local/Acrobat8/Resource/Font',    #Linux, Acrobat 5?
-                '/usr/local/Acrobat7/Resource/Font',    #Linux, Acrobat 5?
-                '/usr/local/Acrobat6/Resource/Font',    #Linux, Acrobat 5?
-                '/usr/local/Acrobat5/Resource/Font',    #Linux, Acrobat 5?
-                '/usr/local/Acrobat4/Resource/Font',    #Linux, Acrobat 4
+                '/usr/lib/Acrobat9/Resource/Font',
+                '/usr/lib/Acrobat8/Resource/Font',
+                '/usr/lib/Acrobat7/Resource/Font',
+                '/usr/lib/Acrobat6/Resource/Font',
+                '/usr/lib/Acrobat5/Resource/Font',
+                '/usr/lib/Acrobat4/Resource/Font',
+                '/usr/local/Acrobat9/Resource/Font',
+                '/usr/local/Acrobat8/Resource/Font',
+                '/usr/local/Acrobat7/Resource/Font',
+                '/usr/local/Acrobat6/Resource/Font',
+                '/usr/local/Acrobat5/Resource/Font',
+                '/usr/local/Acrobat4/Resource/Font',
                 '%(REPORTLAB_DIR)s/fonts',              #special
                 '%(REPORTLAB_DIR)s/../fonts',           #special
                 '%(REPORTLAB_DIR)s/../../fonts',        #special
@@ -52,9 +45,7 @@
 
 # places to look for TT Font information
 TTFSearchPath = (
-                'c:/winnt/fonts',
-                'c:/windows/fonts',
-                '/usr/lib/X11/fonts/TrueType/',
+                '/usr/X11R6/lib/X11/fonts/TrueType/',
                 '%(REPORTLAB_DIR)s/fonts',      #special
                 '%(REPORTLAB_DIR)s/../fonts',   #special
                 '%(REPORTLAB_DIR)s/../../fonts',#special
@@ -75,17 +66,11 @@
                   '/usr/local/Acrobat6/Resource/CMap',
                   '/usr/local/Acrobat5/Resource/CMap',
                   '/usr/local/Acrobat4/Resource/CMap',
-                  'C:\\Program Files\\Adobe\\Acrobat\\Resource\\CMap',
-                  'C:\\Program Files\\Adobe\\Acrobat 9.0\\Resource\\CMap',
-                  'C:\\Program Files\\Adobe\\Acrobat 8.0\\Resource\\CMap',
-                  'C:\\Program Files\\Adobe\\Acrobat 7.0\\Resource\\CMap',
-                  'C:\\Program Files\\Adobe\\Acrobat 6.0\\Resource\\CMap',
-                  'C:\\Program Files\\Adobe\\Acrobat 5.0\\Resource\\CMap',
-                  'C:\\Program Files\\Adobe\\Acrobat 4.0\\Resource\\CMap',
                   '%(REPORTLAB_DIR)s/fonts/CMap',       #special
                   '%(REPORTLAB_DIR)s/../fonts/CMap',    #special
                   '%(REPORTLAB_DIR)s/../../fonts/CMap', #special
                   '%(HOME)s/fonts/CMap',                #special
+                  '/usr/local/share/ghostscript/Resource/CMap',
                   )
 
 #### Normally don't need to edit below here ####
