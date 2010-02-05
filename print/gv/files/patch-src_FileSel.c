--- src/FileSel.c.orig	2010-01-16 19:32:22.000000000 -0500
+++ src/FileSel.c	2010-01-16 19:33:09.000000000 -0500
@@ -1488,6 +1488,7 @@
      else          SetIncompleteDirectoryView(fs,cannotopenList);
      chdir(APP_DIR);
      ENDMESSAGE(SetDirectoryView)
+     (void)closedir(dirp);
      return;
    }
 
