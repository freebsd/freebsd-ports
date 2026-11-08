--- libbeat/autodiscover/providers/docker/docker.go.orig	2026-08-26 15:33:57 UTC
+++ libbeat/autodiscover/providers/docker/docker.go
@@ -15,7 +15,7 @@
 // specific language governing permissions and limitations
 // under the License.
 
-//go:build linux || darwin || windows
+//go:build linux || darwin || windows || freebsd
 
 package docker
 
@@ -33,7 +33,7 @@ import (
 	"github.com/elastic/beats/v7/libbeat/common"
 
 	"github.com/elastic/beats/v7/pkg/autodiscover/bus"
-	"github.com/elastic/beats/v7/pkg/autodiscover/docker"
+	docker "github.com/elastic/beats/v7/pkg/autodiscover/docker"
 	"github.com/elastic/beats/v7/pkg/autodiscover/utils"
 	"github.com/elastic/elastic-agent-libs/config"
 	"github.com/elastic/elastic-agent-libs/keystore"
