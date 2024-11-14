--- generator/main.go.orig	2018-02-26 16:03:57 UTC
+++ generator/main.go
@@ -21,7 +21,7 @@ func generateConfig(nodes *Node, nameToN
 		log.Fatal("Unable to determine absolute path for output")
 	}
 
-	content, err := ioutil.ReadFile("generator.yml")
+	content, err := ioutil.ReadFile("/usr/local/etc/snmp_exporter/generator.yml")
 	if err != nil {
 		log.Fatalf("Error reading yml config: %s", err)
 	}
@@ -65,7 +65,7 @@ func generateConfig(nodes *Node, nameToN
 
 var (
 	generateCommand    = kingpin.Command("generate", "Generate snmp.yml from generator.yml")
-	outputPath         = generateCommand.Flag("output-path", "Path to to write resulting config file").Default("snmp.yml").Short('o').String()
+	outputPath         = generateCommand.Flag("output-path", "Path to to write resulting config file").Default("/usr/local/etc/snmp_exporter/snmp.yml").Short('o').String()
 	parseErrorsCommand = kingpin.Command("parse_errors", "Debug: Print the parse errors output by NetSNMP")
 	dumpCommand        = kingpin.Command("dump", "Debug: Dump the parsed and prepared MIBs")
 )
