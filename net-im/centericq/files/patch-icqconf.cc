--- src/icqconf.cc.orig	Wed Oct  1 08:27:45 2003
+++ src/icqconf.cc	Wed Oct  8 17:28:21 2003
@@ -270,7 +270,7 @@
 	    if(getantispam()) f << "antispam" << endl;
 	    if(getmailcheck()) f << "mailcheck" << endl;
 	    if(getaskaway()) f << "askaway" << endl;
-	    f << "defcharset" << getdefcharset() << endl;
+	    f << "defcharset\t" << getdefcharset() << endl;
 
 	    param = "";
 	    for(protocolname pname = icq; pname != protocolname_size; (int) pname += 1)
