--- source/compiler/asltypes.h.orig	2017-02-25 00:43:54 UTC
+++ source/compiler/asltypes.h
@@ -344,12 +344,11 @@ typedef struct asl_xref_info
 } ASL_XREF_INFO;
 
 
-typedef struct yy_buffer_state *YY_BUFFER_STATE;
 typedef struct asl_file_node
 {
     FILE                    *File;
     UINT32                  CurrentLineNumber;
-    YY_BUFFER_STATE         State;
+    void                    *State;
     char                    *Filename;
     struct asl_file_node    *Next;
 
