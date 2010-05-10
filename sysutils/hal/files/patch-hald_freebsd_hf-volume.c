--- hald/freebsd/hf-volume.c.orig	2009-12-23 14:01:00.000000000 -0500
+++ hald/freebsd/hf-volume.c	2009-12-23 14:01:25.000000000 -0500
@@ -86,9 +86,12 @@ hf_volume_resolve_fuse (const char *spec
         {
           if (strcmp(fields[0], special) == 0)
 	    {
+	      char *ret;
+
+	      ret = g_strdup(fields[1]);
 	      g_strfreev(fields);
 	      g_strfreev(lines);
-	      return g_strdup(fields[1]);
+	      return ret;
 	    }
 	}
       g_strfreev(fields);
