--- fsom.c.orig	2015-11-21 16:35:06 UTC
+++ fsom.c
@@ -31,6 +31,10 @@
 #define 	M_E		2.7182818284590452354
 #endif
 
+#ifndef		ABS
+#define		ABS(x)		((x) < 0 ? -(x) : (x))
+#endif
+
 /**
  * \brief  Create a new synapsis between two neurons
  * \param  input_neuron 		Input neuron for the synapsis
@@ -591,10 +595,10 @@ som_train_iteration ( som_network_t *net
 	som_neuron_t *neuron;
 	for ( i=0; i < net->output_layer->neurons_rows; ++i )
 	{
-		dist_i = abs( x - i );
+		dist_i = ABS( x - i );
 		for ( j=0; j < net->output_layer->neurons_cols; ++j )
 		{
-			dist     = pow( dist_i + abs ( y - j ), 4 );
+			dist     = pow( dist_i + ABS ( y - j ), 4 );
 			inv_dist = (1.0 / ((double) dist + 1)) * l_rate;
 			neuron   = net->output_layer->neurons[i][j];
 			for ( k=0; k < net->input_layer->neurons_count; ++k )
