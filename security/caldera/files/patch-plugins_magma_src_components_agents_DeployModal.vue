--- plugins/magma/src/components/agents/DeployModal.vue.orig	2024-02-16 18:38:55.910370000 -0500
+++ plugins/magma/src/components/agents/DeployModal.vue	2024-02-16 18:38:22.148726000 -0500
@@ -142,6 +142,11 @@
                                 font-awesome-icon(icon="fab fa-apple").fa-2x
                             br
                             span darwin
+                        .has-text-centered.platform(v-if="platforms.includes('freebsd')" :class="{ 'selected': selectedPlatform === 'freebsd' }" @click="changePlatform('freebsd')")
+                            span.icon.is-large
+                                font-awesome-icon(icon="fab fa-freebsd").fa-2x
+                            br
+                            span freebsd
             form.mt-4
                 div(v-for="field in agentFields" :key="field.name")
                     .field.is-horizontal.mb-2
@@ -162,6 +167,7 @@
                         span.icon 
                             font-awesome-icon(v-if="command.platform === 'windows'" icon="fab fa-windows")
                             font-awesome-icon(v-if="command.platform === 'darwin'" icon="fab fa-apple")
+                            font-awesome-icon(v-if="command.platform === 'freebsd'" icon="fab fa-freebsd")
                             font-awesome-icon(v-if="command.platform === 'linux'" icon="fab fa-linux")
                         span {{ command.platform }}
                     span.tag {{ command.executor }}
@@ -180,6 +186,7 @@
                             span.icon 
                                 font-awesome-icon(v-if="command.platform === 'windows'" icon="fab fa-windows")
                                 font-awesome-icon(v-if="command.platform === 'darwin'" icon="fab fa-apple")
+                                font-awesome-icon(v-if="command.platform === 'freebsd'" icon="fab fa-freebsd")
                                 font-awesome-icon(v-if="command.platform === 'linux'" icon="fab fa-linux")
                             span {{ command.platform }}
                         span.tag {{ command.executor }}
