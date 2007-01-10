--- fea/pa_backend_ipfw2.cc.orig	Wed Jan 10 20:08:58 2007
+++ fea/pa_backend_ipfw2.cc	Wed Jan 10 20:18:04 2007
@@ -329,7 +329,7 @@
     cmds |= (CMD_MOVE_RULESET << 24);
     cmds |= ((dst_index << 16) & 0xFF);
     cmds |= src_index & 0xFFFF;
-    return (docmd4(IP_FW_DEL, (void*)cmds, sizeof(cmds)));
+    return (docmd4(IP_FW_DEL, (void*)(uintptr_t)cmds, sizeof(cmds)));
 }
 
 // Swap the contents of the two rulesets.
@@ -344,7 +344,7 @@
     cmds |= (CMD_SWAP_RULESETS << 24);
     cmds |= ((first_index << 16) & 0xFF);
     cmds |= second_index & 0xFFFF;
-    return (docmd4(IP_FW_DEL, (void*)cmds, sizeof(cmds)));
+    return (docmd4(IP_FW_DEL, (void*)(uintptr_t)cmds, sizeof(cmds)));
 }
 
 // Flush the contents of a given ruleset.
@@ -355,7 +355,7 @@
     uint32_t cmds = 0;
     cmds |= (CMD_DEL_RULES_WITH_SET << 24);
     cmds |= index & 0xFFFF;
-    return (docmd4(IP_FW_DEL, (void*)cmds, sizeof(cmds)));
+    return (docmd4(IP_FW_DEL, (void*)(uintptr_t)cmds, sizeof(cmds)));
 }
 
 // Micro-assemble an IPFW2 instruction sequence for the specified
