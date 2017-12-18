--- Telegram/SourceFiles/_other/packer.cpp.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/_other/packer.cpp
@@ -246,7 +246,7 @@ int main(int argc, char *argv[])
 			}
 			QByteArray inner = f.readAll();
 			stream << name << quint32(inner.size()) << inner;
-#if defined Q_OS_MAC || defined Q_OS_LINUX
+#if defined Q_OS_MAC || defined Q_OS_LINUX || defined Q_OS_FREEBSD
 			stream << (QFileInfo(fullName).isExecutable() ? true : false);
 #endif
 		}
