--- src/slurp.c.orig	2016-01-24 14:16:26 UTC
+++ src/slurp.c
@@ -194,7 +194,7 @@ int recv_init( u_char *initmsg )
          return 0;
    // get file size and divide to determine portion of dictionary to process per task
       fseek(wl.dictfile, 0, SEEK_END );
-      wl.ptask_size = wl.dictfile->_offset / cfg.ptask_level;
+      wl.ptask_size = ftell(wl.dictfile) / cfg.ptask_level;
       pstr += strlen(pstr)+1;
    }
    if( cfg.mcl & CL_GDICT )
