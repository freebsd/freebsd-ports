--- reportlab/rl_config.py.orig	Thu Jul 25 04:56:34 2002
+++ reportlab/rl_config.py	Sat Aug 17 18:56:07 2002
@@ -18,29 +18,21 @@
 emptyTableAction=           'error'                 # one of 'error', 'indicate', 'ignore'
 
 # places to look for T1Font information
-T1SearchPath =  ('c:/Program Files/Adobe/Acrobat 5.0/Resource/Font', #Win32, Acrobat 5
-                 'c:/Program Files/Adobe/Acrobat 4.0/Resource/Font', #Win32, Acrobat 4
-                 '%(disk)s/Applications/Python %(sys_version)s/reportlab/fonts', #Mac?
-                 '/usr/lib/Acrobat5/Resource/Font', #Linux, Acrobat 5?
-                 '/usr/lib/Acrobat4/Resource/Font', #Linux, Acrobat 4
-                 '%(REPORTLAB_DIR)s/fonts' #special
-                 )
+T1SearchPath =  ('/usr/local/lib/Acrobat5/Resource/Font',
+		 '/usr/local/lib/Acrobat4/Resource/Font',
+		 '%(REPORTLAB_DIR)s/fonts' #special
+		)
 
 # places to look for TT Font information
-TTFSearchPath = (
-                'c:/winnt/fonts',
-                'c:/windows/fonts',
-                '/usr/lib/X11/fonts/TrueType/',
-                '%(REPORTLAB_DIR)s/fonts' #special
-                )
+TTFSearchPath = ('/usr/X11R6/lib/X11/fonts/TrueType/',
+		 '%(REPORTLAB_DIR)s/fonts' #special
+		)
 
 # places to look for CMap files - should ideally merge with above
 CMapSearchPath = ('/usr/local/Acrobat5/Resource/CMap',
-                  '/usr/local/Acrobat4/Resource/CMap',
-                  'C:\\Program Files\\Adobe\\Acrobat\\Resource\\CMap',
-                  'C:\\Program Files\\Adobe\\Acrobat 5.0\\Resource\\CMap',
-                  'C:\\Program Files\\Adobe\\Acrobat 4.0\\Resource\\CMap'
-                  )
+		  '/usr/local/Acrobat4/Resource/CMap',
+		  '/usr/local/share/ghostscript/Resource/CMap'
+		 )
 
 #### Normally don't need to edit below here ####
 import os, sys, string
