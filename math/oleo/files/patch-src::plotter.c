--- src/plotter.c.orig	Wed Jan 19 18:27:00 2005
+++ src/plotter.c	Wed Jan 19 18:27:27 2005
@@ -2639,7 +2639,7 @@
 	case SP_PLOT_PIE:
 		sp_pie_plot_point(mg, point);
 		break;
-	default:
+	default: {}
 		/* ?? */
 	}
 }
@@ -2770,7 +2770,7 @@
 	case SP_PLOT_PIE:
 		sp_pie_begin_graph(mg, scale, trans_x, trans_y);
 		break;
-	default:
+	default: {}
 		/* ??? */
 	}
 
@@ -2790,7 +2790,7 @@
 	case SP_PLOT_PIE:
 		sp_pie_end_graph(mg);
 		break;
-	default:
+	default: {}
 		/* ??? */
 	}
 }
