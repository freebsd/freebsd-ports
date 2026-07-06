--- src/message-poller.cpp.orig	2026-04-08 07:07:55 UTC
+++ src/message-poller.cpp
@@ -1,6 +1,8 @@
 #include <QTimer>
 #include <QDateTime>
 #include <QJsonDocument>
+#include <QJsonValue>
+#include <QRegularExpression>
 
 #include "utils/utils.h"
 #include "utils/translate-commit-desc.h"
