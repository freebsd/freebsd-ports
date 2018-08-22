--- Telegram/SourceFiles/_other/packer.cpp.orig	2018-08-04 18:53:40 UTC
+++ Telegram/SourceFiles/_other/packer.cpp
@@ -233,7 +233,7 @@ int main(int argc, char *argv[])
 			}
 			QByteArray inner = f.readAll();
 			stream << name << quint32(inner.size()) << inner;
-#if defined Q_OS_MAC || defined Q_OS_LINUX
+#if defined Q_OS_MAC || defined Q_OS_LINUX || defined Q_OS_FREEBSD
 			stream << (QFileInfo(fullName).isExecutable() ? true : false);
 #endif
 		}
