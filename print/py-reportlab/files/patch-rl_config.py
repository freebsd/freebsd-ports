--- rl_config.py.orig	Wed Jan 21 17:33:01 2004
+++ rl_config.py	Mon Jan 26 11:57:15 2004
@@ -19,37 +19,22 @@
 eps_preview_transparent=    None                    #set to white etc
 
 # places to look for T1Font information
-T1SearchPath =  ('c:/Program Files/Adobe/Acrobat 6.0/Resource/Font', #Win32, Acrobat 6
-                'c:/Program Files/Adobe/Acrobat 5.0/Resource/Font', #Win32, Acrobat 5
-                 'c:/Program Files/Adobe/Acrobat 4.0/Resource/Font', #Win32, Acrobat 4
-                 '%(disk)s/Applications/Python %(sys_version)s/reportlab/fonts', #Mac?
-                 '/usr/lib/Acrobat5/Resource/Font', #Linux, Acrobat 5?
-                 '/usr/lib/Acrobat4/Resource/Font', #Linux, Acrobat 4
-                 '/usr/local/Acrobat6/Resource/Font', #Linux, Acrobat 5?
-                 '/usr/local/Acrobat5/Resource/Font', #Linux, Acrobat 5?
-                 '/usr/local/Acrobat4/Resource/Font', #Linux, Acrobat 4
-                 '%(REPORTLAB_DIR)s/fonts' #special
+T1SearchPath =  ('/usr/local/Acrobat6/Resource/Font',
+                 '/usr/local/Acrobat5/Resource/Font',
+                 '/usr/local/Acrobat4/Resource/Font',
+                  '%(REPORTLAB_DIR)s/fonts' #special
                  )
 
 # places to look for TT Font information
-TTFSearchPath = (
-                'c:/winnt/fonts',
-                'c:/windows/fonts',
-                '/usr/lib/X11/fonts/TrueType/',
-                '%(REPORTLAB_DIR)s/fonts' #special
+TTFSearchPath = ('/usr/X11R6/lib/X11/fonts/TrueType/',
+                '%(REPORTLAB_DIR)s/fonts' #special
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
+		  '/usr/local/share/ghostscript/Resource/CMap'
                   )
 
 #### Normally don't need to edit below here ####
