--- public/components/all/package.go.orig
+++ public/components/all/package.go
@@ -15,16 +15,4 @@
 import (
 	// Import all community components.
 	_ "github.com/redpanda-data/connect/v4/public/components/community"
-
-	// Import all enterprise components.
-	_ "github.com/redpanda-data/connect/v4/public/components/gateway"
-	_ "github.com/redpanda-data/connect/v4/public/components/gcp/enterprise"
-	_ "github.com/redpanda-data/connect/v4/public/components/google"
-	_ "github.com/redpanda-data/connect/v4/public/components/kafka/enterprise"
-	_ "github.com/redpanda-data/connect/v4/public/components/mongodb/enterprise"
-	_ "github.com/redpanda-data/connect/v4/public/components/mysql"
-	_ "github.com/redpanda-data/connect/v4/public/components/postgresql"
-	_ "github.com/redpanda-data/connect/v4/public/components/slack"
-	_ "github.com/redpanda-data/connect/v4/public/components/snowflake"
-	_ "github.com/redpanda-data/connect/v4/public/components/splunk"
 )
