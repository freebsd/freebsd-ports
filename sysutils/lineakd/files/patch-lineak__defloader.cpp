--- lineak/defloader.cpp.orig	Tue Feb 15 18:28:46 2005
+++ lineak/defloader.cpp	Tue Feb 15 18:28:49 2005
@@ -129,7 +129,7 @@
 	   // Handle empty lines.
 	   loc = tmp.find('=');
            // empty line
-   	   if (loc == string::npos)
+   	   if (loc == (unsigned int)string::npos)
    	     continue;
 
 	   // key == the name of the key.
@@ -157,13 +157,13 @@
 		 //cout << akey;
 	         /** Now determine if this is a toggleable key. We will have to parse
 	             the name format name1|name2 if indeed it is a toggleable key. */
-		 if ((unsigned int)key.find('|') != string::npos) {
+		 if ((unsigned int)key.find('|') != (unsigned int)string::npos) {
 		    key+='|';
 		    akey->setToggle(true);
 		    int index;
 		    string tmp;
 	            //vector<string>names;
-	            while (((unsigned int)(index = key.find('|'))) != string::npos) {
+	            while (((unsigned int)(index = key.find('|'))) != (unsigned int)string::npos) {
 		       tmp = key.substr(0,index);
 		       //cout << "adding toggle name: " << tmp << " to " << akey->getName() << endl;
                        akey->addToggleName(tmp);
