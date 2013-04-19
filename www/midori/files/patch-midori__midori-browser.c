--- ./midori/midori-browser.c.orig	2013-04-04 20:31:20.000000000 +0000
+++ ./midori/midori-browser.c	2013-04-06 12:28:33.000000000 +0000
@@ -3228,8 +3228,10 @@
       { NULL },
       #ifndef HAVE_GRANITE
       { "HelpFAQ" },
+      #ifdef __linux__
       { "HelpBugs"},
       #endif
+      #endif
       { "About" },
       { "Preferences" },
     };
@@ -5509,9 +5511,11 @@
     { "HelpFAQ", GTK_STOCK_HELP,
         N_("_Frequent Questions"), "F1",
         NULL, G_CALLBACK (_action_help_link_activate) },
+    #ifdef __linux__
     { "HelpBugs", NULL,
         N_("_Report a Problem…"), NULL,
         NULL, G_CALLBACK (_action_help_link_activate) },
+    #endif
     { "About", GTK_STOCK_ABOUT,
         NULL, "",
         NULL, G_CALLBACK (_action_about_activate) },
@@ -5814,7 +5818,9 @@
             "<menuitem action='Window'/>"
             "<menu action='Help'>"
                 "<menuitem action='HelpFAQ'/>"
+                #ifdef __linux__
                 "<menuitem action='HelpBugs'/>"
+                #endif
                 "<separator/>"
                 "<menuitem action='About'/>"
         "</menu>"
