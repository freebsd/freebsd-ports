
$FreeBSD$

--- lib/gmond_config.c.orig	Thu Feb 20 14:32:29 2003
+++ lib/gmond_config.c	Thu Feb 20 14:32:39 2003
@@ -224,7 +224,7 @@
    config->deaf = 0;
    config->debug_level = 0;
    config->no_setuid = 0;
-   config->setuid = conf_strdup("nobody");
+   config->setuid = conf_strdup("ganglia");
    config->no_gexec = 0;
    config->all_trusted = 0;
 
