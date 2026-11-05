--- qa/no-bootstrap-tests/src/test/java/org/elasticsearch/bootstrap/SpawnerNoBootstrapTests.java.orig	2026-10-28 20:24:18 UTC
+++ qa/no-bootstrap-tests/src/test/java/org/elasticsearch/bootstrap/SpawnerNoBootstrapTests.java
@@ -53,7 +53,7 @@ public class SpawnerNoBootstrapTests extends LuceneTes
 public class SpawnerNoBootstrapTests extends LuceneTestCase {
 
     private static final String CONTROLLER_SOURCE = """
-        #!/bin/bash
+        #!/usr/bin/env bash
 
         echo I am alive
         echo "I am an error" >&2
