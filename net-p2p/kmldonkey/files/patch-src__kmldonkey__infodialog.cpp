--- ./src/kmldonkey/infodialog.cpp.orig	Tue Jul 26 13:40:33 2005
+++ ./src/kmldonkey/infodialog.cpp	Sun Apr  9 13:15:40 2006
@@ -72,10 +72,20 @@
     layout->addWidget(makeLabel(i18n("Comment:"), frame), 6, 0);
     layout->addWidget(makeLabel(i18n("Alt. names:"), frame, true), 7, 0);
 
+    QHBoxLayout* l1 = new QHBoxLayout();
+
     nameView = new KLineEdit(fi->fileName(), frame, "nameView");
     nameView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
     nameView->setReadOnly(true);
-    layout->addWidget(nameView, 0, 1);
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
@@ -206,6 +216,7 @@
         return;
     }
     nameView->setText(fi->fileName());
+    fileNoView->setText(humanReadableFileNumber(fi->fileNo()));
     availView->update();
     sizeView->setText(humanReadableSize(fi->fileDownloaded()));
     totalSizeView->setText(humanReadableSize(fi->fileSize()));
