--- packages/gtk2/src/gtk+/gtk/gtkfilesystem.inc	2009-01-20 15:43:50.000000000 -0500
+++ packages/gtk2/src/gtk+/gtk/gtkfilesystem.inc	2009-01-20 15:48:04.000000000 -0500
@@ -115,17 +115,14 @@
 
 {$IFDEF read_interface_rest}
 
+{$ifdef HasGTK_FileSystem}
 
 { GError enumeration for GtkFileSystem  }
 
 function GTK_FILE_SYSTEM_ERROR : TGQuark;
 
-
-
 function gtk_file_system_error_quark:TGQuark;cdecl;external gtklib name 'gtk_file_system_error_quark';
 
-
-
 { Boxed-type for gtk_file_folder_get_info() results  }
 
 function GTK_TYPE_FILE_INFO : GType;
@@ -244,11 +241,16 @@
 { GtkFileSystem modules support  }
 
 function _gtk_file_system_create(file_system_name:Pchar):PGtkFileSystem;cdecl;external gtklib name '_gtk_file_system_create';
+
+{$endif HasGTK_FileSystem}
+
 {$endif}  {read_interface_rest}
 
 
 {$ifdef read_implementation}
 
+{$ifdef HasGTK_FileSystem}
+
 function GTK_FILE_SYSTEM_ERROR : TGQuark;
   begin
      GTK_FILE_SYSTEM_ERROR:=gtk_file_system_error_quark;
@@ -301,12 +303,13 @@
 end;
 
 
-
 function GTK_FILE_FOLDER_GET_IFACE(inst : pointer) : PGtkFileSystemIface;
 begin
    GTK_FILE_FOLDER_GET_IFACE:=G_TYPE_INSTANCE_GET_INTERFACE(inst,GTK_TYPE_FILE_FOLDER);
 end;
 
+{$endif HasGTK_FileSystem}
+
 function gtk_file_path_new_dup(str : Pgchar) : PGtkFilePath;
 begin
    gtk_file_path_new_dup:=PGtkFilePath(g_strdup(str));
