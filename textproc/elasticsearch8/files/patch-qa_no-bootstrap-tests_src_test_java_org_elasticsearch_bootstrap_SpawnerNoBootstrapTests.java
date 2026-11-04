--- qa/no-bootstrap-tests/src/test/java/org/elasticsearch/bootstrap/SpawnerNoBootstrapTests.java.orig	2026-10-28 21:29:53 UTC
+++ qa/no-bootstrap-tests/src/test/java/org/elasticsearch/bootstrap/SpawnerNoBootstrapTests.java
@@ -54,7 +54,7 @@ public class SpawnerNoBootstrapTests extends LuceneTes
 public class SpawnerNoBootstrapTests extends LuceneTestCase {
 
     private static final String CONTROLLER_SOURCE = """
-        #!/bin/bash
+        #!/usr/bin/env bash
 
         echo I am alive
         echo "I am an error" >&2
