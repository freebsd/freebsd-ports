--- lineakd/main.cpp.orig	Mon Feb 21 20:26:38 2005
+++ lineakd/main.cpp	Sat Apr  2 18:20:50 2005
@@ -134,19 +134,19 @@
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
@@ -307,7 +307,7 @@
   watch_messages();
 
   /* init X/Xkb with our EAK keycodes/keysyms */
-  msg("Initializing the display");
+  lineak_core_functions::msg("Initializing the display");
 
   if (!X->initialize(myKbd)) {
      cerr << "Could not initialize all keys. Retrying.\n";
@@ -329,7 +329,7 @@
         myDisplay = new displayCtrl(myConfig);
         myDisplay->init();
   }
-  msg("Initializing Plugin Display");
+  lineak_core_functions::msg("Initializing Plugin Display");
   plugins->initializePluginsDisplay(*myDisplay);
 
   /* alright, we're going to loop forever now. only signals can interrupt us. */
@@ -362,23 +362,23 @@
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
 	       if (very_verbose) cout << "Reiniting plugin provided On Screen Display" << endl;
@@ -390,7 +390,7 @@
 	       myDisplay->init();
 	   }
 	   // Initialize the plugin displays again.
-	   msg("Initializing Plugin Display");
+	   lineak_core_functions::msg("Initializing Plugin Display");
 	   plugins->initializePluginsDisplay(*myDisplay);
 	   // set exec.setDisplayCtrl(myDisplay) again.
 	   exec.setDisplayCtrl(myDisplay);
@@ -414,7 +414,7 @@
 		 } 
 
 	         if (obj != NULL) {
-		    msg("Got an object!");
+		    lineak_core_functions::msg("Got an object!");
 	            if (obj->getType() == SYM && obj->getEventType() == PRESS) {
 		      cout << "xev.xkey.keycode = " << xev.xkey.keycode << endl;
 		      cout << "obj->getKeyCode() = " << obj->getKeyCode() << endl;
@@ -435,21 +435,21 @@
 		       }
 	            }
 	            else {
-		        msg("Looking for CODE and PRESS");
+		        lineak_core_functions::msg("Looking for CODE and PRESS");
 			
 	               if (obj->getType() == CODE && obj->getEventType() == PRESS)
 	               {
 		          if (verbose) cout << xev.xkey.keycode << " = " << obj->getKeyCode() << endl;
 			  
 			  if (obj->hasModifier(xev.xkey.state))
-			     msg("true");
+			     lineak_core_functions::msg("true");
 			  else
-			     msg("false");
+			     lineak_core_functions::msg("false");
 			  
 		          if ((int)xev.xkey.keycode == obj->getKeyCode()
 		              && obj->hasModifier((int)xev.xkey.state))
 		          {
-			     msg("getting to the right place!");
+			     lineak_core_functions::msg("getting to the right place!");
 			     execute = plugins->exec(obj,xev);
 	                     if (execute != NULL)
                                 execute(obj,xev);
