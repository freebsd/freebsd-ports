--- OpenFilesScreen.c.orig	2010-01-26 03:53:04.000000000 +0800
+++ OpenFilesScreen.c	2010-01-26 03:56:23.000000000 +0800
@@ -26,7 +26,7 @@
 typedef struct OpenFiles_ProcessData_ {
    char* data[256];
    struct OpenFiles_FileData_* files;
-   bool failed;
+   int error;
 } OpenFiles_ProcessData;
 
 typedef struct OpenFiles_FileData_ {
@@ -80,16 +80,18 @@
    OpenFiles_ProcessData* process = calloc(sizeof(OpenFiles_ProcessData), 1);
    OpenFiles_FileData* file = NULL;
    OpenFiles_ProcessData* item = process;
-   process->failed = true;
    bool anyRead = false;
+
+   if (!fd) {
+      process->error = 127;
+      return process;
+   }
+
    while (!feof(fd)) {
       int cmd = fgetc(fd);
-      if (cmd == EOF && !anyRead) {
-         process->failed = true;
+      if (cmd == EOF && !anyRead)
          break;
-      }
       anyRead = true;
-      process->failed = false;
       char* entry = malloc(1024);
       if (!fgets(entry, 1024, fd)) break;
       char* newline = strrchr(entry, '\n');
@@ -106,7 +108,7 @@
       }
       item->data[cmd] = entry;
    }
-   pclose(fd);
+   process->error = pclose(fd);
    return process;
 }
 
@@ -115,8 +117,10 @@
    int index = MAX(Panel_getSelectedIndex(panel), 0);
    Panel_prune(panel);
    OpenFiles_ProcessData* process = OpenFilesScreen_getProcessData(this->process->pid);
-   if (process->failed) {
+   if (process->error == 127) {
       Panel_add(panel, (Object*) ListItem_new("Could not execute 'lsof'. Please make sure it is available in your $PATH.", 0));
+   } else if (process->error == 1) {
+      Panel_add(panel, (Object*) ListItem_new("Failed listing open files.", 0));
    } else {
       OpenFiles_FileData* file = process->files;
       while (file) {
