Workaround for base GCC, which is too stupid to understand the declaration
below:

/wrkdirs/usr/ports/www/otter-browser/work/otter-browser-0.9.09/src/ui/CertificateDialog.h:66: error: expected ',' or '...' before '>' token
/wrkdirs/usr/ports/www/otter-browser/work/otter-browser-0.9.09/src/ui/CertificateDialog.h:66: error: wrong number of template arguments (1, should be 2)
/usr/local/include/qt5/QtCore/qcontainerfwd.h:46: error: provided for 'template<class Key, class T> class QMap'
/wrkdirs/usr/ports/www/otter-browser/work/otter-browser-0.9.09/src/ui/CertificateDialog.h:66: error: default argument missing for parameter 4 of 'QStandardItem* Otter::CertificateDialog::createField(Otter::CertificateDialog::CertificateField, QStandardItem*, const QMap<int, QVariant>&, QVariant)'
/wrkdirs/usr/ports/www/otter-browser/work/otter-browser-0.9.09/src/ui/CertificateDialog.cpp:388: error: prototype for 'QStandardItem* Otter::CertificateDialog::createField(Otter::CertificateDialog::CertificateField, QStandardItem*, const QMap<int, QVariant>&)' does not match any in class 'Otter::CertificateDialog'
/wrkdirs/usr/ports/www/otter-browser/work/otter-browser-0.9.09/src/ui/CertificateDialog.h:66: error: candidate is: QStandardItem* Otter::CertificateDialog::createField(Otter::CertificateDialog::CertificateField, QStandardItem*, const QMap<int, QVariant>&, QVariant)
--- src/ui/CertificateDialog.h.orig	2016-01-11 10:50:08 UTC
+++ src/ui/CertificateDialog.h
@@ -63,7 +63,7 @@ public:
 
 protected:
 	void changeEvent(QEvent *event);
-	QStandardItem* createField(CertificateField field, QStandardItem *parent = NULL, const QMap<int, QVariant> &data = QMap<int, QVariant>());
+	QStandardItem* createField(CertificateField field, QStandardItem *parent = NULL, const QMap<int, QVariant> &data = (QMap<int, QVariant>()));
 	QString formatHex(const QString &source, const QChar &separator = QLatin1Char(' '));
 
 protected slots:
