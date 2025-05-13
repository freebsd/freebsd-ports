--- screen.c.orig	2023-08-16 00:29:26 UTC
+++ screen.c
@@ -230,8 +230,6 @@ int multiattach;
 int multi_uid;
 int own_uid;
 int multiattach;
-int tty_mode;
-int tty_oldmode = -1;
 #endif
 
 char HostName[MAXSTR];
@@ -1009,9 +1007,6 @@ int main(int ac, char** av)
 
     /* ttyname implies isatty */
     SetTtyname(true, &st);
-#ifdef MULTIUSER
-    tty_mode = (int)st.st_mode & 0777;
-#endif
 
     fl = fcntl(0, F_GETFL, 0);
     if (fl != -1 && (fl & (O_RDWR|O_RDONLY|O_WRONLY)) == O_RDWR)
@@ -1127,15 +1122,28 @@ int main(int ac, char** av)
 #endif
   }
 
-  if (stat(SockPath, &st) == -1)
-    Panic(errno, "Cannot access %s", SockPath);
-  else
-    if (!S_ISDIR(st.st_mode))
+  if (stat(SockPath, &st) == -1) {
+    if (eff_uid == real_uid) {
+      Panic(errno, "Cannot access %s", SockPath);
+    } else {
+      Panic(0, "Error accessing %s", SockPath);
+    }
+  } else if (!S_ISDIR(st.st_mode)) {
+    if (eff_uid == real_uid || st.st_uid == real_uid) {
       Panic(0, "%s is not a directory.", SockPath);
+    } else {
+      Panic(0, "Error accessing %s", SockPath);
+    }
+  }
 #ifdef MULTIUSER
   if (multi) {
-    if ((int)st.st_uid != multi_uid)
-      Panic(0, "%s is not the owner of %s.", multi, SockPath);
+    if ((int)st.st_uid != multi_uid) {
+      if (eff_uid == real_uid || st.st_uid == real_uid) {
+        Panic(0, "%s is not the owner of %s.", multi, SockPath);
+      } else {
+        Panic(0, "Error accessing %s", SockPath);
+      }
+    }
   }
   else
 #endif
@@ -1149,9 +1157,13 @@ int main(int ac, char** av)
       Panic(0, "You are not the owner of %s.", SockPath);
 #endif
   }
-
-  if ((st.st_mode & 0777) != 0700)
-    Panic(0, "Directory %s must have mode 700.", SockPath);
+  if ((st.st_mode & 0777) != 0700) {
+    if (eff_uid == real_uid || st.st_uid == real_uid) {
+      Panic(0, "Directory %s must have mode 700.", SockPath);
+    } else {
+      Panic(0, "Error accessing %s", SockPath);
+    }
+  }
   if (SockMatch && index(SockMatch, '/'))
     Panic(0, "Bad session name '%s'", SockMatch);
   SockName = SockPath + strlen(SockPath) + 1;
@@ -1189,8 +1201,14 @@ int main(int ac, char** av)
       else
         exit(9 + (fo || oth ? 1 : 0) + fo);
     }
-    if (fo == 0)
-      Panic(0, "No Sockets found in %s.\n", SockPath);
+    if (fo == 0) {
+      if (eff_uid == real_uid || st.st_uid == real_uid) {
+        Panic(0, "No Sockets found in %s.\n", SockPath);
+      } else {
+        Panic(0, "Error accessing %s", SockPath);
+      }
+    }
+
     Msg(0, "%d Socket%s in %s.", fo, fo > 1 ? "s" : "", SockPath);
     eexit(0);
   }
@@ -2170,20 +2188,6 @@ DEFINE_VARARGS_FN(Panic)
       if (D_userpid)
         Kill(D_userpid, SIG_BYE);
     }
-#ifdef MULTIUSER
-  if (tty_oldmode >= 0) {
-
-# ifdef USE_SETEUID
-    if (setuid(own_uid))
-      xseteuid(own_uid);	/* may be a loop. sigh. */
-# else
-      setuid(own_uid);
-# endif
-
-    debug1("Panic: changing back modes from %s\n", attach_tty);
-    chmod(attach_tty, tty_oldmode);
-  }
-#endif
   eexit(1);
 }
 
@@ -2234,7 +2238,7 @@ static char *pad_expand(char *buf, char *p, int numpad
   pn2 = pn = p + padlen;
   r = winmsg_numrend;
   while (p >= buf) {
-    if (r && *p != 127 && p - buf == winmsg_rendpos[r - 1]) {
+    if (r && p - buf == winmsg_rendpos[r - 1]) {
       winmsg_rendpos[--r] = pn - buf;
       continue;
     }
