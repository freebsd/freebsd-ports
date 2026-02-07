../common/mgenSocketList.cpp:231:20: error: cannot initialize return object of type 'MgenSocketList::Item *' with an rvalue of type 'bool'
            return false;
                   ^~~~~

--- common/mgenSocketList.cpp.orig	2018-08-25 18:45:33 UTC
+++ common/mgenSocketList.cpp
@@ -228,7 +228,7 @@ MgenSocketList::Item* MgenSocketList::JoinGroup(const 
         {
             DMSG(0, "MgenSocketList::JoinGroup() memory allocation error: %s\n",
                     GetErrorString());
-            return false;
+            return NULL;
         }
         item->SetSocketNotifier(socket_notifier);
         Prepend(item);
