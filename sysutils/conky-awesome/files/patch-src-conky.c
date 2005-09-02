--- src/conky.c.orig	Fri Sep  2 21:55:33 2005
+++ src/conky.c	Fri Sep  2 21:54:07 2005
@@ -846,7 +846,7 @@
 	OBJ_upspeedgraph,
 	OBJ_uptime,
 	OBJ_uptime_short,
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(i386) || defined(__i386__)
 	OBJ_apm_adapter,
 	OBJ_apm_battery_time,
 	OBJ_apm_battery_life,
@@ -1688,8 +1688,8 @@
 	}
 	END OBJ(uptime_short, INFO_UPTIME) END OBJ(uptime, INFO_UPTIME) END
 	    OBJ(adt746xcpu, 0) END OBJ(adt746xfan, 0) END
-#ifdef __FreeBSD__
-	OBJ(apm_adapter, 0) END
+#if defined(__FreeBSD__) || defined(i386) || defined(__i386__)
+        OBJ(apm_adapter, 0) END
 	OBJ(apm_battery_life, 0) END
 	OBJ(apm_battery_time, 0) END
 #endif /* __FreeBSD__ */
@@ -2715,7 +2715,7 @@
 				format_seconds(p, n, (int) cur->uptime);
 			}
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(i386) || defined(__i386__)
 			OBJ(apm_adapter) {
 				snprintf(p, n, "%s", get_apm_adapter());
 			}
