
$FreeBSD$

--- gmetad/conf.c.orig	Tue May 27 11:02:49 2003
+++ gmetad/conf.c	Tue Oct 28 11:10:08 2003
@@ -251,7 +251,7 @@
    config->trusted_hosts = NULL;
    config->debug_level = 0;
    config->should_setuid = 1;
-   config->setuid_username = "nobody";
+   config->setuid_username = "ganglia";
    config->rrd_rootdir = "/var/lib/ganglia/rrds";
    config->scalable_mode = 1;
    config->all_trusted = 0;
