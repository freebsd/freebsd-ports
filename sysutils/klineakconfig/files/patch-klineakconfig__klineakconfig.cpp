--- klineakconfig/klineakconfig.cpp.orig	Mon Jun  5 18:36:05 2006
+++ klineakconfig/klineakconfig.cpp	Mon Jun  5 18:39:06 2006
@@ -55,7 +55,7 @@
    QString parsefile = QString::null;
    parsefile = QDir::homeDirPath() + CONFFILE;
     
-   msg("Loading the plugin manager");
+   lineak_core_functions::msg("Loading the plugin manager");
    plugins = new PluginManager;
    vector<string> pluginlist = plugins->scanForPlugins();
    /** Load the plugins */
@@ -68,7 +68,7 @@
    macrolist = plugins->getMacroList();
    /** Get a list of directives from the plugins and their defaults that we support here */
    dnd = plugins->getDirectivesList();
-   msg("Setting dnd!");
+   lineak_core_functions::msg("Setting dnd!");
    /** Add to the list of directives and defaults that we support implicitly. */
    dnd.addValue(_CD_KEYBOARD_TYPE, snull);
    dnd.addValue(_CD_USERCONFFILE, snull);
@@ -95,7 +95,7 @@
    signal(SIGTERM, signalquit);
    signal(SIGABRT, signalquit);
    signal(SIGINT, signalquit);
-   signal(SIGCLD,signalchild);
+   signal(SIGCHLD,signalchild);
    /* and for a rehash when we catch SIGHUP */
    signal(SIGHUP,signalhup);
    
@@ -142,16 +142,16 @@
    /* Make sure we have a config file. */ 
    filename.setName(parsefile);
    if (!filename.exists()) {
-      msg("Creating a basic config file.");
+      lineak_core_functions::msg("Creating a basic config file.");
       createBasic(parsefile);
    }
 
-   msg("Parsing the config files.");
+   lineak_core_functions::msg("Parsing the config files.");
    /** Parse the users ~/.lineak/lineakd.conf file */
    if (!(got_conf = parseconf()))
       quit();
 
-   msg("Setting commands!");
+   lineak_core_functions::msg("Setting commands!");
    usleep(400000);
    myKbd.setCommands(myConfig);
 
@@ -165,10 +165,10 @@
    connect(keyopts,SIGNAL(apply()),this,SLOT(slotRefreshKeylist(void)));
    
    // Show the panel
-   msg("Showing the system tray.");
+   lineak_core_functions::msg("Showing the system tray.");
    systemTrayApp->show();
    // Show all the data in the gui widgets.
-   msg("Refreshing GUI data");
+   lineak_core_functions::msg("Refreshing GUI data");
    refreshGUIdata();
    // Test and see if there are any lineakd processes running. If there are kill them or exit.
    
@@ -181,7 +181,7 @@
 	usleep(400000);
 	attempt++;
    }  	
-   msg("Starting lineakd");
+   lineak_core_functions::msg("Starting lineakd");
    startLineakd();
    
 }
@@ -235,7 +235,7 @@
    until the new file has been reparsed.*/
    
    changing_from_signal = true;
-   msg("reparsing");
+   lineak_core_functions::msg("reparsing");
    bool res = false;
      
    if (parsefile != QString::null)
@@ -297,7 +297,7 @@
      QMessageBox::critical(this, "KLineakConfig", "Failed to parse the configuration file.");
      return false;
   }
-  //msg("Do we have a def yet?");
+  //lineak_core_functions::msg("Do we have a def yet?");
   /** If we parsed a definition's file */
   if (got_def) {
      string kbdtxt = myConfig[_CD_KEYBOARD_TYPE];
@@ -306,7 +306,7 @@
         error("myConfig is empty!");
 	   
      if (myDef.hasKeyboard(kbdtxt)) {
-        msg("Returning the keyboard.");
+        lineak_core_functions::msg("Returning the keyboard.");
         myKbd = myDef.getKeyboard(kbdtxt);
      }
      else {
@@ -314,9 +314,9 @@
 	return false;
      }
      
-     //msg("is myKbd empty?");
+     //lineak_core_functions::msg("is myKbd empty?");
      if (myKbd.isEmpty()) {
-        msg("OH OH! it's an empty keyboard definition!");
+        lineak_core_functions::msg("OH OH! it's an empty keyboard definition!");
         QString homedir = QDir::homeDirPath(); //getenv("HOME");
         homedir+=LINEAKDIR;
         homedir+=DEFFILE;
@@ -329,13 +329,13 @@
                 "%2\n").arg(LINEAKKB_FILE).arg(homedir));
            quit();
      } else
-        msg("myKbd is not empty");
+        lineak_core_functions::msg("myKbd is not empty");
   }
   else {
      error("Attepting to load the user .conf setting before we have keyboard data!");
      return false;
   }
-  msg("Returning from parseConf");
+  lineak_core_functions::msg("Returning from parseConf");
   return true;
 }
 
@@ -422,7 +422,7 @@
 		Return true if we hupped the daemon.
   		Return false if the daemon was not hupped */
 bool KlineakConfig::hupLineakd() {
-   msg("hupLineakd()");
+   lineak_core_functions::msg("hupLineakd()");
    msgPasser message;
    message.start();
    message.sendMessage(msgPasser::HUP,"hup");
@@ -468,7 +468,7 @@
 /** Stop the lineakd daemon. If we killed it return true. Else if it could not be killed
 		return false */
 bool KlineakConfig::stopLineakd() {
-   msg("Stopping Lineakd");
+   lineak_core_functions::msg("Stopping Lineakd");
    msgPasser message;
    message.start();
    message.sendMessage(msgPasser::EXIT,"exit");
@@ -640,7 +640,7 @@
   
   //changing_text_from_signal = false;
    selected_key = 0;
-   //msg("leaving setKeyboard");
+   //lineak_core_functions::msg("leaving setKeyboard");
 }
 
 /** select a new keyboard by model name. The brand name is obtained by
@@ -655,9 +655,9 @@
   // of the keys defined.
   myKbd.setCommands(myConfig);
   if (verbose) {
-     msg("SELECTED NEW KEYBOARD");
+     lineak_core_functions::msg("SELECTED NEW KEYBOARD");
      cout << myKbd << endl;
-     msg("--END SELECTED NEW KEYBOARD--");
+     lineak_core_functions::msg("--END SELECTED NEW KEYBOARD--");
   }
   
   //changing_text_from_signal = true;
@@ -693,7 +693,7 @@
    KURL source, dest;
    QString name;
    QString returnMsg;
-   msg("Backup conffile");
+   lineak_core_functions::msg("Backup conffile");
    name = (myConfig[_CD_USERCONFFILE]).c_str();
    if (verbose) cout << name << " to " << name + ".backup" << endl;
    source.setPath(name);
@@ -722,14 +722,14 @@
    // Now save the thing.
    Saver tmp(myConfig.getFilename());
    if (verbose) {
-      msg("Saving!");
+      lineak_core_functions::msg("Saving!");
       cout << myConfig << endl;
    }
    
    bool r = tmp.saveFile(myConfig);
    
    if (r)
-      msg("Saved!");
+      lineak_core_functions::msg("Saved!");
    else
       error("Could not save the config file.");
    
@@ -737,16 +737,16 @@
 }
 
 void KlineakConfig::onAdvancedConfigOptionsButtonClicked(void) {
-   msg("Showing Advanced Configuration Options");
+   lineak_core_functions::msg("Showing Advanced Configuration Options");
    advancedKbdConfig->setData(myConfig);
    advancedKbdConfig->show();
    advancedKbdConfig->raise();
 }
 
 void KlineakConfig::onAdvancedKeyOptionsButtonClicked(void) {
-   msg("onAdvancedKeyOptionsButtonClicked()");
+   lineak_core_functions::msg("onAdvancedKeyOptionsButtonClicked()");
    if (lstAvailableKeys->currentItem() == 0) 
-      msg("The current item is null.");
+      lineak_core_functions::msg("The current item is null.");
    else {
       string key = lstAvailableKeys->currentItem()->text(0).latin1();
       //cout << "Outputting myKbd" << endl;
