--- usertable.cpp.orig	2023-07-29 17:29:34 UTC
+++ usertable.cpp
@@ -608,7 +608,7 @@ void UserTable::RunAsUser(std::string cmd) const
     }
   }
   
-  execlp("/bin/bash","/bin/bash", "-c", cmd.c_str(), (char *)NULL);
+  execlp("/bin/sh","/bin/sh", "-c", cmd.c_str(), (char *)NULL);
 
 failed:
 
