--- chrome/common/variations/fieldtrial_testing_config.gyp.orig	2015-10-15 09:32:40.670879000 -0400
+++ chrome/common/variations/fieldtrial_testing_config.gyp	2015-10-15 09:27:09.909117000 -0400
@@ -19,7 +19,7 @@
       'conditions': [
         ['OS!="android"', {'sources/': [['exclude', '_android\\.json$']]}],
         ['OS!="win"', {'sources/': [['exclude', '_win\\.json$']]}],
-        ['OS!="linux" or chromeos==1', {'sources/': [['exclude', '_linux\\.json$']]}],
+        ['(OS!="linux" or chromeos==1) and os_bsd!=1', {'sources/': [['exclude', '_linux\\.json$']]}],
         ['OS!="mac"', {'sources/': [['exclude', '_mac\\.json$']]}],
         ['chromeos!=1', {'sources/': [['exclude', '_chromeos\\.json$']]}],
         ['OS!="ios"', {'sources/': [['exclude', '_ios\\.json$']]}],
