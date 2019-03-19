--- nsd_exporter.go.orig	2018-02-08 23:45:14 UTC
+++ nsd_exporter.go
@@ -5,6 +5,7 @@ package main
 import (
 	"bufio"
 	"flag"
+	"fmt"
 	"log"
 	"net/http"
 	"strconv"
@@ -58,10 +59,20 @@ func (c *NSDCollector) Collect(ch chan<-
 	s := bufio.NewScanner(r)
 	for s.Scan() {
 		line := strings.Split(s.Text(), "=")
-		metricName := line[0]
+		metricName := strings.TrimSpace(line[0])
 		m, ok := c.metrics[metricName]
 		if !ok {
-			log.Println("Unknown Metric ", metricName, ". Skipping.")
+			log.Println("New metric " + metricName + " found. Refreshing.")
+			// Try to update the metrics list
+			err = c.updateMetric(s.Text())
+			if err != nil {
+				log.Println(err.Error())
+			}
+			// Refetch metric
+			m, ok = c.metrics[metricName]
+			if !ok {
+				log.Println("Metric " + metricName + "not configured. Skipping")
+			}
 			continue
 		}
 		value, err := strconv.ParseFloat(line[1], 64)
@@ -84,7 +95,57 @@ func (c *NSDCollector) Collect(ch chan<-
 
 }
 
-func (c *NSDCollector) updateMetricsList() error {
+func (c *NSDCollector) updateMetric(s string) error {
+	// Assume line is in "metric=#" format
+	line := strings.Split(s, "=")
+	metricName := strings.TrimSpace(line[0])
+
+	_, exists := c.metrics[metricName]
+	if !exists {
+		metricConf, ok := metricConfiguration.Metrics[metricName]
+		if ok {
+			promName := nsdToProm.Replace(line[0])
+			c.metrics[metricName] = &promMetric{
+				desc: prometheus.NewDesc(
+					prometheus.BuildFQName(*nsdType, "", promName),
+					metricConf.Help,
+					nil,
+					nil,
+				),
+				valueType: metricConf.Type,
+			}
+		} else { // Try labeled metric
+			for _, v := range metricConfiguration.LabelMetrics {
+				labels := v.Regex.FindStringSubmatch(metricName)
+				if labels != nil {
+					var promName string
+					if v.Name != "" {
+						promName = v.Name
+					} else {
+						promName = nsdToProm.Replace(line[0])
+					}
+					c.metrics[metricName] = &promMetric{
+						desc: prometheus.NewDesc(
+							prometheus.BuildFQName(*nsdType, "", promName),
+							v.Help,
+							v.Labels,
+							nil,
+						),
+						valueType: v.Type,
+						labels:    labels[1:len(labels)],
+					}
+					// python "for-else"
+					goto Found
+				}
+			}
+			return fmt.Errorf("Metric ", metricName, " not found in config.")
+		Found:
+		}
+	}
+	return nil
+}
+
+func (c *NSDCollector) initMetricsList() error {
 	r, err := c.client.Command("stats_noreset")
 	if err != nil {
 		log.Println(err)
@@ -98,49 +159,9 @@ func (c *NSDCollector) updateMetricsList
 	// Grab metrics
 	s := bufio.NewScanner(r)
 	for s.Scan() {
-		// Assume line is in "metric=#" format
-		line := strings.Split(s.Text(), "=")
-		metricName := line[0]
-
-		_, exists := c.metrics[metricName]
-		if !exists {
-			metricConf, ok := metricConfiguration.Metrics[metricName]
-			if ok {
-				promName := nsdToProm.Replace(line[0])
-				c.metrics[metricName] = &promMetric{
-					desc: prometheus.NewDesc(
-						prometheus.BuildFQName(*nsdType, "", promName),
-						metricConf.Help,
-						nil,
-						nil,
-					),
-					valueType: metricConf.Type,
-				}
-			} else { // Try labeled metric
-				for _, v := range metricConfiguration.LabelMetrics {
-					// TODO: Move this to Collect(), to catch any metrics that are created at runtime
-					// Unfortunately prom needs all metrics defined at the beginning
-					labels := v.Regex.FindStringSubmatch(metricName)
-					if labels != nil {
-						var promName string
-						if v.Name != "" {
-							promName = v.Name
-						} else {
-							promName = nsdToProm.Replace(line[0])
-						}
-						c.metrics[metricName] = &promMetric{
-							desc: prometheus.NewDesc(
-								prometheus.BuildFQName(*nsdType, "", promName),
-								v.Help,
-								v.Labels,
-								nil,
-							),
-							valueType: v.Type,
-							labels:    labels[1:len(labels)],
-						}
-					}
-				}
-			}
+		err = c.updateMetric(s.Text())
+		if err != nil {
+			log.Println(err.Error(), "Skipping.")
 		}
 	}
 	return s.Err()
@@ -156,7 +177,7 @@ func NewNSDCollector(nsdType string, hos
 		client: client,
 	}
 
-	err = collector.updateMetricsList()
+	err = collector.initMetricsList()
 	if err != nil {
 		log.Println(err)
 		return nil, err
@@ -174,7 +195,7 @@ func NewNSDCollectorFromConfig(path stri
 		client: client,
 	}
 
-	err = collector.updateMetricsList()
+	err = collector.initMetricsList()
 	if err != nil {
 		log.Println(err)
 		return nil, err
