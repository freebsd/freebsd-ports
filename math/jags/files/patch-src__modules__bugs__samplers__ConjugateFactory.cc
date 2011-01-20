--- src/modules/bugs/samplers/ConjugateFactory.cc.orig	2011-01-20 05:12:21.000000000 -0500
+++ src/modules/bugs/samplers/ConjugateFactory.cc	2011-01-20 05:12:46.000000000 -0500
@@ -120,7 +120,7 @@
 		method = new ConjugateBeta(gv);
 	    }
 	    else {
-		logic_error("Cannot find conjugate sampler for uniform");
+		throw logic_error("Cannot find conjugate sampler for uniform");
 	    }
 	    break;
 	default:
