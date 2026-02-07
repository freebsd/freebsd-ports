greeting.cc:72:18: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
    version = "v"VERSION" ";
                 ^

1 error generated.

--- src/greeting.cc.orig	2018-08-04 05:50:47 UTC
+++ src/greeting.cc
@@ -69,7 +69,7 @@ void Binc::showGreeting(void)
   string tmp = session.globalconfig["Security"]["version in greeting"];
   lowercase(tmp);
   if (tmp == "yes")
-    version = "v"VERSION" ";
+    version = "v" VERSION" ";
 
   com << "* OK Welcome to Binc IMAP " << version 
       << "Copyright (C) 2002-2005 Andreas Aardal Hanssen at "
