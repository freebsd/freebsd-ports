--- src/proc.c.orig	2008-10-22 21:08:21.000000000 -0400
+++ src/proc.c	2014-04-14 11:28:06.963679543 -0400
@@ -30,6 +30,9 @@
 #include <dirent.h>
 #include <ctype.h>
 
+#ifdef _FREEBSD_
+#include <unistd.h>
+#endif
 /* now here is the nasty stuff:  ideally we want to ignore/get-rid-of
  * deleted binaries and maps, BUT, preLINK, renames and later deletes
  * them all the time, to replace them with (supposedly better) prelinked
@@ -96,7 +99,7 @@
   if (exemaps)
     *exemaps = g_set_new ();
   
-  g_snprintf (name, sizeof (name) - 1, "/proc/%d/maps", pid);
+  g_snprintf (name, sizeof (name) - 1, "/compat/linux/proc/%d/maps", pid);
   in = fopen (name, "r");
   if (!in)
     {
@@ -165,9 +168,9 @@
   struct dirent *entry;
   pid_t selfpid = getpid ();
 
-  proc = opendir ("/proc");
+  proc = opendir ("/compat/linux/proc");
   if (!proc)
-    g_error ("failed opening /proc: %s", strerror (errno));
+    g_error ("failed opening /compat/linux/proc: %s", strerror (errno));
 
   while ((entry = readdir (proc)))
   {
@@ -182,7 +185,7 @@
 	  if (pid == selfpid)
 	    continue;
 
-	  g_snprintf (name, sizeof (name) - 1, "/proc/%s/exe", entry->d_name);
+	  g_snprintf (name, sizeof (name) - 1, "/compat/linux/proc/%s/exe", entry->d_name);
 
 	  len = readlink (name, exe_buffer, sizeof (exe_buffer));
 
@@ -228,35 +231,60 @@
 	  if (b) sscanf(b, tag" %d %d", &(v1), &(v2));		\
 	} G_STMT_END
 
-void
-proc_get_memstat (preload_memory_t *mem)
+
+#define read_vmstat(v1,v2) G_STMT_START {			\
+    const char *b;					        \
+    b = buf+191;						\
+    if (b) sscanf(b,"   %d   %d", &(v1), &(v2));		\
+  } G_STMT_END							\
+ 	    
+
+
+void proc_get_memstat (preload_memory_t *mem)
 {
   static int pagesize = 0;
   char buf[4096];
+#ifndef __LINUX__
+  FILE* fp;
+#endif
 
   memset (mem, 0, sizeof (*mem));
 
   if (!pagesize)
     pagesize = getpagesize ();
  
-  open_file ("/proc/meminfo");
+  open_file ("/compat/linux/proc/meminfo");
   read_tag ("MemTotal:", mem->total);
   read_tag ("MemFree:", mem->free);
   read_tag ("Buffers:", mem->buffers);
   read_tag ("Cached:", mem->cached);
-
+#ifdef __LINUX__
   open_file ("/proc/vmstat");
-  read_tag ("pgpgin", mem->pagein);
-  read_tag ("pgpgout", mem->pageout);
+   read_tag ("pgpgin", mem->pagein);
+   read_tag ("pgpgout", mem->pageout);
+#else
+   fp = popen("/usr/bin/vmstat","r");
+   if(fp!=NULL)
+     {
+       fread(buf,sizeof buf,1,fp);
+       read_vmstat(mem->pagein,mem->pageout);
+#ifdef _DEBUG
+       printf("readed pi %d po %d ",mem->pagein,
+	      mem->pageout);
+#endif 
+     }
+#endif
 
   if (!mem->pagein) {
-    open_file ("/proc/stat");
+    open_file ("/compat/linux/proc/stat");
     read_tag2 ("page", mem->pagein, mem->pageout);
   }
 
   mem->pagein *= pagesize / 1024;
   mem->pageout *= pagesize / 1024;
-
+#ifdef _DEBUG
   if (!mem->total || !mem->pagein)
-    g_warning ("failed to read memory stat, is /proc mounted?");
+    g_warning ("failed to read memory stat, is /compat/linux/proc mounted?");
+#endif
+    
 }
