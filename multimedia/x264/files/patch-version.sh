--- version.sh.orig	2010-04-23 12:55:03.524324331 +0200
+++ version.sh	2010-04-23 12:54:56.084537002 +0200
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 git rev-list HEAD | sort > config.git-hash
 LOCALVER=`wc -l config.git-hash | awk '{print $1}'`
 if [ $LOCALVER \> 1 ] ; then
