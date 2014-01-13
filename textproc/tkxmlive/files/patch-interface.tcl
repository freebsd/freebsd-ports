--- interface.tcl.orig	2002-05-30 23:56:36.000000000 +0200
+++ interface.tcl	2013-08-07 14:58:22.000000000 +0200
@@ -1,4 +1,6 @@
-#!/usr/bin/wish
+#!/bin/sh
+# The next line restarts using %%WISH%% \
+exec %%WISH%% "$0"
 
 
 package require msgcat
@@ -17,9 +19,11 @@
 source library/scrolled_text.tcl
 
 
-set mcDir [file join [file dirname [info script]] gui/msgs]
-msgcat::mcload $mcDir
-msgcat::mclocale $env(LANG)
+if {[info exists env(LANG)]} {
+  set mcDir [file join [file dirname [info script]] gui/msgs]
+  msgcat::mcload $mcDir
+  msgcat::mclocale $env(LANG)
+}
 
 proc SetResource { win } {
 
