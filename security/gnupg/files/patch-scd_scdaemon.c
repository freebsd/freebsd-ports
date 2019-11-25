--- scd/scdaemon.c.orig	2019-07-09 09:08:45 UTC
+++ scd/scdaemon.c
@@ -99,6 +99,7 @@ enum cmd_and_opt_values
   oDenyAdmin,
   oDisableApplication,
   oEnablePinpadVarlen,
+  oSharedAccess,
   oListenBacklog,
 
   oNoop
@@ -164,6 +165,8 @@ static ARGPARSE_OPTS opts[] = {
   /* Stubs for options which are implemented by 2.3 or later.  */
   ARGPARSE_s_s (oNoop, "application-priority", "@"),
 
+  ARGPARSE_s_n (oSharedAccess, "shared-access", N_("use PCSC_SHARE_SHARED for pcsc_connect")),
+
   ARGPARSE_end ()
 };
 
@@ -629,6 +632,8 @@ main (int argc, char **argv )
 
         case oNoop: break;
 
+        case oSharedAccess: opt.shared_access = 1; break;
+
         default:
           pargs.err = configfp? ARGPARSE_PRINT_WARNING:ARGPARSE_PRINT_ERROR;
           break;
@@ -727,6 +732,7 @@ main (int argc, char **argv )
       es_printf ("disable-pinpad:%lu:\n", GC_OPT_FLAG_NONE );
       es_printf ("card-timeout:%lu:%d:\n", GC_OPT_FLAG_DEFAULT, 0);
       es_printf ("enable-pinpad-varlen:%lu:\n", GC_OPT_FLAG_NONE );
+      es_printf ("shared-access:%lu:\n", GC_OPT_FLAG_NONE );
 
       scd_exit (0);
     }
