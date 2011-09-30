--- setup.py.orig	2006-08-19 11:36:16.000000000 +0400
+++ setup.py	2011-09-29 12:09:15.000000000 +0400
@@ -9,10 +9,14 @@
     lang = lang[3:-3]
     i18n.append(('share/locale/%s/LC_MESSAGES' % lang,
                  ['i18n/%s/LC_MESSAGES/hercules.mo' % lang]))
+i18n.append(('share/hercules/xrc', \
+            ['xrc/calculators.xrc',
+             'xrc/exercisewizard.xrc',
+             'xrc/hercules.xrc']))
 
 setup (name = "hercules",
        fullname = "The Diary Of Hercules",
-       version = "0.0.4",
+       version = "0.1.1",
        description = "Personal workout diary",
        author = "Basil Shubin",
        author_email = "bashu@users.sourceforge.net",
@@ -21,6 +25,6 @@
        keywords = ["Workout software", "Bodybuilding", "Fitness", "wxPython"],
 
        scripts = ["hercules.py"],
-       packages = ["Hercules", "Hercules/gui"],
+       packages = ["Hercules", "Hercules/gui", "Hercules/plugins"],
        data_files = i18n
        )
