Modify the explanation on the crashed lock screen to our situation.
That is, to use ck-unlock-session.

--- abstractlocker.cpp.orig	2017-09-14 11:49:05 UTC
+++ abstractlocker.cpp
@@ -51,11 +51,11 @@ void BackgroundWindow::paintEvent(QPaintEvent* )
     if (m_greeterFailure) {
         auto text = ki18n("The screen locker is broken and unlocking is not possible anymore.\n"
                           "In order to unlock switch to a virtual terminal (e.g. Ctrl+Alt+F2),\n"
-                          "log in and execute the command:\n\n"
-                          "loginctl unlock-session %1\n\n"
+                          "log in as root and execute the command:\n\n"
+                          "# ck-unlock-session <session-name>\n\n"
+                          "The <session-name> can be obtained by running the command:\n\n:"
+                          "# ck-unlock-session\n\n"
                           "Afterwards switch back to the running session (Ctrl+Alt+F%2).");
-        text = text.subs(QString::fromLocal8Bit(qgetenv("XDG_SESSION_ID")));
-        text = text.subs(QString::fromLocal8Bit(qgetenv("XDG_VTNR")));
         p.setPen(Qt::white);
         QFont f = p.font();
         f.setBold(true);
