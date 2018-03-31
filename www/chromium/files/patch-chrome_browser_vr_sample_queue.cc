--- chrome/browser/vr/sample_queue.cc.orig	2018-03-24 12:29:50.123017000 +0100
+++ chrome/browser/vr/sample_queue.cc	2018-03-24 12:30:25.632912000 +0100
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#include <stdint.h>
+
 #include "chrome/browser/vr/sample_queue.h"
 
 namespace vr {
