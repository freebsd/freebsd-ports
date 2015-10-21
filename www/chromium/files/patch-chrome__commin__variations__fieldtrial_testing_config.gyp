--- chrome/common/variations/fieldtrial_testing_config.gyp.orig	2015-10-14 23:35:23.943296000 +0200
+++ chrome/common/variations/fieldtrial_testing_config.gyp	2015-10-14 23:36:22.584477000 +0200
@@ -19,7 +19,7 @@
       'conditions': [
         ['OS!="android"', {'sources/': [['exclude', '_android\\.json$']]}],
         ['OS!="win"', {'sources/': [['exclude', '_win\\.json$']]}],
-        ['OS!="linux" or chromeos==1', {'sources/': [['exclude', '_linux\\.json$']]}],
+        ['(OS!="linux" and OS!="freebsd") or chromeos==1', {'sources/': [['exclude', '_linux\\.json$']]}],
         ['OS!="mac"', {'sources/': [['exclude', '_mac\\.json$']]}],
         ['chromeos!=1', {'sources/': [['exclude', '_chromeos\\.json$']]}],
         ['OS!="ios"', {'sources/': [['exclude', '_ios\\.json$']]}],
