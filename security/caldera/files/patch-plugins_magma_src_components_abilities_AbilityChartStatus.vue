--- plugins/magma/src/components/abilities/AbilityChartStatus.vue.orig	2024-02-16 18:23:17.915545000 -0500
+++ plugins/magma/src/components/abilities/AbilityChartStatus.vue	2024-02-16 18:23:59.841718000 -0500
@@ -101,6 +101,13 @@
       itemStyle: { color: "#F7DB89" },
     },
     {
+      name: "freebsd",
+      value: Object.values(abilityStore.abilities).filter(
+        (ability) => getAbilityPlatforms(ability).indexOf("freebsd") >= 0
+      ).length,
+      itemStyle: { color: "#9D2A11" },
+    },
+    {
       name: "darwin",
       value: Object.values(abilityStore.abilities).filter(
         (ability) => getAbilityPlatforms(ability).indexOf("darwin") >= 0
