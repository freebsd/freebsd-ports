
$FreeBSD$

--- gmetad/conf.c.orig
+++ gmetad/conf.c
@@ -249,7 +249,7 @@
    config->trusted_hosts = NULL;
    config->debug_level = 0;
    config->should_setuid = 1;
-   config->setuid_username = "nobody";
+   config->setuid_username = "ganglia";
    config->rrd_rootdir = "/var/lib/ganglia/rrds";
    config->scalable_mode = 1;
    config->all_trusted = 0;
