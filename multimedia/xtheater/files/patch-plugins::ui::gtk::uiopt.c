--- plugins/ui/gtk/uiopt.c.orig	Sat Jun  2 07:06:34 2001
+++ plugins/ui/gtk/uiopt.c	Sun Aug 22 22:10:22 2004
@@ -40,8 +40,8 @@
 void apply_savesettings (GtkWidget * b, gpointer ig);
 
 /* Data */
-static GtkWidget *labs[64];
-static GtkWidget *sets[64];
+static GtkWidget *my_labs[64];
+static GtkWidget *my_sets[64];
 static char type[64];
 static char plug_opts[64][80];
 static int num_settings;
@@ -83,26 +83,26 @@
          type[i] = 's';
          tmp = opts[i] + 7;
          while (*(tmp++) != '\t');
-         sets[i] = gtk_entry_new ();
-         labs[i] = gtk_label_new (tmp);
+         my_sets[i] = gtk_entry_new ();
+         my_labs[i] = gtk_label_new (tmp);
          strncpy (plug_opts[i], opts[i] + 7, tmp - opts[i] - 8);
-         gtk_box_pack_start (GTK_BOX (horbox[i]), sets[i], 0, 0, 0);
-         gtk_box_pack_start (GTK_BOX (horbox[i]), labs[i], 0, 0, 0);
+         gtk_box_pack_start (GTK_BOX (horbox[i]), my_sets[i], 0, 0, 0);
+         gtk_box_pack_start (GTK_BOX (horbox[i]), my_labs[i], 0, 0, 0);
          if (loader_get_setting (plug_opts[i]))
-            gtk_entry_set_text (GTK_ENTRY (sets[i]),
+            gtk_entry_set_text (GTK_ENTRY (my_sets[i]),
                                 loader_get_setting (plug_opts[i]));
       }
       if (!strncmp (opts[i], "bool", 4)) {
          type[i] = 'b';
          tmp = opts[i] + 5;
          while (*(tmp++) != '\t');
-         sets[i] = gtk_check_button_new ();
-         labs[i] = gtk_label_new (tmp);
+         my_sets[i] = gtk_check_button_new ();
+         my_labs[i] = gtk_label_new (tmp);
          strncpy (plug_opts[i], opts[i] + 5, tmp - opts[i] - 6);
-         gtk_box_pack_start (GTK_BOX (horbox[i]), sets[i], 0, 0, 0);
-         gtk_box_pack_start (GTK_BOX (horbox[i]), labs[i], 0, 0, 0);
+         gtk_box_pack_start (GTK_BOX (horbox[i]), my_sets[i], 0, 0, 0);
+         gtk_box_pack_start (GTK_BOX (horbox[i]), my_labs[i], 0, 0, 0);
          if (loader_get_setting (plug_opts[i]))
-            gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (sets[i]),
+            gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (my_sets[i]),
                                           !strcmp (loader_get_setting
                                                    (plug_opts[i]), "true"));
 
@@ -146,14 +146,14 @@
    for (i = 0; i < num_settings; i++) {
       switch (type[i]) {
          case 'b':
-            if (GTK_TOGGLE_BUTTON (sets[i])->active)
+            if (GTK_TOGGLE_BUTTON (my_sets[i])->active)
                loader_set_setting (plug_opts[i], "true");
             else
                loader_set_setting (plug_opts[i], "false");
             break;
          case 's':
             loader_set_setting (plug_opts[i],
-                                gtk_entry_get_text (GTK_ENTRY (sets[i])));
+                                gtk_entry_get_text (GTK_ENTRY (my_sets[i])));
             break;
       }
    }
