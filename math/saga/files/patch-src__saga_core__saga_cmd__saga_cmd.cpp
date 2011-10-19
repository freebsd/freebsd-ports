--- src/saga_core/saga_cmd/saga_cmd.cpp_orig	2011-05-17 15:36:45.000000000 +0200
+++ src/saga_core/saga_cmd/saga_cmd.cpp	2011-10-17 08:25:58.000000000 +0200
@@ -126,7 +126,11 @@
 #endif
 //---------------------------------------------------------
 
+#if wxCHECK_VERSION(2, 8, 11)
+	if( !wxInitialize( argc, argv ) )
+#else
 	if( !wxInitialize() )
+#endif
 	{
 		Print_Error(SG_T("initialisation failed"));
