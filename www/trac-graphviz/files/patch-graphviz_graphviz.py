
$FreeBSD$

--- graphviz/graphviz.py.orig
+++ graphviz/graphviz.py
@@ -16,11 +16,11 @@
 __version__   = '0.7.2'
 
 
+import hashlib
 import inspect
 import locale
 import os
 import re
-import sha
 import subprocess
 import sys
 
@@ -59,10 +59,7 @@
                      'c:\\Program Files\\ATT\\Graphviz\\bin',
                      ],
         
-        'freebsd6': ['/usr/local/bin',
-                     ],
-        
-        'freebsd5': ['/usr/local/bin',
+        'freebsd%%OSMAJOR%%': ['%%LOCALBASE%%/bin',
                      ],
         
         'darwin':   ['/opt/local/bin',
@@ -312,7 +309,7 @@
         encoded_cmd = (processor + unicode(self.processor_options)) \
                 .encode(self.encoding)
         encoded_content = content.encode(self.encoding)
-        sha_key  = sha.new(encoded_cmd + encoded_content).hexdigest()
+        sha_key  = hashlib.sha1(encoded_cmd + encoded_content).hexdigest()
         img_name = '%s.%s.%s' % (sha_key, processor, out_format)
         # cache: hash.<dot>.<png>
         img_path = os.path.join(self.cache_dir, img_name)
