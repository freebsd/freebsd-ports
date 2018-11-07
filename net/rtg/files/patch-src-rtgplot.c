--- src/rtgplot.c.orig	2003-10-02 15:27:52 UTC
+++ src/rtgplot.c
@@ -221,7 +221,10 @@ int main(int argc, char **argv) {
 						plot_line(data[i][j], &img, &graph, colors->shade, TRUE);
 					else
 						plot_line(data[i][j], &img, &graph, colors->shade, FALSE);
-					snprintf(intname, sizeof(intname), "%s%d", arguments.table[i], arguments.iid[j]);
+					if (arguments.tablename[i])
+						snprintf(intname, sizeof(intname), "%s", arguments.tablename[i]);
+					else
+						snprintf(intname, sizeof(intname), "%s%d", arguments.table[i], arguments.iid[j]);
 					plot_legend(&img, rate[i][j], &graph, colors->shade, intname, offset);
 					offset++;
 				}
@@ -629,15 +632,15 @@ void plot_legend(gdImagePtr * img, rate_
 	if (set.verbose >= HIGH)
 		fprintf(dfp, "Plotting legend (%s).\n", __FUNCTION__);
 
-	gdImageFilledRectangle(*img, BORDER_L,
+	gdImageFilledRectangle(*img, BORDER_L - 10,
 			     BORDER_T + graph->image.yplot_area + 37 + 10 * offset,
-	BORDER_L + 7, BORDER_T + graph->image.yplot_area + 44 + 10 * offset, color);
-	gdImageRectangle(*img, BORDER_L, BORDER_T + graph->image.yplot_area + 37 + 10 * offset,
-	       BORDER_L + 7, BORDER_T + graph->image.yplot_area + 44 + 10 * offset,
+	BORDER_L - 3, BORDER_T + graph->image.yplot_area + 44 + 10 * offset, color);
+	gdImageRectangle(*img, BORDER_L - 10, BORDER_T + graph->image.yplot_area + 37 + 10 * offset,
+	       BORDER_L - 3, BORDER_T + graph->image.yplot_area + 44 + 10 * offset,
 			 std_colors[black]);
 
-	if (strlen(interface) > 17) {
-		interface[17] = '\0';
+	if (strlen(interface) > 15) {
+		interface[15] = '\0';
 	}
 	snprintf(string, sizeof(string), "%s", interface);
 	for (i = 0; i < (17 - strlen(interface)); i++) {
@@ -662,7 +665,7 @@ void plot_legend(gdImagePtr * img, rate_
 			units(rate.cur, cur), graph->units,
 			units((float)rate.total, total));
 	}
-	gdImageString(*img, gdFontSmall, BORDER_L + 10,
+	gdImageString(*img, gdFontSmall, BORDER_L,
 		      BORDER_T + graph->image.yplot_area + 33 + (10 * offset), string, std_colors[black]);
 }
 
@@ -866,6 +869,13 @@ void plot_labels(gdImagePtr * img, graph
 	title_offset = 1 - (0.01 * (strlen(VERSION) + strlen(COPYRIGHT) + 2));
 	snprintf(string, sizeof(string), "%s %s", COPYRIGHT, VERSION);
 	gdImageString(*img, gdFontSmall, BORDER_L + (graph->image.xplot_area * title_offset), BORDER_T - 15, string, std_colors[black]);
+
+	/* title */
+	if (graph->titlestr)
+	{
+		snprintf(string, sizeof(string), "%s", graph->titlestr);
+		gdImageString(*img, gdFontMediumBold, BORDER_L + 5, BORDER_T - 16, string, std_colors[black]);
+	}
 }
 
 
@@ -1342,10 +1352,14 @@ void parseWeb(arguments_t *arguments, gr
 			}
 		}
 /* XXX REB - Warning: Deprecated, tN argument will go away in RTG 0.8 XXX */
+		snprintf(var, sizeof(var), "title");
+		graph->titlestr = cgiGetValue(cgiArg, var); 
 		for (i = 0; i < MAXTABLES; i++) {
 			snprintf(var, sizeof(var), "t%d", i + 1);
 			if ((arguments->table[i] = cgiGetValue(cgiArg, var)))
 				arguments->tables_to_plot++;
+			snprintf(var, sizeof(var), "t%d_name", i + 1);
+			arguments->tablename[i] = cgiGetValue(cgiArg, var);
 		}
 		if ((graph->units = cgiGetValue(cgiArg, "units")) == NULL) {
 			graph->units = malloc(sizeof(DEFAULT_UNITS));
