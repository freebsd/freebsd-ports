--- chrome/browser/resources/sandbox_internals/sandbox_internals.ts.orig	2022-07-22 17:30:31 UTC
+++ chrome/browser/resources/sandbox_internals/sandbox_internals.ts
@@ -2,7 +2,7 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
-// <if expr="is_linux or chromeos_ash or chromeos_lacros">
+// <if expr="is_posix or chromeos_ash or chromeos_lacros">
 import './strings.m.js';
 
 import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
@@ -121,7 +121,7 @@ function androidHandler() {
 }
 // </if>
 
-// <if expr="is_linux or chromeos_ash or chromeos_lacros">
+// <if expr="is_posix or chromeos_ash or chromeos_lacros">
 
 /**
  * Adds a status row that reports either Yes or No.
@@ -182,7 +182,7 @@ document.addEventListener('DOMContentLoaded', () => {
   // <if expr="is_android">
   androidHandler();
   // </if>
-  // <if expr="is_linux or chromeos_ash or chromeos_lacros">
+  // <if expr="is_posix or chromeos_ash or chromeos_lacros">
   linuxHandler();
   // </if>
 });
