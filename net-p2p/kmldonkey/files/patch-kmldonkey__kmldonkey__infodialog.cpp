--- ./kmldonkey/kmldonkey/infodialog.cpp.orig	2008-07-12 06:02:29.000000000 -0300
+++ ./kmldonkey/kmldonkey/infodialog.cpp	2008-07-12 06:04:27.000000000 -0300
@@ -72,10 +72,21 @@
     layout->addWidget(makeLabel(i18n("Comment:"), frame), 6, 0);
     layout->addWidget(makeLabel(i18n("Alt. names:"), frame, true), 7, 0);
 
+    QHBoxLayout* l1 = new QHBoxLayout();
+
     nameView = new KLineEdit(fi->fileName(), frame, "nameView");
     nameView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
     nameView->setReadOnly(true);
-    layout->addWidget(nameView, 0, 1);
+
+    l1->addWidget(nameView);
+
+    l1->addWidget(makeLabel(i18n("Number:"), frame));
+    fileNoView = new KLineEdit(humanReadableFileNumber(fi->fileNo()), frame, "fileNoView");
+    fileNoView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
+    fileNoView->setReadOnly(true);
+    l1->addWidget(fileNoView);
+
+    layout->addLayout(l1, 0, 1);
 
     availView = new AvailabilityWidget(fileno, frame, "availView");
     layout->addWidget(availView, 1, 1);
@@ -202,6 +213,7 @@
         return;
     }
     nameView->setText(fi->fileName());
+    fileNoView->setText(humanReadableFileNumber(fi->fileNo()));
     availView->update();
     sizeView->setText(humanReadableSize(fi->fileDownloaded()));
     totalSizeView->setText(humanReadableSize(fi->fileSize()));
