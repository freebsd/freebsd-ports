--- curs_lib.c.old	Wed Sep  1 19:39:20 1999
+++ curs_lib.c	Sun Sep 26 23:47:03 1999
@@ -156,6 +156,16 @@
       def = 0;
       break;
     }
+    else if (tolower(ch.ch) == 'y')
+    {
+      def = 1;
+      break;
+    }
+    else if (tolower(ch.ch) == 'n')
+    {
+      def = 0;
+      break;
+    }
     else
     {
       BEEP();
@@ -413,8 +423,9 @@
 {
   event_t ch;
   int choice;
-  char *p;
+  char *p, *nletters;
 
+  nletters = _(letters);
   mvaddstr (LINES - 1, 0, prompt);
   clrtoeol ();
   FOREVER
@@ -428,6 +439,12 @@
     }
     else
     {
+      p = strchr (nletters, ch.ch);
+      if (p)
+      {
+	choice = p - nletters + 1;
+	break;
+      }
       p = strchr (letters, ch.ch);
       if (p)
       {
