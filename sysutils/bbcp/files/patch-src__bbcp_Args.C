--- src/bbcp_Args.C.orig	2015-01-16 13:16:09.000000000 -0800
+++ src/bbcp_Args.C	2015-01-16 13:17:22.000000000 -0800
@@ -58,7 +58,7 @@
          bbcp_Opt *p = this;
          do if (i <= p->Optmaxl && i >= p->Optminl &&
                !strncmp(p->Optword, optarg, i)) return p->Optvalu;
-            while(p = p->Optnext);
+            while((p = p->Optnext));
          return 0;
         }
 
@@ -203,7 +203,7 @@
    if (optspec[1] == '.')
       {if (argval && *argval == '-')
           if (inStream) arg_stream.RetToken();
-             else Aloc--;
+             }else{ Aloc--;
        argval = 0;
        return *optspec;
       }
