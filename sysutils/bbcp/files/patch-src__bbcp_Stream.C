--- src/bbcp_Stream.C.orig	2015-01-16 11:52:58.000000000 -0800
+++ src/bbcp_Stream.C	2015-01-16 11:55:23.000000000 -0800
@@ -206,7 +206,7 @@
            return bbcp_Emsg("Exec",errno,"creating a pipe for",parm[0]);
         Child_In=fildes_In[0]; Child_Out=fildes_Out[1]; Child_Err=fildes_Err[1];
         fildes_Out[1] = (inrd ? fildes_In[1] : -1);
-        if (retc = Attach(fildes_Out)) return retc;
+        if ((retc = Attach(fildes_Out))) return retc;
        }
 
     // Fork a process first so we can pick up the next request.
@@ -436,7 +436,7 @@
      // If we have a token, return it
      //
      xline = 1;
-     if (wp = GetToken(lowcase)) return wp;
+     if ((wp = GetToken(lowcase))) return wp;
 
      // If no continuation allowed, return a null (but only once)
      //
