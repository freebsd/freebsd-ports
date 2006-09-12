--- setup.py.orig	Thu May 18 05:36:05 2006
+++ setup.py	Fri Jun  9 06:46:03 2006
@@ -53,12 +53,8 @@
     lang = mofile.split(os.sep)[1]
     directory = os.sep.join(["share", "locale", lang, "LC_MESSAGES"])
     data_files.append((directory, [ mofile ]))
-    
-docdir = "share/doc/pkpgcounter"    
-docfiles = ["README", "COPYING", "BUGS", "CREDITS", "NEWS"]
-data_files.append((docdir, docfiles))
 
-directory = os.sep.join(["share", "man", "man1"])
+directory = os.sep.join(["man", "man1"])
 manpages = glob.glob(os.sep.join(["man", "*.1"]))    
 data_files.append((directory, manpages))
 
