
$FreeBSD$

--- gmond/g25_config.c.orig
+++ gmond/g25_config.c
@@ -228,7 +228,7 @@
    config->deaf = 0;
    config->debug_level = 0;
    config->no_setuid = 0;
-   config->setuid = conf_strdup("nobody");
+   config->setuid = conf_strdup("ganglia");
    config->no_gexec = 0;
    config->all_trusted = 0;
    config->host_dmax = 0;
