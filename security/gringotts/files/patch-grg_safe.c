--- src/grg_safe.c.orig	Thu Dec  5 15:10:07 2002
+++ src/grg_safe.c	Sat Jan  4 19:53:18 2003
@@ -33,6 +33,7 @@
 
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <regex.h>
 #include <unistd.h>
 #include <fcntl.h>
@@ -43,7 +44,6 @@
 #include <sys/fsuid.h>
 #endif
 #include <sys/time.h>
-#include <sys/types.h>
 #include <sys/resource.h>
 
 #define GRG_SAFE			0
@@ -57,8 +57,6 @@
 grg_mlockall_and_drop_root_privileges (void)
 {
   //drop eventual group root privileges
-  setgid (getgid ());
-  setgid (getgid ());		//twice for counter "saved IDs", cfr. Secure Programming HowTo
 #ifdef HAVE_SYS_FSUID_H
   setfsgid (getgid ());
   setfsgid (getgid ());
@@ -67,7 +65,7 @@
   if (!geteuid ())
     //the process is (ev. SUID) root. I can mlockall() the memory in order to avoid swapping.
     {
-#ifdef HAVE_MLOCK
+#ifdef HAVE_MLOCKALL
       gint res = mlockall (MCL_CURRENT | MCL_FUTURE);
 
       if (res)
@@ -82,8 +80,6 @@
 #endif
 
       //drop root privileges
-      setuid (getuid ());
-      setuid (getuid ());
 #ifdef HAVE_SYS_FSUID_H
       setfsuid (getuid ());
       setfsuid (getuid ());
@@ -243,7 +239,7 @@
   if (!(geteuid () && getegid () && getuid () && getgid ()))
     change_sec_level (GRG_UNSAFE);
 
-#ifdef HAVE_MLOCK
+#ifdef HAVE_MLOCKALL
   if (!mem_safe)
     change_sec_level (GRG_UNSAFE);
 #endif
@@ -347,7 +343,7 @@
     ADD_INDICATOR (GTK_DIALOG (dialog)->vbox,
 		   _("Memory protection from core dumps"), green) g_free (rl);
 
-#ifdef HAVE_MLOCK
+#ifdef HAVE_MLOCKALL
   if (mem_safe)
     ADD_INDICATOR (GTK_DIALOG (dialog)->vbox,
 		   _("Memory protection from swap writings"), green)
