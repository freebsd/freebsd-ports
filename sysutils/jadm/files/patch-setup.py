--- setup.py.orig	2014-09-14 17:02:59.000000000 +0800
+++ setup.py	2014-09-15 10:21:15.776638606 +0800
@@ -37,5 +37,5 @@ setup(
 )
 
 # man page install
-if sys.argv[1] == "install":
-   os.system('cp ./man8/jadm.8 /usr/local/man/man8/jadm.8')
+#if sys.argv[1] == "install":
+   #os.system('cp ./man8/jadm.8 /usr/local/man/man8/jadm.8')
