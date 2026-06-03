--- vendor/gitlab.com/gitlab-org/rust/gitlab-code-parser/bindings/go/chunker/chunker.go.orig	2025-10-25 07:41:10 UTC
+++ vendor/gitlab.com/gitlab-org/rust/gitlab-code-parser/bindings/go/chunker/chunker.go
@@ -2,7 +2,7 @@ package chunker
 
 /*
 #include <stdint.h>
-#include "parser-c-bindings.h"
+#include <parser-c-bindings.h>
 
 extern int goChunkerYieldFunc(CChunk*, void*);
 */
