--- ntpclients/ntpviz.py.original	2022-02-14 19:02:54.755920000 +0100
+++ ntpclients/ntpviz.py	2022-02-14 19:03:27.065022000 +0100
@@ -1620,6 +1620,7 @@
             sys.stderr.write("ntpviz: INFO: now running at nice: %s\n" % nice)
 
     for fontpath in ("@PREFIX@/share/fonts/liberation",
+                     "@PREFIX@/share/fonts/Liberation",
                      "@PREFIX@/share/fonts/liberation-fonts",
                      "@PREFIX@/share/fonts/truetype/liberation",
                      "/usr/share/fonts/liberation",
