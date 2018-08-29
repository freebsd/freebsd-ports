--- sudo.cpp.orig	2018-05-21 19:10:17 UTC
+++ sudo.cpp
@@ -36,7 +36,13 @@
 #include <QSocketNotifier>
 #include <QDebug>
 #include <QThread>
+#if defined(__linux__)
 #include <pty.h>
+#elif defined(__FreeBSD__)
+#include <libutil.h>
+#include <errno.h>
+#include <termios.h>
+#endif
 #include <unistd.h>
 #include <memory>
 #include <csignal>
@@ -52,6 +58,9 @@ namespace
 
     const QString su_prog{QStringLiteral(LXQTSUDO_SU)};
     const QString sudo_prog{QStringLiteral(LXQTSUDO_SUDO)};
+#ifdef __FreeBSD__
+    const QString pwd_prompt_end_c_locale{QStringLiteral(":")};
+#endif
     const QString pwd_prompt_end{QStringLiteral(": ")};
     const QChar nl{QLatin1Char('\n')};
 
@@ -179,6 +188,10 @@ void Sudo::child()
     if (BACK_SU == mBackend)
     {
         program = su_prog.toStdString();
+#ifdef __FreeBSD__
+		*(param_arg++) = "-m";
+		*(param_arg++) = "root";
+#endif
         *(param_arg++) = "-c"; //run command
     } else
     {
@@ -200,7 +213,6 @@ void Sudo::child()
 
     setsid(); //session leader
     execvp(params[0], const_cast<char **>(params.get()));
-
     //exec never returns in case of success
     QTextStream{stderr, QIODevice::WriteOnly} << tr("%1: Failed to exec '%2': %3\n").arg(app_master).arg(params[0]).arg(strerror(errno));
     exit(1);
@@ -277,8 +289,13 @@ int Sudo::parent()
                 lxqtApp->quit();
             } else
             {
-                if (line.endsWith(pwd_prompt_end))
+#ifdef __FreeBSD__
+                if( line.endsWith(pwd_prompt_end_c_locale)  || line.endsWith(pwd_prompt_end))
+#else
+                if(line.endsWith(pwd_prompt_end))
+#endif
                 {
+
                     //if now echo is turned off, su/sudo requests password
                     struct termios tios;
                     //loop to be sure we don't miss the flag (we can afford such small delay in "normal" output processing)
