--- connections/connectionwindow.cpp.orig	2022-10-01 20:28:59 UTC
+++ connections/connectionwindow.cpp
@@ -62,6 +62,7 @@ ConnectionWindow::ConnectionWindow(QWidget *parent) :
     connect(ui->btnMoveUp, &QPushButton::clicked, this, &ConnectionWindow::moveConnUp);
     connect(ui->btnMoveDown, &QPushButton::clicked, this, &ConnectionWindow::moveConnDown);
 
+    ui->cbBusSpeed->addItem("33333");
     ui->cbBusSpeed->addItem("50000");
     ui->cbBusSpeed->addItem("100000");
     ui->cbBusSpeed->addItem("125000");
