--- powerpc64/machine.m4.old	2021-04-18 10:51:29.072176000 -0500
+++ powerpc64/machine.m4	2021-04-18 11:45:30.583315000 -0500
@@ -1,26 +1,15 @@
 define(`PROLOGUE',
 `.globl C_NAME($1)
 DECLARE_FUNC(C_NAME($1))
-ifelse(WORDS_BIGENDIAN,no,
-`ifdef(`FUNC_ALIGN',`.align FUNC_ALIGN')
+ifdef(`FUNC_ALIGN',`.align FUNC_ALIGN')
 C_NAME($1):
 addis 2,12,(.TOC.-C_NAME($1))@ha
 addi 2,2,(.TOC.-C_NAME($1))@l
-.localentry C_NAME($1), .-C_NAME($1)',
-`.section ".opd","aw"
-.align 3
-C_NAME($1):
-.quad .C_NAME($1),.TOC.@tocbase,0
-.previous
-ifdef(`FUNC_ALIGN',`.align FUNC_ALIGN')
-.C_NAME($1):')
+.localentry C_NAME($1), .-C_NAME($1)
 undefine(`FUNC_ALIGN')')
 
 define(`EPILOGUE',
-`ifelse(WORDS_BIGENDIAN,no,
-`.size C_NAME($1), . - C_NAME($1)',
-`.size .C_NAME($1), . - .C_NAME($1)
-.size C_NAME($1), . - .C_NAME($1)')')
+`.size C_NAME($1), . - C_NAME($1)')
 
 C Get vector-scalar register from vector register
 C VSR(VR)
