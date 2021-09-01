From: Fabian Vogt <fvogt@suse.de>
Date: Wed, 7 Apr 2021 13:38:09 +0200
Subject: [PATCH] Remove invalid g_object declarations to fix build with glib
 >= 2.68

 g_object_ref_sink is defined as a macro meanwhile and so the build fails.
 Just remove the declarations, glib.h is included anyway.

Obtained from:

https://github.com/qtwebkit/qtwebkit/commit/5b698ba3faffd4e198a45be9fe74f53307395e4b.patch

--- Source/WTF/wtf/glib/GRefPtr.h.orig	2020-03-04 17:16:37 UTC
+++ Source/WTF/wtf/glib/GRefPtr.h
@@ -29,9 +29,6 @@
 #include <wtf/RefPtr.h>
 #include <algorithm>
 
-extern "C" void g_object_unref(gpointer);
-extern "C" gpointer g_object_ref_sink(gpointer);
-
 namespace WTF {
 
 enum GRefPtrAdoptType { GRefPtrAdopt };
