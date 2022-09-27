--- src/libdar/parallel_tronconneuse.cpp.orig	2022-04-13 16:16:59 UTC
+++ src/libdar/parallel_tronconneuse.cpp
@@ -91,21 +91,21 @@ namespace libdar
 	{
 	    U_I tmp_bs1, tmp_bs2;

-	    scatter = make_shared<ratelier_scatter<crypto_segment> >(get_ratelier_size(num_workers));
+	    scatter.reset(new (nothrow) ratelier_scatter<crypto_segment>(get_ratelier_size(num_workers)));
 	    if(!scatter)
 		throw Ememory("parallel_tronconneuse::parallel_tronconneuse");

-	    gather = make_shared<ratelier_gather<crypto_segment> >(get_ratelier_size(num_workers));
+	    gather.reset(new (nothrow) ratelier_gather<crypto_segment>(get_ratelier_size(num_workers)));
 	    if(!gather)
 		throw Ememory("parallel_tronconneuse::parallel_tronconneuse");

-	    waiter = make_shared<barrier>(num_workers + 2); // +1 for crypto_reade thread, +1 this thread
+	    waiter.reset(new (nothrow) barrier(num_workers + 2));
 	    if(!waiter)
 		throw Ememory("parallel_tronconneuse::parallel_tronconneuse");

 		// tas is created empty

-	    tas = make_shared<heap<crypto_segment> >();
+	    tas.reset(new (nothrow) heap<crypto_segment>());
 	    if(!tas)
 		throw Ememory("parallel_tronconneuse::parallel_tronconneuse");

