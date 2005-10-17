--- util/install-info.c.orig	Mon Oct 17 21:05:19 2005
+++ util/install-info.c	Mon Oct 17 21:24:07 2005
@@ -22,6 +22,7 @@
 #include <getopt.h>
 
 static char *progname = "install-info";
+static char *default_section = NULL;
 
 struct spec_entry;
 struct spec_section;
@@ -120,6 +121,8 @@
 struct option longopts[] =
 {
   { "delete",    no_argument, NULL, 'r' },
+  { "defentry",  required_argument, NULL, 'E' },
+  { "defsection",  required_argument, NULL, 'S' },
   { "dir-file",  required_argument, NULL, 'd' },
   { "entry",     required_argument, NULL, 'e' },
   { "help",      no_argument, NULL, 'h' },
@@ -439,6 +442,10 @@
 Options:\n\
  --delete          delete existing entries for INFO-FILE from DIR-FILE;\n\
                      don't insert any new entries.\n\
+ --defentry=TEXT   like --entry, but only use TEXT if an entry\n\
+                     is not present in INFO-FILE.\n\
+ --defsection=TEXT like --section, but only use TEXT if a section\n\
+                     is not present in INFO-FILE.\n\
  --dir-file=NAME   specify file name of Info directory file.\n\
                      This is equivalent to using the DIR-FILE argument.\n\
  --entry=TEXT      insert TEXT as an Info directory entry.\n\
@@ -1142,6 +1149,8 @@
   struct spec_section *input_sections = NULL;
   struct spec_entry *entries_to_add = NULL;
   int n_entries_to_add = 0;
+  struct spec_entry *default_entries_to_add = NULL;  
+  int n_default_entries_to_add = 0;
 
   /* Record the old text of the dir file, as plain characters,
      as lines, and as nodes.  */
@@ -1205,6 +1214,7 @@
           dirfile = concat (optarg, "", "/dir");
           break;
 
+	case 'E':
         case 'e':
           {
             struct spec_entry *next
@@ -1219,9 +1229,18 @@
             next->text_len = olen;
             next->entry_sections = NULL;
             next->entry_sections_tail = NULL;
-            next->next = entries_to_add;
-            entries_to_add = next;
-            n_entries_to_add++;
+            if (opt == 'e')
+              {
+                next->next = entries_to_add;
+                entries_to_add = next;
+                n_entries_to_add++;
+              }
+            else
+              {
+                next->next = default_entries_to_add;
+                default_entries_to_add = next;
+                n_default_entries_to_add++;
+              }
           }
           break;
 
@@ -1259,6 +1278,10 @@
           }
           break;
 
+        case 'S':
+          default_section = optarg;
+          break;
+
         case 'V':
           printf ("install-info (GNU %s) %s\n", PACKAGE, VERSION);
           puts ("");
@@ -1332,7 +1355,8 @@
             {
               input_sections = (struct spec_section *)
                 xmalloc (sizeof (struct spec_section));
-              input_sections->name = "Miscellaneous";
+              input_sections->name =
+                default_section ? default_section : "Miscellaneous";
               input_sections->next = NULL;
               input_sections->missing = 1;
             }
