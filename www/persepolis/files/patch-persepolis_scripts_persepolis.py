--- persepolis/scripts/persepolis.py.orig	2019-09-16 20:45:38 UTC
+++ persepolis/scripts/persepolis.py
@@ -42,9 +42,6 @@ if os_type == 'Linux' or os_type == 'FreeBSD' or os_ty
 
 # initialization
 
-# find home address
-home_address = os.path.expanduser("~")
-
 # persepolis config_folder
 config_folder = determineConfigFolder()
 
@@ -58,10 +55,8 @@ global lock_file_validation
 
 if os_type != 'Windows':
     import fcntl
-    user_name_split = home_address.split('/')
-    user_name = user_name_split[2]
 # persepolis lock file
-    lock_file = '/tmp/persepolis_exec_' + user_name + '.lock'
+    lock_file = '/tmp/persepolis_exec_' + os.getlogin() + '.lock'
 
 # create lock file
     fp = open(lock_file, 'w')
