--- notus/scanner/config.py	2022-07-31 23:42:08.386733000 -0500
+++ notus/scanner/config.py	2022-07-31 23:43:46.513394000 -0500
@@ -35,7 +35,7 @@
 DEFAULT_LOG_LEVEL = "INFO"
 DEFAULT_MQTT_BROKER_ADDRESS = "localhost"
 DEFAULT_MQTT_BROKER_PORT = 1883
-DEFAULT_PID_FILE = "/run/notus-scanner/notus-scanner.pid"
+DEFAULT_PID_FILE = "/var/run/notus-scanner/notus-scanner.pid"
 
 _CONFIG = (
     (
