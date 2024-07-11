Rename icon to prevent install conflicts with the Qt6 frontend.

--- qt5/main.cpp.orig	2024-07-03 09:19:19 UTC
+++ qt5/main.cpp
@@ -422,7 +422,7 @@ main(int argc, char *argv[])
         new_argc = argc;
         Q_ASSERT (new_argc);
         app = new QApplication(new_argc, new_argv);
-        app->setWindowIcon(QIcon(QLatin1String(":/icons/pinentry.png")));
+        app->setWindowIcon(QIcon(QLatin1String(":/icons/pinentry-qt5.png")));
         app->setDesktopFileName(QStringLiteral("org.gnupg.pinentry-qt5"));
         (void) new KeyboardFocusIndication{app};
     }
