--- plugins/magma/src/components/adversaries/DetailsTable.vue	2024-02-16 18:25:56.033533000 -0500
+++ plugins/magma/src/components/adversaries/DetailsTable.vue	2024-02-16 18:26:25.865321000 -0500
@@ -395,6 +395,7 @@
                     span.icon.is-small.mr-2
                         font-awesome-icon(v-if="platform.includes('windows')" icon="fab fa-windows")
                         font-awesome-icon(v-if="platform.includes('darwin')" icon="fab fa-apple")
+                        font-awesome-icon(v-if="platform.includes('freebsd')" icon="fab fa-freebsd")
                         font-awesome-icon(v-if="platform.includes('linux')" icon="fab fa-linux")
             td.has-text-centered(:class="{ 'unlock': onHoverUnlocks.indexOf(ability.ability_id) > -1 }")
                 span(v-if="abilityDependencies[ability.ability_id] && getExecutorDetail('requirements', ability)" v-tooltip="`This ability has requirements: (${abilityDependencies[ability.ability_id].requireTypes})`")
