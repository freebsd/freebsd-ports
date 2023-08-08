--- src/pimcommontexttranslator/translator/widgets/translatordebugdialog.cpp.orig	2023-02-18 09:58:32 UTC
+++ src/pimcommontexttranslator/translator/widgets/translatordebugdialog.cpp
@@ -7,6 +7,7 @@
 #include "translatordebugdialog.h"
 #include <QPlainTextEdit>
 
+#include <cerrno>
 #include <KConfigGroup>
 #include <KLocalizedString>
 #include <KMessageBox>
