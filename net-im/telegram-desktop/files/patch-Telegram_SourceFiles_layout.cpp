--- Telegram/SourceFiles/layout.cpp.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/layout.cpp
@@ -264,16 +264,16 @@ bool documentIsExecutableName(const QStr
 		*result = qsl("\
 action app bin command csh osx workflow\
 ").split(' ');
-#elif defined Q_OS_LINUX // Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_MAC
 		*result = qsl("\
 bin csh ksh out run\
 ").split(' ');
-#else // Q_OS_MAC || Q_OS_LINUX
+#else // Q_OS_MAC || Q_OS_LINUX || Q_OS_FREEBSD
 		*result = qsl("\
 bat bin cmd com cpl exe gadget inf ins inx isu job jse lnk msc msi \
 msp mst paf pif ps1 reg rgs sct shb shs u3p vb vbe vbs vbscript ws wsf\
 ").split(' ');
-#endif // !Q_OS_MAC && !Q_OS_LINUX
+#endif // !Q_OS_MAC && !Q_OS_LINUX && ! Q_OS_FREEBSD
 		return result.release();
 	})());
 
