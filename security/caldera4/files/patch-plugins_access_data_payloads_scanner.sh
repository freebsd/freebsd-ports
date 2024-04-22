--- plugins/access/data/payloads/scanner.sh.orig	2021-10-01 14:07:40 UTC
+++ plugins/access/data/payloads/scanner.sh
@@ -1,5 +1,5 @@
-#!/bin/bash
+#!/bin/sh
 
 echo '[+] Starting basic NMAP scan'
 nmap -Pn $1
-echo '[+] Complete with module'
\ No newline at end of file
+echo '[+] Complete with module'
