--- nsd_exporter.go.orig	2018-02-08 23:45:14 UTC
+++ nsd_exporter.go
@@ -19,7 +19,7 @@ import (
 var listenAddr = flag.String("listen-address", ":8080", "The address to listen on for HTTP requests.")
 var metricPath = flag.String("metric-path", "/metrics", "The path to export Prometheus metrocs to.")
 var metricConfigPath = flag.String("metric-config", "", "Mapping file for metrics. Defaults to built in file for NSD 4.1.x. This allows you to add or change any metrics that this scrapes")
-var nsdConfig = flag.String("config-file", "/etc/nsd/nsd.conf", "Configuration file for nsd/unbound to autodetect configuration from. Defaults to /etc/nsd/nsd.conf. Mutually exclusive with -nsd-address, -cert, -key and -ca")
+var nsdConfig = flag.String("config-file", "/usr/local/etc/nsd/nsd.conf", "Configuration file for nsd/unbound to autodetect configuration from. Defaults to /usr/local/etc/nsd/nsd.conf. Mutually exclusive with -nsd-address, -cert, -key and -ca")
 var nsdType = flag.String("type", "nsd", "What nsd-like daemon to scrape (nsd or unbound). Defaults to nsd")
 var cert = flag.String("cert", "", "Client cert file location. Mutually exclusive with -config-file.")
 var key = flag.String("key", "", "Client key file location. Mutually exclusive with -config-file.")
@@ -58,7 +58,7 @@ func (c *NSDCollector) Collect(ch chan<-
 	s := bufio.NewScanner(r)
 	for s.Scan() {
 		line := strings.Split(s.Text(), "=")
-		metricName := line[0]
+		metricName := strings.TrimSpace(line[0])
 		m, ok := c.metrics[metricName]
 		if !ok {
 			log.Println("Unknown Metric ", metricName, ". Skipping.")
