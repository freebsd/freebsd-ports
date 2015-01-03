From 800282f289e3ebeb2873f7914ed560282b482448 Mon Sep 17 00:00:00 2001
From: "Marcus D. Hanwell" <marcus.hanwell@kitware.com>
Date: Tue, 9 Sep 2014 13:39:13 -0400
Subject: [PATCH] Actually define GLX_GLXEXT_LEGACY to prevent the include

Change-Id: I394afaf8a550f5c7b06ceca0898c316e5f2568c9

--- Rendering/vtkXOpenGLRenderWindow.cxx.orig	2012-10-15 20:33:21 UTC
+++ Rendering/vtkXOpenGLRenderWindow.cxx
@@ -25,9 +25,9 @@
 
 #include "vtkOpenGL.h"
 
-// define GLX_GLXEXT_LEGACY to prevent glx.h to include glxext.h provided by
-// the system
-//#define GLX_GLXEXT_LEGACY
+// Define GLX_GLXEXT_LEGACY to prevent glx.h from including the glxext.h
+// provided by the system.
+#define GLX_GLXEXT_LEGACY
 #include "GL/glx.h"
 
 #include "vtkgl.h"
