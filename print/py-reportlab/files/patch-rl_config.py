--- rl_config.py.orig	Wed Nov 10 00:09:28 2004
+++ rl_config.py	Mon Mar 21 03:24:22 2005
@@ -22,15 +22,9 @@
 
 # places to look for T1Font information
 T1SearchPath =  (
-                'c:/Program Files/Adobe/Acrobat 6.0/Resource/Font', #Win32, Acrobat 6
-                'c:/Program Files/Adobe/Acrobat 5.0/Resource/Font',     #Win32, Acrobat 5
-                'c:/Program Files/Adobe/Acrobat 4.0/Resource/Font', #Win32, Acrobat 4
-                '%(disk)s/Applications/Python %(sys_version)s/reportlab/fonts', #Mac?
-                '/usr/lib/Acrobat5/Resource/Font',      #Linux, Acrobat 5?
-                '/usr/lib/Acrobat4/Resource/Font',      #Linux, Acrobat 4
-                '/usr/local/Acrobat6/Resource/Font',    #Linux, Acrobat 5?
-                '/usr/local/Acrobat5/Resource/Font',    #Linux, Acrobat 5?
-                '/usr/local/Acrobat4/Resource/Font',    #Linux, Acrobat 4
+                '/usr/local/Acrobat6/Resource/Font',
+                '/usr/local/Acrobat5/Resource/Font',
+                '/usr/local/Acrobat4/Resource/Font',
                 '%(REPORTLAB_DIR)s/fonts',              #special
                 '%(REPORTLAB_DIR)s/../fonts',           #special
                 '%(REPORTLAB_DIR)s/../../fonts',        #special
@@ -39,9 +33,7 @@
 
 # places to look for TT Font information
 TTFSearchPath = (
-                'c:/winnt/fonts',
-                'c:/windows/fonts',
-                '/usr/lib/X11/fonts/TrueType/',
+                '/usr/X11R6/lib/X11/fonts/TrueType/',
                 '%(REPORTLAB_DIR)s/fonts',      #special
                 '%(REPORTLAB_DIR)s/../fonts',   #special
                 '%(REPORTLAB_DIR)s/../../fonts',#special
@@ -49,20 +41,14 @@
                 )
 
 # places to look for CMap files - should ideally merge with above
-CMapSearchPath = ('/usr/lib/Acrobat6/Resource/CMap',
-                  '/usr/lib/Acrobat5/Resource/CMap',
-                  '/usr/lib/Acrobat4/Resource/CMap',
-                  '/usr/local/Acrobat6/Resource/CMap',
+CMapSearchPath = ('/usr/local/Acrobat6/Resource/CMap',
                   '/usr/local/Acrobat5/Resource/CMap',
                   '/usr/local/Acrobat4/Resource/CMap',
-                  'C:\\Program Files\\Adobe\\Acrobat\\Resource\\CMap',
-                  'C:\\Program Files\\Adobe\\Acrobat 6.0\\Resource\\CMap',
-                  'C:\\Program Files\\Adobe\\Acrobat 5.0\\Resource\\CMap',
-                  'C:\\Program Files\\Adobe\\Acrobat 4.0\\Resource\\CMap'
                   '%(REPORTLAB_DIR)s/fonts/CMap',       #special
                   '%(REPORTLAB_DIR)s/../fonts/CMap',    #special
                   '%(REPORTLAB_DIR)s/../../fonts/CMap', #special
                   '%(HOME)s/fonts/CMap',                #special
+                  '/usr/local/share/ghostscript/Resource/CMap',
                   )
 
 #### Normally don't need to edit below here ####
