--- libbeat/autodiscover/providers/docker/docker.go.orig	2022-10-24 06:49:31 UTC
+++ libbeat/autodiscover/providers/docker/docker.go
@@ -15,8 +15,8 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
-// +build linux darwin windows
+//go:build linux || darwin || windows || freebsd
+// +build linux darwin windows freebsd
 
 package docker
 
@@ -33,7 +33,7 @@ import (
 	"github.com/elastic/beats/v7/libbeat/common"
 
 	"github.com/elastic/elastic-agent-autodiscover/bus"
-	"github.com/elastic/elastic-agent-autodiscover/docker"
+	docker "github.com/elastic/elastic-agent-autodiscover/docker"
 	"github.com/elastic/elastic-agent-autodiscover/utils"
 	"github.com/elastic/elastic-agent-libs/config"
 	"github.com/elastic/elastic-agent-libs/keystore"
