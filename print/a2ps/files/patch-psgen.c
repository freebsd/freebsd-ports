--- lib/psgen.c.orig	2000-01-15 23:15:07 UTC
+++ lib/psgen.c
@@ -232,7 +232,7 @@ output_marker (a2ps_job * job, const char * kind, ucha
     default:
       *buf = '\0';
       ps_escape_char (job, cp[i], buf);
-      output (jdiv, (char *) buf);
+      output (jdiv, "%s", (char *) buf);
       break;
     }
   }
