--- tools/mitre/mitredb.py.orig	2023-05-24 19:23:05 UTC
+++ tools/mitre/mitredb.py
@@ -766,13 +766,6 @@ def main(database=None):
     # Parse enterprise-attack.json file:
     parse_json(pathfile, session, database)
 
-    # User and group permissions
-    os.chmod(database, 0o660)
-    uid = pwd.getpwnam("root").pw_uid
-    gid = grp.getgrnam("wazuh").gr_gid
-    os.chown(database, uid, gid)
-
-
 if __name__ == '__main__':
     parser = argparse.ArgumentParser(description='This script installs mitre.db in a directory.')
     parser.add_argument('--database', '-d', help='-d /your/directory/mitre.db (default: /var/ossec/var/db/mitre.db')
