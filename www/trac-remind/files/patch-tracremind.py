--- tracremind.py.orig	Sat Jan 20 01:33:00 2007
+++ tracremind.py	Fri May 18 20:13:23 2007
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#!%%PYTHON%%
 
 import os
 import sys
@@ -107,7 +107,7 @@
 if __name__ == '__main__':
    # Default config file
    #
-   configfile = '/etc/tracremind.conf'
+   configfile = '%%PREFIX%%/etc/tracremind.conf'
    project = ''
    component = ''
    ENABLE_SYSLOG = 0
