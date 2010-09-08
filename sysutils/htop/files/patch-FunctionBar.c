--- FunctionBar.c.orig	2010-01-26 03:50:57.000000000 +0800
+++ FunctionBar.c	2010-01-26 03:51:50.000000000 +0800
@@ -52,14 +52,12 @@
       this->functions = malloc(sizeof(char*) * 15);
       this->keys = malloc(sizeof(char*) * 15);
       this->events = malloc(sizeof(int) * 15);
-      int i = 0;
-      while (i < 15 && functions[i]) {
+      for (int i = 0; i < 15 && functions[i]; i++) {
          this->functions[i] = String_copy(functions[i]);
          this->keys[i] = String_copy(keys[i]);
          this->events[i] = events[i];
-         i++;
+         this->size = i;
       }
-      this->size = i;
    } else {
       this->staticData = true;
       this->functions = functions ? functions : FunctionBar_FLabels;
