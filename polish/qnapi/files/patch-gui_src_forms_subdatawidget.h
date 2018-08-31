From 27bbaa5a32e5c6d9e45a6ba221928be6ec555ddd Mon Sep 17 00:00:00 2001
From: Luigi Baldoni <luigino@users.noreply.github.com>
Date: Mon, 11 Jun 2018 14:55:54 +0200
Subject: [PATCH] Add missing include statement for Qt 5.11 (#148)

--- gui/src/forms/subdatawidget.h.orig	2017-05-19 16:50:58 UTC
+++ gui/src/forms/subdatawidget.h
@@ -16,6 +16,7 @@
 #define SUBDATAWIDGET_H
 
 #include <QWidget>
+#include <QIcon>
 #include "ui_subDataWidget.h"
 
 class subDataWidget : public QWidget {
