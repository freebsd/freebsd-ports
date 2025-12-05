Add missing header for Qt 6.10

--- rkward/autotests/core_test.cpp.orig	2025-10-01 11:59:03 UTC
+++ rkward/autotests/core_test.cpp
@@ -9,6 +9,7 @@ SPDX-License-Identifier: GPL-2.0-or-later
 #include <QApplication>
 #include <QButtonGroup>
 #include <QDir>
+#include <QElapsedTimer>
 #include <QFile>
 #include <QLoggingCategory>
 #include <QObject>
