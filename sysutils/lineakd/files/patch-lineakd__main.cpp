--- lineakd/main.cpp.orig	Fri May 26 14:51:44 2006
+++ lineakd/main.cpp	Fri May 26 14:53:46 2006
@@ -136,19 +136,19 @@
   /** Load the plugins */
   plugins->loadPlugins(pluginlist);
   if (verbose) {
-	  msg("");
-	  msg("Listing Plugins");
+	  lineak_core_functions::msg("");
+	  lineak_core_functions::msg("Listing Plugins");
 	  plugins->listPlugins();
   }
 
-  msg("");
-  msg("Defining Macro Lists");
+  lineak_core_functions::msg("");
+  lineak_core_functions::msg("Defining Macro Lists");
   /** Define the list of macros we support */
   plugins->defineMacroLists();
   //if (verbose) plugins->listPlugins();
   /** Define the configurate directives we support */
-  msg("");
-  msg("Defining Directives Lists");
+  lineak_core_functions::msg("");
+  lineak_core_functions::msg("Defining Directives Lists");
   plugins->defineDirectivesLists();
   //if (verbose) plugins->listPlugins();
    /** Get a list of macros we support so that we can inform other classes */
@@ -318,7 +318,7 @@
   watch_messages();
 
   /* init X/Xkb with our EAK keycodes/keysyms */
-  msg("Initializing the display");
+  lineak_core_functions::msg("Initializing the display");
 
   if (!X->initialize(myKbd)) {
      cerr << "Could not initialize all keys. Retrying.\n";
@@ -340,7 +340,7 @@
         myDisplay = new displayCtrl(myConfig);
         myDisplay->init();
   }
-  msg("Initializing Plugin Display");
+  lineak_core_functions::msg("Initializing Plugin Display");
   plugins->initializePluginsDisplay(*myDisplay);
 
   /* alright, we're going to loop forever now. only signals can interrupt us. */
@@ -375,23 +375,23 @@
      // like VMWare.
      if (xev.type == MappingNotify) {
 //       if (!X->xkbRemapped()) {
-           msg("Setting xkbRemapped flag");
+           lineak_core_functions::msg("Setting xkbRemapped flag");
            X->xkbRemapped(true); // =1;
-           msg("Cleaning up key mappings from MappingNotify event");
+           lineak_core_functions::msg("Cleaning up key mappings from MappingNotify event");
            X->cleanup(myKbd);
-	   msg("Cleaning up the on screen display.");
+	   lineak_core_functions::msg("Cleaning up the on screen display.");
 	   myDisplay->cleanup();
 //       }
        // If we are getting the display back.
        // Get out modifiers and grab our keys again.
        // Reinitialize the OSD.
 //       else {
-           msg("Clearing xkbRemapped flag");
+           lineak_core_functions::msg("Clearing xkbRemapped flag");
            X->xkbRemapped(false);
            //X->getModifiers();
-           msg("Reclaiming keyboard map from MappingNotify event");
+           lineak_core_functions::msg("Reclaiming keyboard map from MappingNotify event");
            X->initialize(myKbd);
-	   msg("Restarting the OSD.");
+	   lineak_core_functions::msg("Restarting the OSD.");
 	   myDisplay = plugins->getDisplay(myConfig);
 	   if (myDisplay != NULL) {
 	       //if (very_verbose) cout << "Reiniting plugin provided On Screen Display" << endl;
@@ -405,7 +405,7 @@
 	       myDisplay->init();
 	   }
 	   // Initialize the plugin displays again.
-	   msg("Initializing Plugin Display");
+	   lineak_core_functions::msg("Initializing Plugin Display");
 	   plugins->initializePluginsDisplay(*myDisplay);
 	   // set exec.setDisplayCtrl(myDisplay) again.
 	   exec.setDisplayCtrl(myDisplay);
@@ -433,7 +433,7 @@
 
 	         if (obj != NULL) {
 		    vmsg("Got an object!");
-                    msg("Looking for SYM and PRESS");
+                    lineak_core_functions::msg("Looking for SYM and PRESS");
 	            if (obj->getType() == SYM && obj->getEventType() == PRESS) {
 		      if (verbose) {
 		         cout << "xev.xkey.keycode = " << xev.xkey.keycode << endl;
@@ -451,7 +451,7 @@
 		       }
 	            }
 	            else {
-		       msg("Looking for CODE and PRESS");
+		       lineak_core_functions::msg("Looking for CODE and PRESS");
 	               if (obj->getType() == CODE && obj->getEventType() == PRESS)
 	               {
 		          if (very_verbose) cout << xev.xkey.keycode << " = " << obj->getKeyCode() << endl;
