--- lineakd/main.cpp.orig	Wed Dec 29 11:55:13 2004
+++ lineakd/main.cpp	Wed Dec 29 11:55:15 2004
@@ -288,7 +288,7 @@
   watch_messages();
 
   /* init X/Xkb with our EAK keycodes/keysyms */
-  msg("Initializing the display");
+  lineak_core_functions::msg("Initializing the display");
 
   if (!X->initialize(myKbd)) {
      cerr << "Could not initialize all keys. Retrying.\n";
@@ -345,7 +345,7 @@
 		 } 
 
 	         if (obj != NULL) {
-		    msg("Got an object!");
+		    lineak_core_functions::msg("Got an object!");
 	            if (obj->getType() == SYM && obj->getEventType() == PRESS) {
 		       if (xev.xkey.keycode == XKeysymToKeycode (display, obj->getKeySym())
 		           && obj->hasModifier(xev.xkey.state))
@@ -366,21 +366,21 @@
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
@@ -515,7 +515,7 @@
 		if (!X->xkbRemapped())
 		   X->xkbRemapped(true); // =1;
 		else {
-		   msg("Reclaiming keyboard map from MappingNotify event");
+		   lineak_core_functions::msg("Reclaiming keyboard map from MappingNotify event");
 		   X->xkbRemapped(false);
 		   //X->getModifiers();
 		   X->initialize(myKbd);
