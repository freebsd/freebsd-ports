--- sudo.cpp.orig	2019-01-25 23:40:04 UTC
+++ sudo.cpp
@@ -38,7 +38,13 @@
 #include <QThread>
 #include <QProcessEnvironment>
 #include <QTimer>
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
@@ -56,6 +62,9 @@ namespace
 
     const QString su_prog{QStringLiteral(LXQTSUDO_SU)};
     const QString sudo_prog{QStringLiteral(LXQTSUDO_SUDO)};
+#ifdef __FreeBSD__
+    const QString pwd_prompt_end_c_locale{QStringLiteral(":")};
+#endif
     const QString pwd_prompt_end{QStringLiteral(": ")};
     const QChar nl{QLatin1Char('\n')};
 
@@ -240,27 +249,39 @@ QString Sudo::backendName (backend_t backEnd)
 void Sudo::child()
 {
     int params_cnt = 3 //1. su/sudo & "shell command" & last nullptr
+#ifndef __FreeBSD__
         + (BACK_SU == mBackend ? 1 : 3); //-c for su | -E /bin/sh -c for sudo
+#else
+      + (BACK_SU == mBackend ? 3 : 3);
+#endif
     std::unique_ptr<char const *[]> params{new char const *[params_cnt]};
     const char ** param_arg = params.get() + 1;
 
     std::string program = backendName().toLocal8Bit().data();
+    if (BACK_SU == mBackend)
+    {
+        *(param_arg++) = "-m";
+        *(param_arg++) = "root";
+        *(param_arg++) = "-c";
+    }
     if (BACK_SUDO == mBackend)
     {
+
         *(param_arg++) = "-E"; //preserve environment
         *(param_arg++) = "/bin/sh";
+        *(param_arg++) = "-c"; //run command
     }
-    *(param_arg++) = "-c"; //run command
 
     params[0] = program.c_str();
-
     // Note: we force the su/sudo to communicate with us in the simplest
     // locale and then set the locale back for the command
-    char const * const env_lc_all = getenv("LC_ALL");
+
     std::string command;
+#ifndef __FreeBSD__
+    char const * const env_lc_all = getenv("LC_ALL");
     if (env_lc_all == nullptr)
     {
-        command = "unset LC_ALL; ";
+        command = "unset LC_ALL;";
     } else
     {
         // Note: we need to check if someone is not trying to inject commands
@@ -276,6 +297,9 @@ void Sudo::child()
     }
     command += "exec ";
     command += squashedArgs().toLocal8Bit().data();
+#else
+    command = squashedArgs().toLocal8Bit().data();
+#endif
     *(param_arg++) = command.c_str();
 
     *param_arg = nullptr;
@@ -283,12 +307,11 @@ void Sudo::child()
     setenv("LC_ALL", "C", 1);
 
     env_workarounds();
-
     setsid(); //session leader
     execvp(params[0], const_cast<char **>(params.get()));
-
     //exec never returns in case of success
     QTextStream{stderr, QIODevice::WriteOnly} << tr("%1: Failed to exec '%2': %3\n").arg(app_master).arg(params[0]).arg(strerror(errno));
+
     exit(1);
 }
 
@@ -354,7 +377,11 @@ int Sudo::parent()
                 }
             } else
             {
+#ifdef __FreeBSD__
+                if( line.endsWith(pwd_prompt_end_c_locale)  || line.endsWith(pwd_prompt_end))
+#else
                 if (line.endsWith(pwd_prompt_end))
+#endif
                 {
                     //if now echo is turned off, su/sudo requests password
                     struct termios tios;
