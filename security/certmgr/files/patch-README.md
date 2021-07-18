--- README.md.orig	2021-07-04 21:06:24 UTC
+++ README.md
@@ -39,13 +39,13 @@ Prometheus is used to collect some useful `certmgr` me
 ## certmgr.yaml
 
 The configuration file must be a YAML file; it is expected to be in
-`/etc/certmgr/certmgr.yaml`. The location can be changed using the
+`%%ETCDIR%%/certmgr.yaml`. The location can be changed using the
 `-f` flag.
 
 An example `certmgr.yaml` file is:
 
 ```
-dir: /etc/certmgr.d
+dir: %%ETCDIR%%.d
 default_remote: ca.example.net:8888
 svcmgr: systemd
 before: 72h
