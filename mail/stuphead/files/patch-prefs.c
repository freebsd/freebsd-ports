--- src/prefs.c.bak	Tue Aug 17 14:33:11 2004
+++ src/prefs.c	Tue Aug 17 14:32:13 2004
@@ -157,6 +157,7 @@
                         string_rgb_to_gdk_color((GdkColor *)param[i].data, (gchar *)value);
 			break;
 		default:
+			break;
 		}
 	}
 }
@@ -451,6 +450,7 @@
                                 string_rgb_to_gdk_color((GdkColor *)param[i].data, "#000000");
 			break;
 		default:
+			break;
 		}
 	}
 }
@@ -470,6 +468,7 @@
 			g_free(*((gchar **)param[i].data));
 			break;
 		default:
+			break;
 		}
 	}
 }
@@ -615,6 +612,7 @@
 			tmpparam.data = &enum_data;
 			break;
 		case P_OTHER:
+			break;
 		}
 		tmpparam.widget_set_func(&tmpparam);
 		g_free(str_data);
