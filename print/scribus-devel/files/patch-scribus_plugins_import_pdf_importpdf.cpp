--- scribus/plugins/import/pdf/importpdf.cpp.orig	2020-03-15 14:15:45 UTC
+++ scribus/plugins/import/pdf/importpdf.cpp
@@ -75,7 +75,7 @@ PdfPlug::PdfPlug(ScribusDoc* doc, int flags)
 QImage PdfPlug::readThumbnail(const QString& fName)
 {
 	QString pdfFile = QDir::toNativeSeparators(fName);
-	globalParams = new GlobalParams();
+	globalParams.reset(new GlobalParams());
 	if (globalParams)
 	{
 #if defined(Q_OS_WIN32) && POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 62, 0)
@@ -90,7 +90,6 @@ QImage PdfPlug::readThumbnail(const QString& fName)
 			if (pdfDoc->getErrorCode() == errEncrypted)
 			{
 				delete pdfDoc;
-				delete globalParams;
 				return QImage();
 			}
 			if (pdfDoc->isOk())
@@ -134,11 +133,9 @@ QImage PdfPlug::readThumbnail(const QString& fName)
 				image.setText("YSize", QString("%1").arg(h));
 				delete dev;
 				delete pdfDoc;
-				delete globalParams;
 				return image;
 			}
 			delete pdfDoc;
-			delete globalParams;
 		}
 	}
 	return QImage();
@@ -387,7 +384,7 @@ bool PdfPlug::convert(const QString& fn)
 		qApp->processEvents();
 	}
 
-	globalParams = new GlobalParams();
+	globalParams.reset(new GlobalParams());
 	GooString *userPW = nullptr;
 	if (globalParams)
 	{
@@ -429,7 +426,6 @@ bool PdfPlug::convert(const QString& fn)
 					if (progressDialog)
 						progressDialog->close();
 					delete pdfDoc;
-					delete globalParams;
 					return false;
 				}
 				if (progressDialog)
@@ -474,7 +470,6 @@ bool PdfPlug::convert(const QString& fn)
 							progressDialog->close();
 						delete optImp;
 						delete pdfDoc;
-						delete globalParams;
 						return false;
 					}
 					pageString = optImp->getPagesString();
@@ -839,13 +834,13 @@ bool PdfPlug::convert(const QString& fn)
 								if (names.isDict())
 								{
 									LinkAction *linkAction = nullptr;
-									linkAction = LinkAction::parseAction(&names, pdfDoc->getCatalog()->getBaseURI());
+									linkAction = LinkAction::parseAction(&names, pdfDoc->getCatalog()->getBaseURI()).get();
 									if (linkAction)
 									{
 										LinkJavaScript *jsa = (LinkJavaScript*)linkAction;
 										if (jsa->isOk())
 										{
-											QString script = UnicodeParsedString(jsa->getScript());
+											QString script = QString::fromStdString(jsa->getScript());
 											if (script.startsWith("this."))
 											{
 												script.remove(0, 5);
@@ -908,7 +903,7 @@ bool PdfPlug::convert(const QString& fn)
 		}
 		delete pdfDoc;
 	}
-	delete globalParams;
+	globalParams.release();
 	globalParams = nullptr;
 
 //	qDebug() << "converting finished";
