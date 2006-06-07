$FreeBSD$

--- CastPodder.sh	Sat Apr 29 16:39:22 2006
+++ CastPodder.sh.port	Mon May  1 18:33:50 2006
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 #
 # Copyright 2005-2006 CastPodder Team
 #
@@ -18,5 +18,5 @@
 #
 # $Id: CastPodder.sh 68 2006-04-26 20:14:35Z sgrayban $
 
-cd /opt/CastPodder
+cd %%DATADIR%%
 python CastPodderGui.py
