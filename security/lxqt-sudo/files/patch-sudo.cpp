--- sudo.cpp.orig	2020-04-23 18:44:01 UTC
+++ sudo.cpp
@@ -44,7 +44,7 @@
 #else
 #include <errno.h>
 #include <termios.h>
-#include <util.h>
+#include <libutil.h>
 #endif
 #include <unistd.h>
 #include <memory>
@@ -64,7 +64,11 @@ namespace
 
     const QString su_prog{QStringLiteral(LXQTSUDO_SU)};
     const QString sudo_prog{QStringLiteral(LXQTSUDO_SUDO)};
+#ifdef __FreeBSD__
+    const QString pwd_prompt_end_c_locale{QStringLiteral(":")};
+#endif
     const QString pwd_prompt_end{QStringLiteral(": ")};
+
     const QChar nl{QLatin1Char('\n')};
 
     void usage(QString const & err = QString())
@@ -270,6 +274,8 @@ void Sudo::child()
             *(param_arg++) = "/bin/sh";
             break;
         case BACK_SU:
+            *(param_arg++) = "-m";                                                                                                                                                            
+            *(param_arg++) = "root";
         case BACK_NONE:
             env_workarounds();
             break;
@@ -377,7 +383,12 @@ int Sudo::parent()
                 }
             } else
             {
+#ifdef __FreeBSD__
+                if( line.endsWith(pwd_prompt_end_c_locale)  || line.endsWith(pwd_prompt_end))
+#else
+
                 if (line.endsWith(pwd_prompt_end))
+#endif
                 {
                     //if now echo is turned off, su/sudo requests password
                     struct termios tios;
