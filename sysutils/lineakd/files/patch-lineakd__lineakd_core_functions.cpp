--- lineakd/lineakd_core_functions.cpp.orig	Wed Dec 29 11:49:55 2004
+++ lineakd/lineakd_core_functions.cpp	Wed Dec 29 11:54:02 2004
@@ -46,6 +46,7 @@
 #include <sys/wait.h>
 }
 
+#include <lineak/lineak_core_functions.h>
 #include <lineak/definitions.h>
 #include <lineak/configdirectives.h>
 #include <lineak/saver.h>
@@ -256,7 +257,7 @@
   	sigprocmask(SIG_SETMASK, &mask_set, &old_set);
 
    	/* now do some cleaning... */
-  	msg("Cleaning up xkb mappings");
+  	lineak_core_functions::msg("Cleaning up xkb mappings");
    	/* Clean up X */
         if (X != 0) {
   		X->cleanup(myKbd);
@@ -275,7 +276,7 @@
               //msg("Unloading All Plugins DONE!");
               delete(plugins);
               plugins = NULL;
-              msg("Plugins all taken care of!");
+              lineak_core_functions::msg("Plugins all taken care of!");
            }
         }
 
@@ -283,13 +284,13 @@
   	//sigprocmask(SIG_SETMASK, &old_set, NULL);
 
         /* Remove the message queue */
-  	msg("Removing message queue");
+  	lineak_core_functions::msg("Removing message queue");
 	msgPasser myMsg;
 	if (!myMsg.start()) error("do_exit(): Cannot establish message queue to shutdown the queue.!");
         myMsg.quit();
 
         /** Remove the lock */
-        msg("Removing lock");
+        lineak_core_functions::msg("Removing lock");
         lockCtrl lock("lineakd");
         lock.unlock();
 //      exit(true);
@@ -321,8 +322,8 @@
   		sigprocmask(SIG_SETMASK, &mask_set, &old_set);
    		//bool verbose = cmdprefs.getVerbose();
 
-   		msg("Recieved a message to load a new configuration");
-                msg("Unmapping keys");
+   		lineak_core_functions::msg("Recieved a message to load a new configuration");
+                lineak_core_functions::msg("Unmapping keys");
                 X->cleanup(myKbd);
 
                 //msg("Unloading all plugins");
@@ -366,34 +367,34 @@
                 cmdprefs.setDefaults(dnd);
 
   		/* reload .conf and .def file */
-  		msg("*** reloading config file " + myConfig.getFilename());
+  		lineak_core_functions::msg("*** reloading config file " + myConfig.getFilename());
                 cout << "Config file to load is: " << myConfig.getFilename() << endl;
                 ConfigLoader ldr(myConfig.getFilename(),dnd);
 		myConfig.clear();
                 myConfig = ldr.loadConfig();
                 myConfig.print(cout);
   		//parseConfigs(dnd, myConfig);
-		msg("*** setting config file options " + myConfig.getFilename());
+		lineak_core_functions::msg("*** setting config file options " + myConfig.getFilename());
                 cmdprefs.setOpts(myConfig);
-  		msg("*** reloading definition file " + myDef.getFilename());
+  		lineak_core_functions::msg("*** reloading definition file " + myDef.getFilename());
   		parseDefinitions(cmdprefs, myDef);
 
   		/* re-init the EAKeyboard */
-  		msg("*** re-initializing the keyboard");
+  		lineak_core_functions::msg("*** re-initializing the keyboard");
     	        myKbd = myDef.getKeyboard(myConfig[_CD_KEYBOARD_TYPE]);
 		/** Update our keyboard with our configured commands */
 		myKbd.setCommands(myConfig);
 
   		/* re-init X/Xkb with our EAK keycodes/keysyms */
-  		msg("*** reconfiguring Xkb keymap with new keys and buttons");
+  		lineak_core_functions::msg("*** reconfiguring Xkb keymap with new keys and buttons");
 		X->initialize(myKbd);
 
   		/* .. restore the old signal mask .. */
-  		msg("*** rehash done");
+  		lineak_core_functions::msg("*** rehash done");
   		sigprocmask(SIG_SETMASK, &old_set, NULL);
 		plugins->initializePlugins(myKbd, myConfig,plugins);
 
-  		msg("*** Restarting On Screen Display...");
+  		lineak_core_functions::msg("*** Restarting On Screen Display...");
   		myDisplay->init(myConfig);
                 plugins->initializePluginsDisplay(*myDisplay);
 
