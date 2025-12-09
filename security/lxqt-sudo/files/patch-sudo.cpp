--- sudo.cpp.orig	2025-11-05 12:14:34 UTC
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
@@ -65,6 +65,9 @@ namespace
 
     const QString su_prog{QStringLiteral(LXQTSUDO_SU)};
     const QString sudo_prog{QStringLiteral(LXQTSUDO_SUDO)};
+#ifdef __FreeBSD__
+    const QString pwd_prompt_end_c_locale{QStringLiteral(":")};
+#endif
     const QString doas_prog{QStringLiteral(LXQTSUDO_DOAS)};
     const QString pwd_prompt_end{QStringLiteral(": ")};
     const QChar nl{QLatin1Char('\n')};
@@ -272,7 +275,7 @@ void Sudo::child()
     switch (mBackend)
     {
         case BACK_SU:
-            params_cnt += 1; // -c for su
+            params_cnt += 3; // -m root -c for su
             break;
         case BACK_SUDO:
             params_cnt += 3; // --preserve-env=... /bin/sh -c for sudo
@@ -302,8 +305,10 @@ void Sudo::child()
             break;
         case BACK_DOAS:
             *(param_arg++) = "/bin/sh";
-            [[fallthrough]];
+            break;
         case BACK_SU:
+           *(param_arg++) = "-m";
+           *(param_arg++) = "root";
         case BACK_NONE:
             env_workarounds(mQuiet);
             break;
@@ -414,7 +419,8 @@ int Sudo::parent()
                 }
             } else
             {
-                if (line.endsWith(pwd_prompt_end))
+                if(line.endsWith(pwd_prompt_end_c_locale)  || line.endsWith(pwd_prompt_end))
+
                 {
                     //if now echo is turned off, su/sudo requests password
                     struct termios tios;
