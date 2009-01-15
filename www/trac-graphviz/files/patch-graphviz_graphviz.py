
$FreeBSD$

--- graphviz/graphviz.py.orig
+++ graphviz/graphviz.py
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
