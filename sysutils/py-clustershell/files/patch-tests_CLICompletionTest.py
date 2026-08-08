--- tests/CLICompletionTest.py.orig	2026-08-07 00:59:44 UTC
+++ tests/CLICompletionTest.py
@@ -53,7 +53,7 @@ COMPREPLY=()
 '''
 
 # Stub cluset printing fixed nodes/groups; shadows the real one via PATH.
-_CLUSET_STUB = r'''#!/bin/bash
+_CLUSET_STUB = r'''#!/bin/sh
 case "$1" in
 --completion)
     printf '%s\n' @stubsrc: @gpu
