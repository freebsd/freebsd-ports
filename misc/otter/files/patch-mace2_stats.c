--- mace2/stats.c.orig	2003-08-06 14:17:44 UTC
+++ mace2/stats.c
@@ -1,8 +1,8 @@
 #include "Mace2.h"
 
- long MACE_Stats[MACE_MAX_STATS];
- struct MACE_clock MACE_Clocks[MACE_MAX_CLOCKS];
- int Internal_flags[MAX_INTERNAL_FLAGS];
+long MACE_Stats[MACE_MAX_STATS];
+extern struct MACE_clock MACE_Clocks[MACE_MAX_CLOCKS];
+extern int Internal_flags[MAX_INTERNAL_FLAGS];
 
 extern int Domain_size;       /* owned by mace.c */
 extern int Init_wall_seconds; /* owned by mace.c */
