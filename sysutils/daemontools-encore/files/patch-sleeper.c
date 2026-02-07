--- sleeper.c.orig	2018-10-14 00:48:50 UTC
+++ sleeper.c
@@ -11,16 +11,16 @@ static void catch_sig(int sig)
   int ignored;
   int i;
   switch (sig) {
-  case SIGALRM: name = "ALRM"; break;
-  case SIGCONT: name = "CONT"; break;
-  case SIGHUP: name = "HUP"; break;
-  case SIGINT: name = "INT"; break;
-  case SIGQUIT: name = "QUIT"; break;
-  case SIGTERM: name = "TERM"; break;
-  case SIGUSR1: name = "USR1"; break;
-  case SIGUSR2: name = "USR2"; break;
-  case SIGWINCH: name = "WINCH"; break;
-  default: name = "unknown signal";
+  case SIGALRM: name = "Caught ALRM\n"; break;
+  case SIGCONT: name = "Caught CONT\n"; break;
+  case SIGHUP: name = "Caught HUP\n"; break;
+  case SIGINT: name = "Caught INT\n"; break;
+  case SIGQUIT: name = "Caught QUIT\n"; break;
+  case SIGTERM: name = "Caught TERM\n"; break;
+  case SIGUSR1: name = "Caught USR1\n"; break;
+  case SIGUSR2: name = "Caught USR2\n"; break;
+  case SIGWINCH: name = "Caught WINCH\n"; break;
+  default: name = "unknown signal\n";
   }
   i = str_len(name);
   byte_copy(buf+7,i,name);
