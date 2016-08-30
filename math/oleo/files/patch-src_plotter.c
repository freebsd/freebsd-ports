--- src/plotter.c.orig	2000-11-22 19:33:01 UTC
+++ src/plotter.c
@@ -2639,7 +2639,7 @@ sp_plot_point(Multigrapher *mg, const Po
 	case SP_PLOT_PIE:
 		sp_pie_plot_point(mg, point);
 		break;
-	default:
+	default: {}
 		/* ?? */
 	}
 }
@@ -2770,7 +2770,7 @@ sp_begin_plot(Multigrapher *mg, double s
 	case SP_PLOT_PIE:
 		sp_pie_begin_graph(mg, scale, trans_x, trans_y);
 		break;
-	default:
+	default: {}
 		/* ??? */
 	}
 
@@ -2790,7 +2790,7 @@ sp_end_plot(Multigrapher *mg)
 	case SP_PLOT_PIE:
 		sp_pie_end_graph(mg);
 		break;
-	default:
+	default: {}
 		/* ??? */
 	}
 }
