--- ipaplatform/base/paths.py.orig	2026-01-16 09:23:31 UTC
+++ ipaplatform/base/paths.py
@@ -88,13 +88,13 @@ class BasePathNamespace:
     NAMED_CUSTOM_CONF = "/etc/named/ipa-ext.conf"
     NAMED_LOGGING_OPTIONS_CONF = "/etc/named/ipa-logging-ext.conf"
     NAMED_CUSTOM_OPTIONS_CONF = "/etc/named/ipa-options-ext.conf"
-    NAMED_CONF_SRC = '/usr/share/ipa/bind.named.conf.template'
-    NAMED_CUSTOM_CONF_SRC = '/usr/share/ipa/bind.ipa-ext.conf.template'
+    NAMED_CONF_SRC = '/usr/local/share/ipa/bind.named.conf.template'
+    NAMED_CUSTOM_CONF_SRC = '/usr/local/share/ipa/bind.ipa-ext.conf.template'
     NAMED_CUSTOM_OPTIONS_CONF_SRC = (
-        '/usr/share/ipa/bind.ipa-options-ext.conf.template'
+        '/usr/local/share/ipa/bind.ipa-options-ext.conf.template'
     )
     NAMED_LOGGING_OPTIONS_CONF_SRC = (
-        "/usr/share/ipa/bind.ipa-logging-ext.conf.template"
+        "/usr/local/share/ipa/bind.ipa-logging-ext.conf.template"
     )
     NAMED_VAR_DIR = "/var/named"
     NAMED_KEYTAB = "/etc/named.keytab"
@@ -102,7 +102,7 @@ class BasePathNamespace:
     NAMED_ROOT_KEY = "/etc/named.root.key"
     NAMED_MANAGED_KEYS_DIR = "/var/named/dynamic"
     NAMED_CRYPTO_POLICY_FILE = None
-    UNBOUND_CONF_SRC = '/usr/share/ipa/client/unbound.conf.template'
+    UNBOUND_CONF_SRC = '/usr/local/share/ipa/client/unbound.conf.template'
     UNBOUND_CONFIG_DIR = "/etc/unbound/conf.d/"
     UNBOUND_CONF = "/etc/unbound/conf.d/zzz-ipa.conf"
     NSLCD_CONF = "/etc/nslcd.conf"
@@ -143,11 +143,11 @@ class BasePathNamespace:
     LIMITS_CONF = "/etc/security/limits.conf"
     SSH_CONFIG_DIR = "/etc/ssh"
     SSH_CONFIG = "/etc/ssh/ssh_config"
-    SSH_IPA_CONFIG_TEMPLATE = "/usr/share/ipa/client/ssh_ipa.conf.template"
+    SSH_IPA_CONFIG_TEMPLATE = "/usr/local/share/ipa/client/ssh_ipa.conf.template"
     SSH_IPA_CONFIG = "/etc/ssh/ssh_config.d/04-ipa.conf"
     SSHD_CONFIG = "/etc/ssh/sshd_config"
     SSHD_IPA_CONFIG = "/etc/ssh/sshd_config.d/04-ipa.conf"
-    SSHD_IPA_CONFIG_TEMPLATE = "/usr/share/ipa/client/sshd_ipa.conf.template"
+    SSHD_IPA_CONFIG_TEMPLATE = "/usr/local/share/ipa/client/sshd_ipa.conf.template"
     SSSD_CONF = "/etc/sssd/sssd.conf"
     SSSD_CONF_BKP = "/etc/sssd/sssd.conf.bkp"
     SSSD_CONF_DELETED = "/etc/sssd/sssd.conf.deleted"
@@ -214,8 +214,8 @@ class BasePathNamespace:
     KLIST = "/usr/bin/klist"
     KTUTIL = "/usr/bin/ktutil"
     BIN_KVNO = "/usr/bin/kvno"
-    LDAPMODIFY = "/usr/bin/ldapmodify"
-    LDAPPASSWD = "/usr/bin/ldappasswd"
+    LDAPMODIFY = "/usr/local/bin/ldapmodify"
+    LDAPPASSWD = "/usr/local/bin/ldappasswd"
     MODUTIL = "/usr/bin/modutil"
     NET = "/usr/bin/net"
     BIN_NISDOMAINNAME = "/usr/bin/nisdomainname"
@@ -283,6 +283,7 @@ class BasePathNamespace:
     PKIDESTROY = "/usr/sbin/pkidestroy"
     PKISPAWN = "/usr/sbin/pkispawn"
     PKI = "/usr/bin/pki"
+    PKI_SERVER = "/usr/sbin/pki-server"
     RESTORECON = "/usr/sbin/restorecon"
     SELINUXENABLED = "/usr/sbin/selinuxenabled"
     SETSEBOOL = "/usr/sbin/setsebool"
@@ -292,16 +293,16 @@ class BasePathNamespace:
     FONTS_DIR = "/usr/share/fonts"
     FONTS_OPENSANS_DIR = "/usr/share/fonts/open-sans"
     FONTS_FONTAWESOME_DIR = "/usr/share/fonts/fontawesome"
-    USR_SHARE_IPA_DIR = "/usr/share/ipa/"
-    USR_SHARE_IPA_CLIENT_DIR = "/usr/share/ipa/client"
-    CA_TOPOLOGY_ULDIF = "/usr/share/ipa/ca-topology.uldif"
-    IPA_HTML_DIR = "/usr/share/ipa/html"
-    CA_CRT = "/usr/share/ipa/html/ca.crt"
-    SCHEMA_COMPAT_ULDIF = "/usr/share/ipa/updates/91-schema_compat.update"
-    SCHEMA_COMPAT_POST_ULDIF = "/usr/share/ipa/schema_compat_post.uldif"
-    SUBID_GENERATORS_ULDIF = "/usr/share/ipa/subid-generators.uldif"
-    IPA_JS_PLUGINS_DIR = "/usr/share/ipa/ui/js/plugins"
-    UPDATES_DIR = "/usr/share/ipa/updates/"
+    USR_SHARE_IPA_DIR = "/usr/local/share/ipa/"
+    USR_SHARE_IPA_CLIENT_DIR = "/usr/local/share/ipa/client"
+    CA_TOPOLOGY_ULDIF = "/usr/local/share/ipa/ca-topology.uldif"
+    IPA_HTML_DIR = "/usr/local/share/ipa/html"
+    CA_CRT = "/usr/local/share/ipa/html/ca.crt"
+    SCHEMA_COMPAT_ULDIF = "/usr/local/share/ipa/updates/91-schema_compat.update"
+    SCHEMA_COMPAT_POST_ULDIF = "/usr/local/share/ipa/schema_compat_post.uldif"
+    SUBID_GENERATORS_ULDIF = "/usr/local/share/ipa/subid-generators.uldif"
+    IPA_JS_PLUGINS_DIR = "/usr/local/share/ipa/ui/js/plugins"
+    UPDATES_DIR = "/usr/local/share/ipa/updates/"
     DICT_WORDS = "/usr/share/dict/words"
     VAR_KERBEROS_KRB5KDC_DIR = "/var/kerberos/krb5kdc/"
     VAR_KRB5KDC_K5_REALM = "/var/kerberos/krb5kdc/.k5."
@@ -408,7 +409,7 @@ class BasePathNamespace:
     IPA_RENEWAL_LOCK = "/run/ipa/renewal.lock"
     SVC_LIST_FILE = "/run/ipa/services.list"
     KRB5CC_SAMBA = "/run/samba/krb5cc_samba"
-    SLAPD_INSTANCE_SOCKET_TEMPLATE = "/run/slapd-%s.socket"
+    SLAPD_INSTANCE_SOCKET_TEMPLATE = "/var/run/slapd-%s.socket"
     ADMIN_CERT_PATH = '/root/.dogtag/pki-tomcat/ca_admin.cert'
     ENTROPY_AVAIL = '/proc/sys/kernel/random/entropy_avail'
     KDCPROXY_CONFIG = '/etc/ipa/kdcproxy/kdcproxy.conf'
@@ -428,7 +429,7 @@ class BasePathNamespace:
     IPA_CUSTODIA_CHECK = "/usr/libexec/ipa/ipa-custodia-check"
     IPA_GETKEYTAB = '/usr/sbin/ipa-getkeytab'
     IPA_MIGRATE_LOG = '/var/log/ipa-migrate.log'
-    EXTERNAL_SCHEMA_DIR = '/usr/share/ipa/schema.d'
+    EXTERNAL_SCHEMA_DIR = '/usr/local/share/ipa/schema.d'
     GSSPROXY_CONF = '/etc/gssproxy/10-ipa.conf'
     KRB5CC_HTTPD = '/tmp/krb5cc-httpd'
     IF_INET6 = '/proc/net/if_inet6'
@@ -442,9 +443,9 @@ class BasePathNamespace:
     DSCTL = '/usr/sbin/dsctl'
     DSCONF = '/usr/sbin/dsconf'
     # DS related constants
-    ETC_DIRSRV = "/etc/dirsrv"
-    DS_KEYTAB = "/etc/dirsrv/ds.keytab"
-    ETC_DIRSRV_SLAPD_INSTANCE_TEMPLATE = "/etc/dirsrv/slapd-%s"
+    ETC_DIRSRV = "/usr/local/etc/dirsrv"
+    DS_KEYTAB = "/usr/local/etc/dirsrv/ds.keytab"
+    ETC_DIRSRV_SLAPD_INSTANCE_TEMPLATE = "/usr/local/etc/dirsrv/slapd-%s"
     USR_LIB_DIRSRV = "/usr/lib/dirsrv"
     USR_LIB_DIRSRV_64 = "/usr/lib64/dirsrv"
     VAR_LIB_DIRSRV_INSTANCE_SCRIPTS_TEMPLATE = "/var/lib/dirsrv/scripts-%s"
@@ -453,7 +454,7 @@ class BasePathNamespace:
     SLAPD_INSTANCE_DB_DIR_TEMPLATE = "/var/lib/dirsrv/slapd-%s/db/%s"
     SLAPD_INSTANCE_LDIF_DIR_TEMPLATE = "/var/lib/dirsrv/slapd-%s/ldif"
     DIRSRV_LOCK_DIR = "/run/lock/dirsrv"
-    ALL_SLAPD_INSTANCE_SOCKETS = "/run/slapd-*.socket"
+    ALL_SLAPD_INSTANCE_SOCKETS = "/var/run/slapd-*.socket"
     VAR_LOG_DIRSRV_INSTANCE_TEMPLATE = "/var/log/dirsrv/slapd-%s"
     VAR_LOG_DIRSRV = "/var/log/dirsrv/"
     SLAPD_INSTANCE_ACCESS_LOG_TEMPLATE = "/var/log/dirsrv/slapd-%s/access"
