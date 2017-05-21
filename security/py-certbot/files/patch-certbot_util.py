From 42d07d756df0cf96c9d20b44e772858391d48384 Mon Sep 17 00:00:00 2001
From: Ryan Pineo <ry@tsl.io>
Date: Fri, 12 May 2017 15:45:54 -0400
Subject: [PATCH] support version 0.12.0 of configargparse

fixes #4648

--- certbot/util.py.orig	2017-05-16 07:21:46 UTC
+++ certbot/util.py
@@ -437,7 +437,12 @@ def add_deprecated_argument(add_argument
             sys.stderr.write(
                 "Use of {0} is deprecated.\n".format(option_string))
 
-    configargparse.ACTION_TYPES_THAT_DONT_NEED_A_VALUE.add(ShowWarning)
+    # In version 0.12.0 ACTION_TYPES_THAT_DONT_NEED_A_VALUE was changed from a set
+    # to a tuple.
+    if isinstance(configargparse.ACTION_TYPES_THAT_DONT_NEED_A_VALUE, set):
+        configargparse.ACTION_TYPES_THAT_DONT_NEED_A_VALUE.add(ShowWarning)
+    else:
+        configargparse.ACTION_TYPES_THAT_DONT_NEED_A_VALUE += (ShowWarning,)
     add_argument(argument_name, action=ShowWarning,
                  help=argparse.SUPPRESS, nargs=nargs)
 
