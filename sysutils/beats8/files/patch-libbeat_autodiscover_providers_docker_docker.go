--- libbeat/autodiscover/providers/docker/docker.go.orig	2024-07-09 00:00:36.000000000 +0200
+++ libbeat/autodiscover/providers/docker/docker.go	2024-07-13 21:40:25.908849000 +0200
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
+//go:build linux || darwin || windows || freebsd
 
 package docker
 
@@ -32,7 +32,7 @@
 	"github.com/elastic/beats/v7/libbeat/common"
 
 	"github.com/elastic/elastic-agent-autodiscover/bus"
-	"github.com/elastic/elastic-agent-autodiscover/docker"
+	docker "github.com/elastic/elastic-agent-autodiscover/docker"
 	"github.com/elastic/elastic-agent-autodiscover/utils"
 	"github.com/elastic/elastic-agent-libs/config"
 	"github.com/elastic/elastic-agent-libs/keystore"
