--- interface.tcl	Thu May 30 23:56:36 2002
+++ interface.tcl.new	Fri Feb 20 11:06:41 2004
@@ -1,4 +1,6 @@
-#!/usr/bin/wish
+#!/bin/sh
+# The next line restarts using %%WISH%% \
+exec %%WISH%% "$0"
 
 
 package require msgcat
