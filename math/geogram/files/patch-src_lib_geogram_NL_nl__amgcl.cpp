--- src/lib/geogram/NL/nl_amgcl.cpp.orig	2024-06-14 05:04:18 UTC
+++ src/lib/geogram/NL/nl_amgcl.cpp
@@ -183,7 +183,7 @@ NLboolean nlSolveAMGCL() {
 
     // There can be several linear systems to solve in OpenNL
     for(int k=0; k<ctxt->nb_systems; ++k) {
-	
+
 	if(ctxt->no_variables_indirection) {
 	    x = (double*)ctxt->variable_buffer[k].base_address;
 	    geo_assert(
@@ -192,9 +192,11 @@ NLboolean nlSolveAMGCL() {
 	}
 
 	if(ctxt->verbose) {
-	    GEO::Logger::out("AMGCL") << "Calling solver" << std::endl;
+        GEO::Logger::out("AMGCL") << "calling AMGCL solver (built in geogram) "
+				  << "(" << Backend::name() << ")"
+				  << std::endl;
 	}
-	
+
 	// Call the solver and copy used iterations and last
 	// relative residual to OpenNL context.
 	std::tie(ctxt->used_iterations, ctxt->error) = solver(
