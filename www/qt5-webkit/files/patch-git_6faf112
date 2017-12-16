From 6faf11215e1af27d35e921ae669aa0251a01a1ab Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Michael=20Br=C3=BCning?= <michael.bruning@digia.com>
Date: Wed, 13 Nov 2013 18:13:36 +0100
Subject: [PATCH] Trigger layout after resizing the FrameView.

There are problems with QGLWidget based web plugins due to the fact
that WebKit forces us to relayout during paint events, which in turn
might resize widgets, causing the shared backing store's QImages to
be corrupted and hence causing crashed.

This patch triggers a layout upon resizing the FrameView, which reduces
the likely hood of resizing plugins during a subsequent paintEvent.

Task-number: QTBUG-34277
Change-Id: Id35c72a3cc68ac6633a74fba0669c2d8fbfabc88
Reviewed-by: Allan Sandfeld Jensen <allan.jensen@digia.com>
---
 Source/WebKit/qt/WebCoreSupport/QWebFrameAdapter.cpp | 3 +++
 1 file changed, 3 insertions(+)

diff --git a/Source/WebKit/qt/WebCoreSupport/QWebFrameAdapter.cpp b/Source/WebKit/qt/WebCoreSupport/QWebFrameAdapter.cpp
index e6145b6ffb82..941d8df603d9 100644
--- Source/WebKit/qt/WebCoreSupport/QWebFrameAdapter.cpp
+++ Source/WebKit/qt/WebCoreSupport/QWebFrameAdapter.cpp
@@ -962,6 +962,9 @@ void QWebFrameAdapter::setViewportSize(const QSize& size)
     ASSERT(view);
     view->resize(size);
     view->adjustViewSize();
+
+    if (view->needsLayout())
+        view->layout();
 }
 
 
