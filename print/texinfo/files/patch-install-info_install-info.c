--- install-info/install-info.c.orig	2011-02-03 21:48:38.000000000 +0000
+++ install-info/install-info.c	2011-02-03 21:56:15.000000000 +0000
@@ -25,6 +25,7 @@
 #define TAB_WIDTH 8
 
 static char *progname = "install-info";
+static char *default_section = NULL;
 
 struct spec_entry;
 struct spec_section;
@@ -145,6 +146,8 @@
   { "calign",    required_argument, NULL, 'C'},
   { "debug",     no_argument, NULL, 'g' },
   { "delete",    no_argument, NULL, 'r' },
+  { "defentry",  required_argument, NULL, 'E' },
+  { "defsection",  required_argument, NULL, 'S' },
   { "dir-file",  required_argument, NULL, 'd' },
   { "entry",     required_argument, NULL, 'e' },
   { "name",      required_argument, NULL, 't' },
@@ -515,6 +518,10 @@
  --debug             report what is being done.\n\
  --delete            delete existing entries for INFO-FILE from DIR-FILE;\n\
                       don't insert any new entries.\n\
+ --defentry=TEXT     like --entry, but only use TEXT if an entry\n\
+                      is not present in INFO-FILE.\n\
+ --defsection=TEXT   like --section, but only use TEXT if a section\n\
+                      is not present in INFO-FILE.\n\
  --description=TEXT  the description of the entry is TEXT; used with\n\
                       the --name option to become synonymous with the\n\
                       --entry option.\n\
@@ -1814,6 +1821,8 @@
   struct spec_entry *entries_to_add = NULL;
   struct spec_entry *entries_to_add_from_file = NULL;
   int n_entries_to_add = 0;
+  struct spec_entry *default_entries_to_add = NULL;
+  int n_default_entries_to_add = 0;
 
   /* Record the old text of the dir file, as plain characters,
      as lines, and as nodes.  */
@@ -1998,6 +2007,7 @@
           }
           break;
 
+	case 'E':
         case 'e':
           {
             struct spec_entry *next
@@ -2012,12 +2022,18 @@
             next->text_len = olen;
             next->entry_sections = NULL;
             next->entry_sections_tail = NULL;
-            next->next = entries_to_add;
             next->missing_name = 0;
             next->missing_basename = 0;
             next->missing_description = 0;
-            entries_to_add = next;
-            n_entries_to_add++;
+	    if (opt == 'e') {
+		next->next = entries_to_add;
+		entries_to_add = next;
+		n_entries_to_add++;
+	    } else {
+		next->next = default_entries_to_add;
+		default_entries_to_add = next;
+		n_default_entries_to_add++;
+	    }
           }
           break;
 
@@ -2084,6 +2100,10 @@
           }
           break;
 
+	case 'S':
+	  default_section = optarg;
+	  break;
+
         case 's':
           {
             struct spec_section *next
@@ -2273,7 +2293,7 @@
         {
           input_sections = (struct spec_section *)
             xmalloc (sizeof (struct spec_section));
-          input_sections->name = "Miscellaneous";
+          input_sections->name = default_section ? default_section : "Miscellaneous";
           input_sections->next = NULL;
           input_sections->missing = 1;
         }
