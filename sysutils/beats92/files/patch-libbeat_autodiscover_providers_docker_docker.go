--- libbeat/autodiscover/providers/docker/docker.go.orig	2026-02-23 21:59:03 UTC
+++ libbeat/autodiscover/providers/docker/docker.go
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
+//go:build linux || darwin || windows || freebsd
 
 package docker
 
@@ -32,7 +32,7 @@ import (
 	"github.com/elastic/beats/v7/libbeat/common"
 
 	"github.com/elastic/elastic-agent-autodiscover/bus"
-	"github.com/elastic/elastic-agent-autodiscover/docker"
+	docker "github.com/elastic/elastic-agent-autodiscover/docker"
 	"github.com/elastic/elastic-agent-autodiscover/utils"
 	"github.com/elastic/elastic-agent-libs/config"
 	"github.com/elastic/elastic-agent-libs/keystore"
