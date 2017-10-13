--- net/instaweb/mod_pagespeed.gypi.orig	2017-10-06 10:03:15 UTC
+++ net/instaweb/mod_pagespeed.gypi
@@ -41,7 +41,12 @@
     '<(DEPTH)/pagespeed/apache/mod_instaweb.cc',
     '<(DEPTH)/pagespeed/kernel/base/mem_debug.cc',
   ],
+  'defines+': [
+    'USE_EXPAT',
+    'SHARED_MODULE',
+  ],
   'ldflags+': [
     '-Wl,--version-script=build/mod_pagespeed.map',
+    '-Wl,-Bshareable'
   ],
 }
