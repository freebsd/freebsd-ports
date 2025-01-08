--- rsyncrypto.h.orig	2016-11-27 18:44:10 UTC
+++ rsyncrypto.h
@@ -58,7 +58,7 @@ struct startup_options {
                 "Force a new key size, even if previous encryption used a different setting.");
         argtable[i++]=noarch=arg_lit0( NULL, "no-archive-mode", "Do not try to preserve timestamps");
         argtable[i++]=gzip=arg_file0( NULL, "gzip", "<file>",
-                "Path to gzip-like program to use. Must accept a --rsyncable command option");
+                "Path to gzip-like program to use. Must accept a --rsyncable command option. Default is %%LOCALBASE%%/bin/gzip");
         argtable[i++]=rem1=arg_rem( "Advanced options:", "" );
         argtable[i++]=rollwin=arg_int0( NULL, "roll-win", "<n>", "Rollover window size. Default is 8192 byte");
         argtable[i++]=rollmin=arg_int0( NULL, "roll-min", "<n>",
@@ -76,7 +76,7 @@ struct startup_options {
             trim->ival[0]=1;
             rollwin->ival[0]=8192;
             rollmin->ival[0]=8192;
-            gzip->filename[0]="gzip";
+            gzip->filename[0]="%%LOCALBASE%%/bin/gzip";
             nenest->ival[0]=0;
         }
     }
