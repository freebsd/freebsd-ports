--- ./lib/Application.vala.orig	2014-03-18 20:51:49.000000000 +0000
+++ ./lib/Application.vala	2014-05-29 09:42:26.000000000 +0000
@@ -69,6 +69,8 @@
         public Application () {
 #if LINUX
             prctl (15, exec_name, 0, 0, 0);
+#elif DragonFly || FreeBSD || NetBSD || OpenBSD
+            setproctitle (exec_name);
 #endif
             Environment.set_prgname (exec_name);
 
@@ -90,6 +92,12 @@
 #if LINUX
         [CCode (cheader_filename = "sys/prctl.h", cname = "prctl")]
             protected extern static int prctl (int option, string arg2, ulong arg3, ulong arg4, ulong arg5);
+#elif DragonFly || FreeBSD
+        [CCode (cheader_filename = "unistd.h", cname = "setproctitle")]
+            protected extern static void setproctitle (string fmt, ...);
+#elif NetBSD || OpenBSD
+        [CCode (cheader_filename = "stdlib.h", cname = "setproctitle")]
+            protected extern static void setproctitle (string fmt, ...);
 #endif
 
         /**
