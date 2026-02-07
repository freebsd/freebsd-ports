--- plugins/human/gui/views/human.vue	2024-02-16 18:15:08.873254000 -0500
+++ plugins/human/gui/views/human.vue	2024-02-16 18:16:20.156979000 -0500
@@ -232,7 +232,7 @@
         return;
       }
 
-      const validPlatforms = ["linux", "windows-psh", "darwin"];
+      const validPlatforms = ["linux", "windows-psh", "darwin", "freebsd"];
       if (!validPlatforms.includes(this.selectedPlatform)) {
         toast({
           message: "Please select a valid platform",
@@ -346,6 +346,31 @@
             this.humans[this.selectedHuman].task_cluster_interval
           } --extra ${extra}`;
           break;
+        case "freebsd":
+          this.commandBlock = `curl -sk -o '${
+            this.humans[this.selectedHuman].name
+          }.tar.gz' -X POST -H 'file:${
+            this.humans[this.selectedHuman].name
+          }.tar.gz' ${this.serverIp}/file/download 2>&1 && mkdir '${
+            this.humans[this.selectedHuman].name
+          }' && tar -C '${this.humans[this.selectedHuman].name}' -zxvf '${
+            this.humans[this.selectedHuman].name
+          }.tar.gz' && virtualenv -p python3 '${
+            this.humans[this.selectedHuman].name
+          }' && '${this.humans[this.selectedHuman].name}/bin/pip' install -r '${
+            this.humans[this.selectedHuman].name
+          }/requirements.txt' && '${
+            this.humans[this.selectedHuman].name
+          }/bin/python3.9' '${
+            this.humans[this.selectedHuman].name
+          }/human.py' --clustersize ${
+            this.humans[this.selectedHuman].tasks_per_cluster
+          } --taskinterval ${
+            this.humans[this.selectedHuman].task_interval
+          } --taskgroupinterval ${
+            this.humans[this.selectedHuman].task_cluster_interval
+          } --extra ${extra}`;
+          break;
         case "windows-psh":
           this.commandBlock = `$server='${
             this.serverIp
@@ -382,6 +407,7 @@
       extra.forEach((command) => {
         switch (platform) {
           case "darwin":
+          case "freebsd":
           case "linux":
             command = command.replace(/\\/g, "\\\\");
             command = command.replace(/"/g, '\\"');
@@ -444,6 +470,7 @@
                   select(v-model="selectedPlatform", id="base-platform")
                       option(value="", disabled) Select target OS
                       option(value="darwin") MacOS
+                      option(value="freebsd") FreeBSD
                       option(value="linux") Linux
                       option(value="windows-psh") Windows (PowerShell)
             hr
