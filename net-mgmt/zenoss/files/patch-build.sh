$FreeBSD$

--- build.sh.orig	2011-02-08 08:07:00.000000000 -0800
+++ build.sh	2011-04-19 20:21:37.000000000 -0700
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/usr/bin/env bash
 
 ###############################################################################
 #
@@ -16,11 +16,5 @@
 . shared-functions.sh
 . build-functions.sh
 
-# gracefully handle Ctrl-C or other interrupts
-trap cleanup EXIT
-
 # build and install the software
 build
-
-# inform the user we're finished with the install
-get_happy
