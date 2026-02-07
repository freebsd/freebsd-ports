--- src/FileSel.c.orig	2012-04-01 14:43:24 UTC
+++ src/FileSel.c
@@ -1414,6 +1414,7 @@ static void SetDirectoryView(FileSelectionWidget fs, c
      else          SetIncompleteDirectoryView(fs,cannotopenList);
      chdir(APP_DIR);
      ENDMESSAGE(SetDirectoryView)
+     (void)closedir(dirp);
      return;
    }
 
