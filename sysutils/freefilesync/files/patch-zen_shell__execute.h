--- ../../zen/shell_execute.h.orig	2016-03-08 10:01:14.347569000 +0800
+++ ../../zen/shell_execute.h	2016-03-08 10:01:42.930783000 +0800
@@ -120,7 +120,7 @@
     {
         //Posix::system - execute a shell command
         int rv = ::system(command.c_str()); //do NOT use std::system as its documentation says nothing about "WEXITSTATUS(rv)", ect...
-        if (rv == -1 || WEXITSTATUS(rv) == 127) //http://linux.die.net/man/3/system    "In case /bin/sh could not be executed, the exit status will be that of a command that does exit(127)"
+        if (rv == -1 ) //http://linux.die.net/man/3/system    "In case /bin/sh could not be executed, the exit status will be that of a command that does exit(127)"
             throw FileError(_("Incorrect command line:") + L"\n" + utfCvrtTo<std::wstring>(command));
     }
     else
