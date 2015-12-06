--- Keyboard.cpp.orig	2015-10-24 12:09:14 UTC
+++ Keyboard.cpp
@@ -23,7 +23,6 @@ Keyboard::Keyboard() 
     new_termios = orig_termios;
     new_termios.c_lflag &= ~(ICANON | ECHO | ECHOCTL | ECHONL);
     new_termios.c_cflag |= HUPCL;
-    new_termios.c_cc[VMIN] = 0;
 
     tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
   } 
@@ -74,13 +73,20 @@ void Keyboard::restore_term() 
   }
 }
 
-void Keyboard::Sleep(unsigned int dwMilliSeconds)
+int Keyboard::Hit()
 {
-  struct timespec req;
-  req.tv_sec = dwMilliSeconds / 1000;
-  req.tv_nsec = (dwMilliSeconds % 1000) * 1000000;
+  struct timeval timeo;
+  fd_set fds;
 
-  while ( nanosleep(&req, &req) == -1 && errno == EINTR && (req.tv_nsec > 0 || req.tv_sec > 0));
+  timeo.tv_sec = 0;
+  timeo.tv_usec = 200000;
+
+  FD_ZERO(&fds);
+  FD_SET(STDIN_FILENO, &fds);
+
+  select(FD_SETSIZE, &fds, NULL, NULL, &timeo);
+
+  return FD_ISSET(STDIN_FILENO, &fds);
 }
 
 void Keyboard::Process() 
@@ -90,9 +96,16 @@ void Keyboard::Process() 
     if (conn)
       dbus_connection_read_write_dispatch(conn, 0);
     int ch[8];
-    int chnum = 0;
+    int chnum, nb;
 
-    while ((ch[chnum] = getchar()) != EOF) chnum++;
+    if (Hit() == 0)
+      continue;
+
+    ioctl(STDIN_FILENO, FIONREAD, &nb);
+
+    for (chnum = 0; chnum < nb && chnum < 8; chnum++) {
+      ch[chnum] = getchar();
+    }
 
     if (chnum > 1) ch[0] = ch[chnum - 1] | (ch[chnum - 2] << 8);
 
@@ -101,8 +114,6 @@ void Keyboard::Process() 
 
     if (m_keymap[ch[0]] != 0)
           send_action(m_keymap[ch[0]]);
-    else
-      Sleep(20);
   }
 }
 
