--- ./build/linux/python_arch.sh.orig	2010-12-16 02:11:47.000000000 +0100
+++ ./build/linux/python_arch.sh	2010-12-20 20:15:08.000000000 +0100
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/usr/bin/env bash
 # Copyright (c) 2010 The Chromium Authors. All rights reserved.
 # Use of this source code is governed by a BSD-style license that can be
 # found in the LICENSE file.
@@ -10,12 +10,7 @@
 #  python_arch.sh /path/to/sysroot/usr/lib/libpython2.4.so.1.0
 #
 
-python=$(readlink -f "$1")
-if [ ! -r "$python" ]; then
-  echo unknown
-  exit 0;
-fi
-file_out=$(file "$python")
+file_out=$(file "$1")
 if [ $? -ne 0 ]; then
   echo unknown
   exit 0;
